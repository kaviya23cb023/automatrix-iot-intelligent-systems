#include <Arduino.h>
#include <math.h>
// Class labels: Low (<20 C), Medium (20-30 C), High (>30 C)
const char* CLASSES[] = {"Low (<20C)", "Medium (20-30C)", "High (>30C)"};
// Input: normalized temperature, x = (temperature - 25) / 15
// Hidden layer: 4 ReLU neurons
// Output layer: 3 softmax scores
const float W1[4] = {-2.45f, -0.85f, 0.92f, 2.70f};
// Use a name other than B1: the ESP32 Arduino core defines B1 as a macro.
const float hiddenBias[4] = {1.10f, 0.45f, 0.40f, 1.25f};
const float W2[3][4] = {
  { 1.85f,  0.30f, -0.90f, -2.10f}, // Low
  {-0.60f,  1.40f,  1.35f, -0.70f}, // Medium
  {-2.10f, -0.80f,  0.45f,  1.95f}  // High
};
const float outputBias[3] = {0.80f, 0.50f, 0.75f};
int predictTemperatureClass(float tempC, float confidences[3]) {
  const float x = (tempC - 25.0f) / 15.0f;
  float hidden[4];
  for (int j = 0; j < 4; ++j) {
    const float z = x * W1[j] + hiddenBias[j];
    hidden[j] = (z > 0.0f) ? z : 0.0f;
  }
  float logits[3];
  float maxLogit = -1.0e9f;
  for (int i = 0; i < 3; ++i) {
    logits[i] = outputBias[i];
    for (int j = 0; j < 4; ++j) {
      logits[i] += W2[i][j] * hidden[j];
    }
    if (logits[i] > maxLogit) maxLogit = logits[i];
  }
  float sumExp = 0.0f;
  for (int i = 0; i < 3; ++i) {
    confidences[i] = expf(logits[i] - maxLogit);
    sumExp += confidences[i];
  }
  int bestClass = 0;
  float maxConfidence = -1.0f;
  for (int i = 0; i < 3; ++i) {
    confidences[i] /= sumExp;
    if (confidences[i] > maxConfidence) {
      maxConfidence = confidences[i];
      bestClass = i;
    }
  }
  return bestClass;
}
void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("--- ESP32 Neural Network Classifier Started ---");
}
void loop() {
  const float testTemps[] = {12.5f, 18.0f, 22.4f, 27.5f, 31.0f, 38.2f};
  const size_t count = sizeof(testTemps) / sizeof(testTemps[0]);
  for (size_t k = 0; k < count; ++k) {
    float probabilities[3];
    const int predicted = predictTemperatureClass(testTemps[k], probabilities);
    Serial.printf("Input: %5.1f C | Class: %-15s | Conf: L: %.2f  M: %.2f  H: %.2f\n",
                  testTemps[k], CLASSES[predicted],
                  probabilities[0], probabilities[1], probabilities[2]);
    delay(1200);
  }
  Serial.println("--------------------------------------------------");
  delay(2000);
}
