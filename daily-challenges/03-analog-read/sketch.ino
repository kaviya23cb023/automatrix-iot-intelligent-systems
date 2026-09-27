#define POT_PIN 34

void setup() {
  Serial.begin(115200);
  pinMode(POT_PIN, INPUT);

  Serial.println("ESP32 Analog Read Started");
}

void loop() {
  int sensorValue = analogRead(POT_PIN);

  Serial.print("Analog Value: ");
  Serial.println(sensorValue);

  delay(500);
}
