# ESP32 Bluetooth to MQTT Bridge

## Project Overview

This project demonstrates how to use an ESP32 to receive an integer via Bluetooth from a mobile device and then publish that integer to an MQTT server over a Wi-Fi connection. The project is a simple yet effective example of how to bridge Bluetooth communication with MQTT, enabling wireless data transfer from a phone to an MQTT server.

## Features

- **Bluetooth Communication**: The ESP32 acts as a Bluetooth receiver that can be paired with a mobile device. The device sends an integer value to the ESP32.
- **Wi-Fi Connectivity**: The ESP32 connects to a specified Wi-Fi network to gain internet access.
- **MQTT Publishing**: The received integer is published to an MQTT broker on a specified topic.

## Components

- **ESP32 Board**: The microcontroller used to handle Bluetooth and Wi-Fi communication.
- **Mobile Device**: Used to send the integer value via Bluetooth.
- **MQTT Broker**: The server that receives the published integer from the ESP32.

## Prerequisites

- **Arduino IDE**: For programming the ESP32.
- **PubSubClient Library**: For MQTT communication.
- **Bluetooth Terminal App**: For sending integers from your mobile device to the ESP32.

## Setup Instructions

1. **Install Arduino IDE**: Ensure that you have the latest version of Arduino IDE installed. Add the ESP32 board support by following [this guide](https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/).
2. **Install Required Libraries**:

   - Install the `PubSubClient` library via the Arduino Library Manager.

3. **Modify the Code**:

   - Open the provided `esp32_bluetooth_mqtt.ino` file in the Arduino IDE.
   - Replace the placeholders (`your_SSID`, `your_PASSWORD`, `your_MQTT_SERVER`, `your_MQTT_PORT`, `your_TOPIC`) with your actual Wi-Fi credentials and MQTT broker details.

4. **Upload the Code**:

   - Connect the ESP32 board to your computer via USB.
   - Select the correct board and port in Arduino IDE and upload the code.

5. **Bluetooth Pairing**:

   - Pair your mobile device with the ESP32 via Bluetooth. The ESP32 will appear as `ESP32_BT`.
   - Use a Bluetooth terminal app to send an integer to the ESP32.

6. **MQTT Verification**:
   - Ensure that your MQTT broker is running.
   - Verify that the integer received via Bluetooth is published to the specified topic on the MQTT broker.

## How It Works

1. **Initialization**:

   - The ESP32 initializes the Bluetooth service and attempts to connect to the specified Wi-Fi network.

2. **Bluetooth Communication**:

   - Once paired, the ESP32 listens for incoming Bluetooth messages. When an integer is received, it is processed and prepared for publishing.

3. **MQTT Publishing**:
   - The ESP32 checks its connection to the MQTT broker. If connected, the received integer is published to the specified MQTT topic.

## Example Use Case

Imagine you want to remotely control a device or monitor a sensor value using just your mobile phone and a simple Bluetooth connection. This project allows you to do just that by bridging Bluetooth with MQTT, enabling seamless integration into IoT systems.

## License

This project is open-source and available under the MIT License.

## Acknowledgments

Special thanks to the open-source community for providing the tools and libraries that made this project possible.
