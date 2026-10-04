#include <Arduino.h>

const float model_weight = 2.000000f;
const float model_bias = -0.000000f;

// Model inference: y = x * weight + bias
float predict(float input_x) {
  return (input_x * model_weight) + model_bias;
}

void printResults() {
  Serial.println();
  Serial.println("ESP32 model inference: y = 2x");

  const float test_inputs[] = {-5.0f, -1.5f, 0.0f, 2.5f, 10.0f, 42.0f};
  const int num_tests = sizeof(test_inputs) / sizeof(test_inputs[0]);

  for (int i = 0; i < num_tests; i++) {
    const float x = test_inputs[i];
    const float actual = 2.0f * x;
    const float predicted = predict(x);

    Serial.print("Input X: ");
    Serial.print(x, 2);
    Serial.print(" | Actual Y: ");
    Serial.print(actual, 2);
    Serial.print(" | Predicted Y: ");
    Serial.println(predicted, 4);
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("ESP32 is ready.");
}

void loop() {
  printResults();
  delay(3000);
}
