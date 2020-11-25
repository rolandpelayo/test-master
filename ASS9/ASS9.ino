#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

#define LED 2
 
const char* ssid = "GlobeAtHome_5E7BF";
const char* password = "DES081983DEN";

DynamicJsonDocument doc(2048);

void setup () {
  pinMode(LED, OUTPUT);
  digitalWrite(LED,HIGH);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println();

  Serial.print("Connecting.");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    digitalWrite(LED,LOW);
    delay(200);
    digitalWrite(LED,HIGH);
    delay(200);
  }
 }
 
void loop() {

  digitalWrite(LED, LOW);
  Serial.println();
  
  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
    
    HTTPClient http;
 
    http.begin("http://cat-fact.herokuapp.com/facts/random");
    
    http.GET();
    
    String payload = http.getString();
    
    DeserializationError error = deserializeJson(doc, payload);
    
    if(error) {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
      delay(5000);
      return;
    }
    //Print the parse value
    Serial.print("Type of Animal: ");
    Serial.println(doc["type"].as<char*>());

    Serial.print("Interesting Facts:Did you know that ");
    Serial.println(doc["text"].as<char*>());
    http.end();
 
  }
  digitalWrite(LED, HIGH);
  delay(8000);
}
