# Day 11 – Simple Temperature Classifier

## Project Overview

This project demonstrates a simple machine learning classification model using TensorFlow.

A small labeled dataset of temperature readings is used to train a neural network that classifies temperatures into three categories:

- Low
- Medium
- High

After training, the model is tested with new temperature values and predicts the corresponding temperature category.

## Objective

- Create a small labeled temperature dataset.
- Train a simple neural network using TensorFlow.
- Classify temperature readings into Low, Medium, or High.
- Test the trained model with new temperature values.
- Display the predicted class for each test value.

## Technologies Used

- Python
- TensorFlow
- NumPy
- Google Colab

## Temperature Categories

| Temperature | Category |
|---:|---|
| 10–19°C | Low |
| 20–29°C | Medium |
| 30–40°C | High |

## Dataset

Sample temperature readings are labeled according to their category.

| Temperature | Class |
|---:|---|
| 10 | Low |
| 12 | Low |
| 15 | Low |
| 18 | Low |
| 20 | Medium |
| 22 | Medium |
| 25 | Medium |
| 28 | Medium |
| 30 | High |
| 33 | High |
| 36 | High |
| 40 | High |

## Working Principle

1. A labeled temperature dataset is created.
2. Each temperature value is assigned to Low, Medium, or High.
3. The dataset is used to train a small dense neural network.
4. The trained model learns the relationship between temperature and its category.
5. New temperature values are given to the model.
6. The model predicts the corresponding temperature category.
7. The predicted results are displayed.

## Model Architecture

The model contains:

- Input layer
- Dense hidden layer with ReLU activation
- Output layer with Softmax activation

The Softmax output provides probabilities for the three temperature categories.

## Sample Prediction

For example:

```text
Temperature: 15°C
Prediction: Low

Temperature: 25°C
Prediction: Medium

Temperature: 35°C
Prediction: High
