# Problem 04 – PWM Fade

## Objective

Control the brightness of an LED using Pulse Width Modulation (PWM), with the brightness proportional to the analog value obtained from a potentiometer.

## Components Required

* ESP32 Development Board
* Potentiometer
* LED
* 220Ω Resistor
* Jumper wires

## Circuit Connections

| Component            | ESP32 Pin                     |
| -------------------- | ----------------------------- |
| Potentiometer VCC    | 3.3V                          |
| Potentiometer GND    | GND                           |
| Potentiometer Signal | GPIO 34                       |
| LED Anode (+)        | GPIO 18 through 220Ω resistor |
| LED Cathode (-)      | GND                           |

## Working Principle

The potentiometer generates an analog input value that is read by the ESP32 ADC.

The analog value (0–4095) is mapped to a PWM duty cycle (0–255). The ESP32 uses PWM to control the LED brightness.

* Lower potentiometer value: LED brightness decreases.
* Higher potentiometer value: LED brightness increases.

## Simulation

[View PWM Fade Simulation on Wokwi](https://wokwi.com/projects/476335798405731329)

## Expected Output

The LED brightness changes smoothly according to the potentiometer position.

## Technologies Used

* ESP32
* Arduino IDE
* Wokwi Simulator
* C++ (Arduino)
* Pulse Width Modulation (PWM)
