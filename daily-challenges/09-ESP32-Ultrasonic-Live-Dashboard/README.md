# Day 09 – ESP32 Ultrasonic Live Dashboard

## Project Overview

This project demonstrates interfacing an HC-SR04 ultrasonic distance sensor with an ESP32 and displaying the live distance measurement on a web dashboard hosted directly by the ESP32.

The ESP32 measures the distance using the ultrasonic sensor and creates a simple web page that automatically refreshes to show the latest distance reading.

## Objective

- Interface an HC-SR04 ultrasonic sensor with ESP32.
- Measure the distance of an object.
- Connect the ESP32 to a Wi-Fi network.
- Create a web server using the ESP32.
- Display live distance measurements on a web page.
- Automatically refresh the dashboard to show updated readings.

## Components Required

- ESP32 Development Board
- HC-SR04 Ultrasonic Distance Sensor
- Jumper Wires
- Wokwi Simulator

## Circuit Connections

### HC-SR04 Ultrasonic Sensor

| HC-SR04 Pin | ESP32 Pin |
|---|---|
| VCC | 5V |
| GND | GND |
| TRIG | GPIO 5 |
| ECHO | GPIO 18 |

*Note: Check the actual Wokwi circuit for the exact GPIO configuration.*

## Working Principle

1. The ESP32 connects to the Wi-Fi network.
2. The HC-SR04 sensor sends an ultrasonic pulse using the TRIG pin.
3. The ECHO pin receives the reflected ultrasonic signal.
4. The ESP32 calculates the distance based on the time taken for the echo to return.
5. The ESP32 hosts a web server.
6. The measured distance is displayed on the web dashboard.
7. The web page automatically refreshes to display the latest distance.

## Distance Measurement

The distance is calculated using the time taken by the ultrasonic pulse to travel to the object and return.

```text
Distance = (Echo Time × Speed of Sound) / 2
