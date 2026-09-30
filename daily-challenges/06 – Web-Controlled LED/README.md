
# 06 - Web-Controlled LED

An ESP32-based IoT project that allows users to remotely control an LED through a web interface hosted directly on the ESP32.

## 📌 Problem Statement

Host a simple web page on the ESP32 with an ON/OFF button that controls an LED remotely.

## 🎯 Objective

To develop a basic IoT application using ESP32 and WiFi connectivity, enabling remote LED control through a browser-based interface.

## 🛠️ Components Used

- ESP32 Development Board
- LED
- Resistor (if using an external LED)
- WiFi Network
- Wokwi ESP32 Simulator

## ⚙️ Working Principle

1. The ESP32 connects to a WiFi network.
2. It starts a web server and hosts a simple HTML webpage.
3. The webpage provides ON and OFF buttons for controlling the LED.
4. When a user clicks a button, an HTTP request is sent to the ESP32.
5. The ESP32 processes the request and updates the LED state.
6. The LED turns ON or OFF according to the selected command.

## 💻 Technologies Used

- ESP32
- Arduino C++
- WiFi Communication
- HTTP Web Server
- HTML
- Wokwi Simulator

## 🔗 Wokwi Simulation

[View Web-Controlled LED Simulation](https://wokwi.com/projects/476558810764090369)

## 📂 Project Structure

```text
06-web-controlled-led/
│
├── README.md
└── web_controlled_led.ino
```

## 🚀 Learning Outcomes

- Understanding ESP32 WiFi connectivity.
- Hosting a web server on an ESP32.
- Understanding HTTP request handling.
- Creating a simple HTML-based control interface.
- Implementing remote hardware control using IoT concepts.

---

Part of the **AUTOMATRIX: Automation, Robotics & Intelligent Systems – SIG 03** Build-a-thon.

**Challenge 06 / 15 – Web-Controlled LED**
