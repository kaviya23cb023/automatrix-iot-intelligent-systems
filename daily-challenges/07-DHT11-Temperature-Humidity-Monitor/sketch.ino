#include <DHT.h>  
#include <LiquidCrystal_I2C.h> // LCD librairy.h>
//===============================================================================
// Set up the DHT sensor  and LCD
const int DHT_Pin =4;                            // The DHT pin 
float temperature ;                             // Sensor temperature
float  humidity;                               // Sensor Humidity
int counter;                                  // Data counter
int totalColumns = 16;                       // number of colums pixels on the LCD
int totalRows = 2;                          // number of rows pixels on the LCD
const int delayTime = 500;                 // delay time on between each iteration
const int scrolling_time = 100;           // Scrolling time of the test
DHT dht(DHT_Pin, DHT22); // If you are using the DHT22, you just need to change the value 11 to 22
LiquidCrystal_I2C lcd(0x27, totalColumns, totalRows);  // Define the lcd object from the liduidCrystal class
String staticMessage = "DHT Tutorial";
String scrollingMessage = "Welcome to ESP32 with DHT11 !";

//=============================================================================
// The below function allow us to scroll a test and it is used to scroll the ouput of data of the sensor
void scrollMessage(int row, String message, int delayTime, int totalColumns) {
  for (int i=0; i < totalColumns; i++) {
    message = " " + message;  
  } 
  message = message + " "; 
  for (int position = 0; position < message.length(); position++) {
    lcd.setCursor(0, row);
    lcd.print(message.substring(position, position + totalColumns));
    delay(delayTime);
  }
}
//=================================================================================
void setup(){
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello, ESP32!");
  lcd.init();                        // Initialize the LCD          
  lcd.backlight();                  // Turn on the back light
  lcd.clear();                     // clear everything from the screen
  lcd.setCursor(2, 0);            // set the position of the test
  lcd.print(staticMessage);      // print the static message 
  scrollMessage(1, scrollingMessage, scrolling_time, totalColumns);
}



void loop() {
  // put your main code here, to run repeatedly:
  temperature = dht.readTemperature();       // To store the values of tempreature
  humidity = dht.readHumidity();            // To store the values of Humidity
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Data: "+ String(counter));   // Print the data index
  // Print the values of Humidity 
  lcd.setCursor(0,1);
  String scrollingMessageHumidity = "Humidity: "+String(humidity);
  scrollMessage(1, scrollingMessageHumidity, scrolling_time, totalColumns);

  // Print he values of Temperature in Celsus
  String scrollingMessageTemperature = "Temperature: "+String(dht.readTemperature(false)) +"C";
  scrollMessage(1, scrollingMessageTemperature, scrolling_time, totalColumns);
  // Print the values of temperature in Fahrenheit
  String scrollingMessageTemperatureFahrenheit = "Temperature: "+String(dht.readTemperature(true)) +"F";
  scrollMessage(1, scrollingMessageTemperatureFahrenheit, scrolling_time, totalColumns);
  // Print the values of the heat Index for both Units
  String scrollingMessageHeatIndexCelsus = "Heat Index In Celsus: "+String(dht.computeHeatIndex(temperature, humidity, false)) +"%";
  scrollMessage(1, scrollingMessageHeatIndexCelsus, scrolling_time, totalColumns);
  String scrollingMessageHeatIndexFahrenheit = "Heat Index In Fahrenheit: "+String(dht.computeHeatIndex(temperature, humidity, true)) +"%";
  scrollMessage(1, scrollingMessageHeatIndexFahrenheit, scrolling_time, totalColumns);
  delay(delayTime);
  counter++;  // update the counbter

}
