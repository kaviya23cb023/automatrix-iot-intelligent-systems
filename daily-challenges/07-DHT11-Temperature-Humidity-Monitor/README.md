# Day 07 – DHT11 Temperature and Humidity Readout

## Project Overview

This project demonstrates interfacing a DHT11 temperature and humidity sensor with an ESP32 microcontroller using Wokwi simulation.

The sensor measures the surrounding temperature and relative humidity, and the ESP32 displays the readings on the Serial Monitor every 2 seconds.

## Objective

* Interface a DHT11 sensor with ESP32.
* Read temperature in Celsius.
* Measure relative humidity in percentage.
* Display sensor readings through the Serial Monitor.
* Update readings at 2-second intervals.

## Components Required

* ESP32 Development Board
* DHT11 Temperature and Humidity Sensor
* Jumper Wires
* Wokwi Simulator

## Circuit Connections

| DHT11 Pin | ESP32 Pin |
| --------- | --------- |
| VCC       | 3.3V      |
| GND       | GND       |
| DATA      | GPIO 15   |

*Note: Update the GPIO number if your Wokwi circuit uses a different pin.*

## Working Principle

1. The ESP32 initializes the DHT11 sensor.
2. The sensor measures the surrounding temperature and humidity.
3. The ESP32 reads the sensor values.
4. The readings are displayed on the Serial Monitor.
5. The process repeats every 2 seconds.

## Sample Output

```text
DHT11 Sensor Readings
Temperature: 28.00 °C
Humidity: 65.00 %

Temperature: 28.00 °C
Humidity: 64.00 %
```

*Sample output for illustration. Actual values depend on the simulated sensor conditions.*

## Wokwi Simulation

[View Day 07 – DHT11 Readout Simulation](https://wokwi.com/projects/476651364303678465)

## Learning Outcomes

* ESP32 GPIO interfacing
* Temperature and humidity sensing
* Using sensor libraries in Arduino IDE
* Serial communication and monitoring
* Periodic sensor data acquisition

## Challenge

Build-A-Thon – 15 Daily Challenges
AUTOMATRIX: Automation, Robotics & Intelligent Systems – SIG 03

**Day 07: DHT11 Readout**
