# 🔌 Bluetooth Integrated Power Control

This project, **Bluetooth Integrated Power Control**, is a smart home automation system that enables users to control an electrical switchboard via Bluetooth using a mobile app. The app automatically powers down the switchboard when the phone’s battery reaches a specified level, helping to save energy and prevent overcharging.

## 📋 Table of Contents
- [Project Overview](#project-overview)
- [Project Features](#project-features)
- [How It Works](#how-it-works)
- [Components Required](#components-required)
- [Installation](#installation)
- [How to Use the App](#how-to-use-the-app)
- [Arduino Code](#arduino-code)

---

## 📖 Project Overview

**Bluetooth Integrated Power Control** uses an Arduino, Bluetooth module, and relay to control appliances based on the battery level of the Android device. This project creates a user-friendly IoT solution for optimizing power use and enhancing home automation.

## ✨ Project Features
- **Bluetooth Connectivity**: Wirelessly controls the switchboard via a mobile app.
- **Battery-Based Control**: Turns off the switchboard when the phone reaches 80% battery.
- **Manual Control**: Toggle the switchboard on/off manually from the app.
- **Status Updates**: Provides real-time feedback on the switchboard’s status (ON/OFF).

---

## ⚙️ How It Works

1. **Bluetooth Communication**: The Android app, developed with **MIT App Inventor**, connects to the HC-05 Bluetooth module attached to the Arduino.
2. **Battery Monitoring**: The app monitors the battery level of the connected Android device.
3. **Automatic Switching**: When the battery reaches the set threshold (e.g., 80%), the app sends a command to the Arduino to turn off the relay, powering down the switchboard.
4. **Manual Override**: Users can control the relay manually using the app.

---

## 🔧 Components Required

- **Arduino Uno/Nano** – Microcontroller board.
- **HC-05 Bluetooth Module** – For Bluetooth communication.
- **Relay Module** – To control the electrical switchboard.
- **Android Device** – To install and run the app.
- **Power Supply** – For Arduino and relay.
- **Miscellaneous Components** – Jumper wires, resistors (for voltage divider on Bluetooth RX pin).

---

## 🛠️ Installation

1. **Arduino Setup**:
   - Install the Arduino IDE.
   - Connect the Arduino, HC-05, and relay module as per the wiring guide in the `docs/` folder.
   
2. **Android Application**:
   - Download the APK file from this repository and install it on an Android device.
   - Grant the required permissions for full functionality.

---

## 📲 How to Use the App

1. **Connect to Bluetooth**:
   - Open the app and pair it with the HC-05 module (usually pairs with code **1234** or **0000**).

2. **Automatic Mode**:
   - After pairing, the app monitors the battery level. Once it reaches 80%, the app automatically sends a command to turn off the switchboard.

3. **Manual Mode**:
   - Use the app’s control buttons to manually toggle the switchboard.

---

## 🖥️ Arduino Code

Here’s the code used on the Arduino to receive Bluetooth commands and control the relay.

```cpp
#include "Arduino.h"
#include <SoftwareSerial.h>

const byte rxPin = 9;
const byte txPin = 8;
const byte relayPin = 7;

SoftwareSerial BTSerial(rxPin, txPin);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  BTSerial.begin(9600);
  Serial.begin(9600);
}

int dataByte;

void loop() {
  if (BTSerial.available() > 0) {
    dataByte = BTSerial.read();
    Serial.println(dataByte);

    if (dataByte == 'A') {
      digitalWrite(LED_BUILTIN, HIGH);
      digitalWrite(relayPin, HIGH);
    }
  
    if (dataByte == 'B') {
      digitalWrite(LED_BUILTIN, LOW);
      digitalWrite(relayPin, LOW);
    }
  }
}
```

### **Arduino Connections**

- **HC-05 Bluetooth Module**:
  - **TXD** → Arduino **RX (Pin 9)**
  - **RXD** → Arduino **TX (Pin 8)** (use a 1KΩ and 2KΩ resistor for voltage divider)
  - **VCC** → Arduino **5V**
  - **GND** → Arduino **GND**

- **Relay Module**:
  - **IN** → Arduino **Pin 7**
  - **VCC** → Arduino **5V**
  - **GND** → Arduino **GND**

---

## 🌍 Applications

- **Home Automation**: Remotely control appliances in your home.
- **Power Management**: Efficiently save energy by controlling appliances based on battery level.
- **Overcharge Prevention**: Helps prevent devices from overcharging by managing power usage.
