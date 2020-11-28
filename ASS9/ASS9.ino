#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
 
const char* ssid = "GlobeAtHome_5E7BF";
const char* password = "DES081983DEN";

DynamicJsonDocument doc(2048);

 
void setup () {

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN,HIGH);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println();

  Serial.print("Connecting.");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    digitalWrite(LED_BUILTIN,LOW);
    delay(250);
    digitalWrite(LED_BUILTIN,HIGH);
    delay(250);
  }
  
}
 
void loop() {

  digitalWrite(LED_BUILTIN, LOW);
  Serial.println();
  
  if (WiFi.status() == WL_CONNECTED) { 
    
    HTTPClient http;
 
    http.begin("http://www.boredapi.com/api/activity?key=5881028");
    
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
    Serial.print("     To do when you bored.");
    Serial.print("\n");
    Serial.print("\n");
    Serial.print("  What to do: ");
    Serial.println(doc["activity"].as<char*>());

    Serial.print("  Type of Activity: ");
    Serial.println(doc["type"].as<char*>());

    Serial.print("  Participants: You ");
    

 
    http.end();
 
  }

  digitalWrite(LED_BUILTIN, HIGH);
  delay(10000);
  
}
