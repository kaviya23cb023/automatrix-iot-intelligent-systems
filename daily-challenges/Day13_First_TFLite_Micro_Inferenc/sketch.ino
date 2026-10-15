#include <TensorFlowLite.h>
#include <tensorflow/lite/micro/all_ops_resolver.h>
#include <tensorflow/lite/micro/micro_interpreter.h>
#include <tensorflow/lite/schema/schema_generated.h>
#include "model_data.h"

// Global variables for TFLite Micro
namespace {
  const tflite::Model* model = nullptr;
  tflite::MicroInterpreter* interpreter = nullptr;
  TfLiteTensor* input = nullptr;
  TfLiteTensor* output = nullptr;

  // Allocate 8KB memory space for tensors
  constexpr int kTensorArenaSize = 8 * 1024;
  uint8_t tensor_arena[kTensorArenaSize];

  // Class mapping
  const char* LABELS[] = {"Dark", "Normal", "Bright"};
}

void setup() {
  Serial.begin(115200);
  while (!Serial);
  
  Serial.println("\n--- ESP32 TFLite Micro Inference Test ---");

  // 1. Load the model byte array
  model = tflite::GetModel(g_model);
  if (model->version() != TFLITE_SCHEMA_VERSION) {
    Serial.println("Model schema mismatch!");
    return;
  }

  // 2. Pull in operator implementations
  static tflite::AllOpsResolver resolver;

  // 3. Build interpreter instance
  static tflite::MicroInterpreter static_interpreter(
      model, resolver, tensor_arena, kTensorArenaSize);
  interpreter = &static_interpreter;

  // 4. Allocate memory from tensor arena for model's tensors
  TfLiteStatus allocate_status = interpreter->AllocateTensors();
  if (allocate_status != kTfLiteOk) {
    Serial.println("AllocateTensors() failed!");
    return;
  }

  // 5. Obtain pointers to model inputs and outputs
  input = interpreter->input(0);
  output = interpreter->output(0);

  Serial.println("TFLite Micro Model loaded successfully!");
  
  // 6. Run Inference on a Hardcoded Sample Value
  float hardcoded_lux_sample = 450.0f; // Sample light reading (Lux)
  
  // Pass sample input into model's input tensor
  input->data.f[0] = hardcoded_lux_sample;

  // Execute inference
  TfLiteStatus invoke_status = interpreter->Invoke();
  if (invoke_status != kTfLiteOk) {
    Serial.println("Model invocation failed!");
    return;
  }

  // Extract prediction results
  float dark_prob = output->data.f[0];
  float normal_prob = output->data.f[1];
  float bright_prob = output->data.f[2];

  // Determine highest confidence class
  int predicted_class_idx = 0;
  float max_prob = dark_prob;

  if (normal_prob > max_prob) {
    max_prob = normal_prob;
    predicted_class_idx = 1;
  }
  if (bright_prob > max_prob) {
    max_prob = bright_prob;
    predicted_class_idx = 2;
  }

  // Print output to Serial Monitor
  Serial.println("\n--- Inference Results ---");
  Serial.print("Input Lux Sample: ");
  Serial.println(hardcoded_lux_sample);
  Serial.print("Predicted Category: ");
  Serial.println(LABELS[predicted_class_idx]);
  Serial.print("Confidence: ");
  Serial.print(max_prob * 100.0f, 1);
  Serial.println("%");
}

void loop() {
  // Static test runs once in setup
  delay(1000);
}
