#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

#define led 2
 
const char* ssid = "SSID";
const char* password = "PASSWORD";

DynamicJsonDocument doc(2048);

 
void setup () {

  pinMode(led, OUTPUT);
  digitalWrite(led,HIGH);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println();

  Serial.print("Connecting.");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    digitalWrite(led,LOW);
    delay(250);
    digitalWrite(led,HIGH);
    delay(250);
  }
  
}
 
void loop() {

  digitalWrite(led, LOW);
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
    Serial.print("Type: ");
    Serial.println(doc["type"].as<char*>());

    Serial.print("Fact: ");
    Serial.println(doc["text"].as<char*>());
 
    http.end();
 
  }

  digitalWrite(led, HIGH);
  delay(30000);
  
}