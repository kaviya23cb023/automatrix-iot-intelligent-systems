# Problem 03 – Analog Read

## Objective

Read the analog value from a potentiometer using the ESP32 and display the readings on the Serial Monitor every 500 milliseconds.

## Components Required

* ESP32 Development Board
* Potentiometer
* Jumper wires

## Circuit Connections

| Potentiometer Pin   | ESP32 Pin |
| ------------------- | --------- |
| VCC                 | 3.3V      |
| GND                 | GND       |
| Signal (Middle Pin) | GPIO 34   |

## Working Principle

The potentiometer provides a variable analog voltage depending on its knob position. The ESP32 reads this voltage using its ADC (Analog-to-Digital Converter) and converts it into a digital value ranging from 0 to 4095.

The readings are displayed on the Serial Monitor every 500 milliseconds.

## Simulation

[View Analog Read Simulation on Wokwi](https://wokwi.com/projects/476335738004597761)

## Expected Output

The Serial Monitor displays the analog readings continuously. Rotating the potentiometer changes the readings.

## Technologies Used

* ESP32
* Arduino IDE
* Wokwi Simulator
* C++ (Arduino)
