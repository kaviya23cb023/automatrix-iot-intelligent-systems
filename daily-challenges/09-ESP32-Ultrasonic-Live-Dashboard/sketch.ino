// #4 ESP32 Ultrasonic sensor
// HC-SR04 Ultrasonic distance sensor
const int pingPin = 27; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 26; // Echo Pin of Ultrasonic Sensor
int buzz=25;

void setup() {
   Serial.begin(115200); // Starting Serial Terminal
   pinMode(buzz, OUTPUT);
}

void loop() {
   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   if (cm>100){digitalWrite(buzz, HIGH);}
   else{digitalWrite(buzz,LOW);}
   Serial.print(inches);
   Serial.print("in, ");
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   delay(100);
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
