# Day 13 – First TFLite Micro Inference on ESP32

## Overview

This project implements the first TinyML inference experiment on an ESP32 using TensorFlow Lite for Microcontrollers.

A small neural network is trained in Python to classify normalized light-level readings into three categories: **Dark, Normal, and Bright**. The trained model is converted into TensorFlow Lite format, embedded in the ESP32 firmware, and used to predict the class of a hardcoded input value.

## Objective

- Train a small classification model.
- Convert the trained model into `.tflite` format.
- Embed the model in the ESP32 program.
- Run on-device inference using a hardcoded sample value.
- Display the predicted class on the Serial Monitor.

## Technologies Used

- ESP32 development board
- Arduino IDE
- Python
- TensorFlow / Keras
- TensorFlow Lite
- TensorFlow Lite for Microcontrollers
- Google Colab

## Model Details

- **Input:** Normalized light-level value between 0 and 1
- **Hidden layer:** 8 neurons with ReLU activation
- **Output layer:** 3 neurons with Softmax activation
- **Classes:** Dark, Normal, Bright
- **Sample input:** 0.20

The model is trained using synthetic sample data with labels assigned according to predefined ranges.

## Classification Ranges

| Normalized input | Class |
|---|---|
| Below 0.33 | Dark |
| 0.33 to below 0.66 | Normal |
| 0.66 to 1.00 | Bright |

These ranges describe the training labels. Actual model predictions should be validated against the trained model's output.

## Project Workflow

1. Generate sample light-level data in Python.
2. Train a small neural network using TensorFlow.
3. Convert the trained model to TensorFlow Lite.
4. Export the model as a C++ header file.
5. Load the embedded model on the ESP32.
6. Allocate the input and output tensors.
7. Run inference using a hardcoded input value.
8. Print the predicted class to the Serial Monitor.

## Project Files

- `Day13_TFLite_Inference.ino` – ESP32 inference program.
- `model_data.h` – Embedded TensorFlow Lite model.
- `Day13_TFLite_Model.ipynb` – Model training and conversion notebook.
- `screenshots/` – Actual compilation and inference evidence.

## How to Run

1. Train and convert the model using Google Colab.
2. Download `model_data.h`.
3. Install compatible ESP32 board support and TensorFlow Lite Micro dependencies.
4. Open the Arduino sketch.
5. Select the correct ESP32 board and COM port.
6. Compile and upload the program.
7. Open the Serial Monitor at 115200 baud.
8. Observe the input value and predicted class.

## Expected Result

For a hardcoded input of `0.20`, the expected class is `Dark`.

The actual prediction and successful hardware execution must be confirmed using the Serial Monitor.

## Learning Outcome

This experiment demonstrates the basic TinyML deployment workflow: training a model, converting it to a microcontroller-compatible format, embedding the model, and executing inference locally on an ESP32.

## Future Scope

The model can be extended to classify live LDR sensor readings and display the classification on an OLED in Day 14. Further integration with Wi-Fi and automatic LED control can be explored in Day 15.

## Note

The model uses synthetic training data and predefined class ranges. It is an educational prototype, not a calibrated light-measurement system.
