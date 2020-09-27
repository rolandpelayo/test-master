/* ASSIGNMENT 6
   by Gericko S. Maandig
   on September 28
*/

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <FS.h>

ESP8266WebServer server;
uint8_t pin_led = 2;
char* ssid = "SSID";
char* password = "PASSWORD";

void setup() {
  // put your setup code here, to run once:
  SPIFFS.begin();
  pinMode(pin_led, OUTPUT);
  WiFi.begin(ssid, password);
  Serial.begin(115200);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/",serveIndexFile);
  server.on("/ledstate", getLEDState);
  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
}

void serveIndexFile() {
  File file = SPIFFS.open("/on and off.html", "r");
  server.streamFile(file, "text/html");
  file.close();
}

void getLEDState() {
  toggleLED();
  String led_state = digitalRead(pin_led) ? "OFF" : "ON" ;
  server.send(200,"text/plain", led_state);
}

void toggleLED() {
  digitalWrite(pin_led, !digitalRead(pin_led));
}