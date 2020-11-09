#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

const char* ssid = "COLLANTES";
const char* password = "AJ2Ka3Max1";

String response = "";
DynamicJsonDocument doc(2048);


void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("WiFi connected with IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  HTTPClient http;
  http.addHeader("Content-Type", "application/json");
  String request = "http://numbersapi.com/random/?json";
  http.begin(request);
  http.GET();
  response = http.getString();
  DeserializationError error = deserializeJson(doc, response);
  if(error) {
     Serial.print(F("deserializeJson() failed: "));
     Serial.println(error.f_str());
     return;
  }
  Serial.println("");
  Serial.print("TRIVIA: ");
  Serial.println(doc["text"].as<char*>());
  Serial.println("");
 
  http.end();
  delay(5000);
}
