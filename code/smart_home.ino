/* IoT Smart Home Automation System
 * Author: Bijoy Laxmi Biswas
 */

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";
const char* mqtt_server = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);
const int relayPin = D1; // Relay connected to D1

void setup_wifi() {
  delay(10);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  if ((char)payload[0] == '1') {
    digitalWrite(relayPin, LOW); // ON
  } else {
    digitalWrite(relayPin, HIGH); // OFF
  }
}

void reconnect() {
  while (!client.connected()) {
    if (client.connect("ESP8266Client")) {
      client.subscribe("home/room1/light1");
    } else {
      delay(5000);
    }
  }
}

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
