# ESP32 TinyML Smart Light Classifier

## Overview

This project demonstrates a Smart Light Classification system using an ESP32 and Tiny Machine Learning (TinyML). It combines sensor-based light monitoring, on-device machine learning inference, and automated lighting control.

The project is aligned with **Day 15 – Mini Integration Project** of the AUTOMATRIX Build-A-Thon, SIG 03, Department of Computer Science and Business Systems, Ramco Institute of Technology.

## Objective

- Monitor ambient light levels using an LDR sensor.
- Classify light conditions as Dark, Normal, or Bright using a TinyML model.
- Run machine learning inference directly on the ESP32.
- Display sensor readings and classification results on an OLED.
- Control an LED automatically based on the predicted light condition.
- Use Wi-Fi connectivity for monitoring and logging results through a web dashboard.

## Technologies Used

- ESP32 microcontroller
- LDR (Light Dependent Resistor)
- OLED display (SSD1306)
- LED
- TensorFlow / TensorFlow Lite
- TensorFlow Lite for Microcontrollers
- Arduino IDE
- Python
- Wi-Fi and web technologies

## Features

- Real-time ambient light monitoring
- On-device TinyML inference
- Three-class light classification
- OLED-based status display
- Automatic LED control
- Wi-Fi connectivity
- Web-based monitoring and result logging

## Working Principle

1. The LDR sensor measures the surrounding light intensity.
2. The ESP32 reads the sensor value and prepares the input for the trained model.
3. The TinyML model classifies the light condition into Dark, Normal, or Bright.
4. The classification result is displayed on the OLED.
5. The ESP32 controls the LED according to the predicted light condition.
6. Wi-Fi connectivity enables monitoring and logging of classification results through a web dashboard.

## System Architecture

**LDR Sensor → ESP32 → TinyML Inference → Light Classification → OLED Display and LED Control → Wi-Fi Web Dashboard**

## Light Classification

| Class | Description | Example action |
|---|---|---|
| Dark | Low ambient light | Turn LED ON |
| Normal | Moderate ambient light | Apply configured lighting behavior |
| Bright | High ambient light | Turn LED OFF |

The exact sensor thresholds and LED behavior depend on the implementation and model configuration.

## Applications

- Smart home lighting
- Energy-efficient lighting systems
- Intelligent indoor lighting
- IoT-based environmental monitoring
- Edge AI and embedded machine learning demonstrations

## Learning Outcomes

- Understanding TinyML deployment on microcontrollers
- Integrating sensors with an ESP32
- Performing on-device machine learning inference
- Interfacing an OLED display
- Implementing automated device control
- Combining Wi-Fi connectivity with embedded intelligence

## Future Enhancements

- Add energy-consumption monitoring.
- Store historical light readings and classification results.
- Improve model accuracy using real-world sensor data.
- Extend the dashboard with graphs and device status indicators.

## Build-A-Thon Details

- **Program:** AUTOMATRIX – Automation, Robotics & Intelligent Systems
- **Challenge:** Day 15 – Mini Integration Project
- **Department:** Computer Science and Business Systems (CSBS)
- **Institution:** Ramco Institute of Technology

## Acknowledgment

This project is documented as part of the AUTOMATRIX Build-A-Thon daily challenges. Refer to the source repository for the original implementation, setup instructions, dependencies, and licensing details.
