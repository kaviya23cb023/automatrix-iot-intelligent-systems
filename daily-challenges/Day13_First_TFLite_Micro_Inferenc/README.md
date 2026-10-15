# ESP32 TFLite Micro Inference

## Overview

This project demonstrates TinyML inference on an ESP32 using TensorFlow Lite for Microcontrollers (TFLite Micro). It explores deploying a lightweight machine learning model on a resource-constrained microcontroller and performing inference locally.

This repository is being used for **Day 13 – First TFLite Micro Inference** of the AUTOMATRIX Build-A-Thon, SIG 03, Department of Computer Science and Business Systems, Ramco Institute of Technology.

## Objective

- Deploy a small TensorFlow Lite model on an ESP32.
- Perform inference using a hardcoded sample input.
- Identify the predicted class from the model output.
- Display the prediction through the Serial Monitor.

## Technologies Used

- ESP32
- TensorFlow Lite for Microcontrollers
- TensorFlow / Keras
- Python
- Arduino IDE / compatible embedded development environment

## Day 13 – First TFLite Micro Inference

### Problem Statement

Deploy a small pretrained or trained `.tflite` model onto the ESP32 using TensorFlow Lite for Microcontrollers. Run inference on a hardcoded sample value and print the predicted class.

### Implementation

The demonstration uses a lightweight light-level classification model with three output classes:

- **Dark**
- **Normal**
- **Bright**

A sample input is supplied directly to the model. The inference runtime processes the input and produces output scores for the three classes. The class with the highest output score is selected as the prediction.

### Workflow

1. Prepare or train a small machine learning model.
2. Convert the model into TensorFlow Lite format.
3. Embed the model in the ESP32 firmware.
4. Initialize the TensorFlow Lite Micro interpreter.
5. Allocate memory for the model's tensors.
6. Supply a hardcoded input value.
7. Execute inference on the ESP32.
8. Print the predicted class on the Serial Monitor.

### Expected Output

For a normalized sample input of `0.20`, the expected classification is `Dark`, provided the trained model produces the expected output.

```text
Day 13: First TFLite Micro Inference
Input value: 0.20
Predicted class: Dark
Inference completed.
```

*Note: This is an illustrative expected output. Actual execution must be verified on the target device.*

## Learning Outcomes

- Understanding TinyML and on-device machine learning.
- Learning the TensorFlow Lite model deployment workflow.
- Understanding input tensors, output tensors, and inference.
- Exploring machine learning on resource-constrained embedded devices.

## Future Enhancements

- Integrate an LDR sensor for real-time light-level readings.
- Display the predicted classification on an OLED.
- Control an LED based on the predicted light level.
- Integrate Wi-Fi connectivity and a live monitoring dashboard.


