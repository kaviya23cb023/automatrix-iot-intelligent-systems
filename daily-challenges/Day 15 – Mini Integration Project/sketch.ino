#include <WiFi.h>
#include <WebServer.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <TensorFlowLite.h>
#include <tensorflow/lite/micro/all_ops_resolver.h>
#include <tensorflow/lite/micro/micro_interpreter.h>
#include <tensorflow/lite/schema/schema_generated.h>
#include "model_data.h"

// Hardware Pin Definitions
#define LDR_PIN 34
#define LED_PIN 2
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

// WiFi Credentials (Wokwi Virtual Network)
const char* ssid = "Wokwi-GUEST";
const char* password = "";

WebServer server(80);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// TensorFlow Lite Micro Objects
namespace {
  const tflite::Model* model = nullptr;
  tflite::MicroInterpreter* interpreter = nullptr;
  TfLiteTensor* input = nullptr;
  TfLiteTensor* output = nullptr;

  constexpr int kTensorArenaSize = 8 * 1024;
  uint8_t tensor_arena[kTensorArenaSize];

  const char* LABELS[] = {"DARK", "NORMAL", "BRIGHT"};
}

// Global System State
float currentLux = 0.0;
String currentClass = "DARK";
float currentConfidence = 0.0;
bool ledStatus = false;

// HTTP Dashboard Handler
void handleRoot() {
  String html = "<!DOCTYPE html><html><head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">";
  html += "<title>Smart Light TinyML Dashboard</title>";
  html += "<style>";
  html += "body { font-family: Arial, sans-serif; text-align: center; background-color: #121212; color: #ffffff; margin-top: 30px; }";
  html += ".card { background: #1e1e1e; padding: 25px; border-radius: 12px; display: inline-block; box-shadow: 0 4px 10px rgba(0,0,0,0.5); width: 80%; max-width: 400px; }";
  html += ".stat { font-size: 24px; margin: 15px 0; color: #00e676; }";
  html += ".label { color: #aaa; font-size: 14px; text-transform: uppercase; }";
  html += "</style>";
  html += "<script>";
  html += "setInterval(function() {";
  html += "  fetch('/data').then(res => res.json()).then(data => {";
  html += "    document.getElementById('lux').innerText = data.lux;";
  html += "    document.getElementById('class').innerText = data.class;";
  html += "    document.getElementById('conf').innerText = data.confidence + '%';";
  html += "    document.getElementById('led').innerText = data.led ? 'ON (Night Light)' : 'OFF';";
  html += "  });";
  html += "}, 1000);";
  html += "</script></head><body>";
  html += "<div class=\"card\">";
  html += "<h2>Smart Light Classifier</h2>";
  html += "<hr style=\"border-color: #333;\">";
  html += "<div class=\"label\">Live Ambient Sensor</div><div class=\"stat\"><span id=\"lux\">0</span> Lux</div>";
  html += "<div class=\"label\">TinyML Prediction</div><div class=\"stat\"><span id=\"class\">--</span></div>";
  html += "<div class=\"label\">Confidence Level</div><div class=\"stat\"><span id=\"conf\">0%</span></div>";
  html += "<div class=\"label\">Actuator LED Status</div><div class=\"stat\"><span id=\"led\">--</span></div>";
  html += "</div></body></html>";

  server.send(200, "text/html", html);
}

// JSON Endpoint for Real-time AJAX Updates
void handleData() {
  String json = "{";
  json += "\"lux\":" + String((int)currentLux) + ",";
  json += "\"class\":\"" + currentClass + "\",";
  json += "\"confidence\":" + String(currentConfidence, 1) + ",";
  json += "\"led\":" + String(ledStatus ? "true" : "false");
  json += "}";
  server.send(200, "application/json", json);
}

void setup() {
  Serial.begin(115200);
  pinMode(LDR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  // Initialize OLED
  Wire.begin(21, 22);
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Connecting WiFi...");
  display.display();

  // Initialize WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Setup Web Server
  server.on("/", handleRoot);
  server.on("/data", handleData);
  server.begin();

  // Initialize TFLite Micro
  model = tflite::GetModel(g_model);
  static tflite::AllOpsResolver resolver;
  static tflite::MicroInterpreter static_interpreter(model, resolver, tensor_arena, kTensorArenaSize);
  interpreter = &static_interpreter;
  interpreter->AllocateTensors();
  input = interpreter->input(0);
  output = interpreter->output(0);
}

void loop() {
  // Handle HTTP Server Requests
  server.handleClient();

  // 1. Read Sensor
  int rawLdr = analogRead(LDR_PIN);
  currentLux = map(rawLdr, 0, 4095, 0, 2500);

  // 2. TFLite Micro Inference
  input->data.f[0] = currentLux;
  if (interpreter->Invoke() == kTfLiteOk) {
    float dark_prob = output->data.f[0];
    float normal_prob = output->data.f[1];
    float bright_prob = output->data.f[2];

    int predictedClass = 0;
    float maxProb = dark_prob;

    if (normal_prob > maxProb) {
      maxProb = normal_prob;
      predictedClass = 1;
    }
    if (bright_prob > maxProb) {
      maxProb = bright_prob;
      predictedClass = 2;
    }

    currentClass = LABELS[predictedClass];
    currentConfidence = maxProb * 100.0f;

    // 3. Automated Actuator Control based on TinyML Prediction
    // Auto-turn ON LED if TinyML classifies environment as DARK
    if (predictedClass == 0) {
      digitalWrite(LED_PIN, HIGH);
      ledStatus = true;
    } else {
      digitalWrite(LED_PIN, LOW);
      ledStatus = false;
    }

    // 4. OLED Rendering
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.print("IP: ");
    display.println(WiFi.localIP());
    display.drawFastHLine(0, 10, 128, SSD1306_WHITE);

    display.setCursor(0, 16);
    display.print("Lux: ");
    display.print((int)currentLux);

    display.setCursor(0, 30);
    display.print("Class: ");
    display.setTextSize(2);
    display.setCursor(45, 26);
    display.println(currentClass);

    display.setTextSize(1);
    display.setCursor(0, 48);
    display.print("LED: ");
    display.println(ledStatus ? "ON" : "OFF");

    display.display();
  }

  delay(200); // Sampling and Web Server processing delay
}
