# Day 08 – ESP32 LDR Light Sensor with OLED Display

## Project Overview

This project demonstrates interfacing an LDR (Light Dependent Resistor) sensor with an ESP32 and displaying live light-intensity readings on an SSD1306 OLED display.

The LDR senses the surrounding light intensity, and the ESP32 reads the analog sensor value and updates the OLED display continuously.

## Objective

* Interface an LDR sensor with ESP32.
* Read analog light-intensity values.
* Interface an SSD1306 OLED display using I2C communication.
* Display live sensor readings on the OLED screen.
* Understand sensor interfacing and display communication in IoT systems.

## Components Required

* ESP32 Development Board
* LDR (Light Dependent Resistor) Sensor
* SSD1306 OLED Display (128 × 64)
* Jumper Wires
* Wokwi Simulator

## Circuit Connections

### LDR Sensor

| LDR Pin | ESP32 Pin |
| ------- | --------- |
| VCC     | 3.3V      |
| GND     | GND       |
| AO      | GPIO 34   |

### SSD1306 OLED Display

| OLED Pin | ESP32 Pin |
| -------- | --------- |
| VCC      | 3.3V      |
| GND      | GND       |
| SDA      | GPIO 21   |
| SCL      | GPIO 22   |

*Note: These are typical ESP32 connections. Refer to the actual Wokwi circuit for the exact pin configuration.*

## Working Principle

1. The LDR detects the surrounding light intensity.
2. The sensor produces an analog signal corresponding to the light level.
3. The ESP32 reads the analog value using its ADC.
4. The ESP32 sends the sensor reading to the SSD1306 OLED through I2C communication.
5. The OLED display continuously updates the live light sensor reading.

## Output

The OLED display shows:

* Project title
* Live LDR analog reading
* Light intensity value

## Wokwi Simulation

[View Day 08 – LDR and OLED Display Simulation](https://wokwi.com/projects/476652437076126721)

## Learning Outcomes

* ESP32 analog input interfacing
* Understanding LDR sensor operation
* I2C communication
* SSD1306 OLED interfacing
* Real-time sensor data visualization
* IoT sensor monitoring fundamentals

## Challenge

Build-A-Thon – 15 Daily Challenges
AUTOMATRIX: Automation, Robotics & Intelligent Systems – SIG 03

**Day 08: OLED Display**
