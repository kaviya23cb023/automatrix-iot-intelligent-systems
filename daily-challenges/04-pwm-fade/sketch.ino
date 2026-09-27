#define POT_PIN 34
#define LED_PIN 18

void setup() {
  Serial.begin(115200);

  pinMode(POT_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  analogWriteResolution(LED_PIN, 8);

  Serial.println("ESP32 PWM Fade Started");
}

void loop() {
  int sensorValue = analogRead(POT_PIN);

  int brightness = map(sensorValue, 0, 4095, 0, 255);

  analogWrite(LED_PIN, brightness);

  Serial.print("Analog Value: ");
  Serial.print(sensorValue);

  Serial.print(" | LED Brightness: ");
  Serial.println(brightness);

  delay(100);
}
