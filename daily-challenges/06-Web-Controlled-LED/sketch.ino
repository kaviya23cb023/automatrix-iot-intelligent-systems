#include <WiFi.h>
#include <WebServer.h>

WebServer server(80);

const int led = 2;

const char MAIN_page[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<body>
  <center>
    <h1>Wi-Fi LED On/Off Demo</h1>
    Click to turn <a href="/ledon">LED ON</a><br>
    Click to turn <a href="/ledoff">LED OFF</a>
  </center>
</body>
</html>
)rawliteral";

void handleRoot() {
  server.send(200, "text/html", MAIN_page);
}

void handleLedOn() {
  digitalWrite(led, HIGH);
  server.send(200, "text/html",
              "LED is ON. <a href=\"/\">Back</a>");
}

void handleLedOff() {
  digitalWrite(led, LOW);
  server.send(200, "text/html",
              "LED is OFF. <a href=\"/\">Back</a>");
}

void setup() {
  Serial.begin(115200);

  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);  // Start with LED off

  WiFi.mode(WIFI_STA);
  WiFi.begin("Wokwi-GUEST", "");

  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/ledon", handleLedOn);
  server.on("/ledoff", handleLedOff);

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
