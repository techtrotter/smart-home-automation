# IoT-Based Smart Home Automation System

This project implements a real-world IoT-based smart home automation solution that allows users to remotely monitor and control home appliances using a microcontroller (ESP8266) over Wi-Fi via MQTT protocol. The system is capable of automating appliances like fans, lights, and air conditioners based on environmental inputs such as temperature and motion.



## Introduction

Home automation is a core application area within the Internet of Things (IoT), where appliances are intelligently controlled to improve convenience, energy efficiency, and security. This project focuses on providing a practical, low-cost home automation setup using microcontrollers and open-source protocols.

The project was developed as a final-year B.Tech project with the aim of automating basic home utilities while remaining extensible and scalable for future smart home ecosystems.

---

## System Overview

This system utilizes an ESP8266 microcontroller (NodeMCU) as the control unit, with peripheral devices such as temperature and motion sensors connected to it. Commands are communicated using the MQTT protocol. A mobile device or computer sends control messages via an MQTT broker, and the microcontroller performs the relevant actions through relay circuits.

---

## Architecture

The architecture includes the following layers:

1. **Perception Layer**: Sensors like DHT11 (temperature) and PIR (motion) detect physical conditions.
2. **Network Layer**: ESP8266 module transmits sensor data and receives control commands using MQTT over Wi-Fi.
3. **Application Layer**: Users interact through MQTT dashboard (e.g., HiveMQ Web Client or mobile app).

---

## Features

- Remote control of home appliances over Wi-Fi
- Automatic switching of devices based on sensor input
- Real-time monitoring of environmental conditions
- MQTT-based communication ensuring light-weight messaging
- Modular design allowing future scalability
- Energy-saving logic (e.g., AC auto switch to economy mode)

---

## Hardware Components

| Component            | Quantity | Description                                           |
|---------------------|----------|-------------------------------------------------------|
| ESP8266 NodeMCU     | 1        | Wi-Fi enabled microcontroller                         |
| Relay Module         | 1-4      | Switches AC devices like lights, fans, etc.           |
| DHT11 Sensor         | 1        | Measures temperature and humidity                     |
| PIR Motion Sensor    | 1        | Detects movement                                      |
| Breadboard & Wires   | -        | Circuit connections                                   |
| Power Supply         | 1        | 5V regulated supply                                   |
| Load Devices         | n        | Lamps, fans, etc.                                     |

---

## Software Components

- Arduino IDE
- PubSubClient library for MQTT
- ESP8266WiFi library
- MQTT Broker (e.g., HiveMQ, Mosquitto)
- MQTT Dashboard (web-based or mobile)

---

## Circuit Diagram

*(Include your circuit diagram as circuit-diagram.png or embed it from external source here)*

Connections:
- DHT11 → Digital Pin D2
- PIR → Digital Pin D5
- Relay IN1 → Digital Pin D1
- Relay IN2 (optional) → Digital Pin D6
- VCC & GND appropriately connected

---

## Working Principle

1. On boot, the ESP8266 connects to the Wi-Fi network and registers with an MQTT broker.
2. The user publishes a command (e.g., "ON" or "OFF") to a specific topic.
3. ESP8266 subscribes to this topic and performs the relevant action through the relay circuit.
4. Additionally, sensors monitor room temperature and motion.
   - For instance, if the room exceeds 28°C, the AC can be automatically switched ON.
   - After 30 minutes, it can switch to Economy mode by default (simulated using timers).
5. Status updates can also be published back to the broker, enabling two-way communication.

---

## Installation & Setup

1. **Install Arduino IDE**
   - Add ESP8266 Board Manager: `http://arduino.esp8266.com/stable/package_esp8266com_index.json`
   - Install libraries: `PubSubClient`, `DHT`, `ESP8266WiFi`

2. **Connect the ESP8266**
   - Connect sensors and relay as per the circuit

3. **Configure the code**
   - Replace Wi-Fi SSID, password, and MQTT broker address in the `.ino` file

4. **Upload Code**
   - Use Arduino IDE to upload `smart_home.ino` to ESP8266

5. **Run MQTT Broker**
   - Use HiveMQ Web Client or install Mosquitto locally/cloud

6. **Control Devices**
   - Publish messages to topics (e.g., `home/room1/light1`) from MQTT client

---

## Use Cases

- Remote control of fan and AC using mobile phone
- Motion-based automation for security lighting
- Temperature-triggered AC control with automatic fallback mode
- Scheduling-based device automation (extendable)

---

## Future Enhancements

- Integration with voice assistants like Alexa or Google Home
- Real-time dashboard and analytics for energy usage
- Multi-room support using ESP-Mesh or MQTT topics
- Feedback-based machine learning to predict usage patterns
- Web interface for rules-based configuration

---

## Author

**Bijoy Laxmi Biswas**  
IoT Developer | Engineer | Passionate about open-source and sustainable tech  
Location: West Bengal, India  
Project Year: 2019 – 2020

---
