#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

#define led 2
 
const char* ssid = "XxXxXxX";
const char* password = "QWERTYuiop00";

DynamicJsonDocument deserializedJSON(4096);

void setup () {

  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println();

  Serial.print("Connecting.");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  
}
 
void loop() {

  Serial.println();
  
  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
    
    HTTPClient http;

    // API
    http.begin("http://api.coindesk.com/v1/bpi/currentprice.json");
    
    http.GET();

    // Get serialized JSON
    String serializedJSON = http.getString();

    // Deserialize JSON to object
    DeserializationError error = deserializeJson(deserializedJSON, serializedJSON);
    
    if(error) {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
      delay(5000);
      return;
    }

    // Parse and print
    Serial.print("---Bitcoin Price Index---");
    Serial.println();
    
    Serial.print("USD: ");
    Serial.println(deserializedJSON["bpi"]["USD"]["rate"].as<char*>());

    Serial.print("GBP: ");
    Serial.println(deserializedJSON["bpi"]["GBP"]["rate"].as<char*>());

    Serial.print("EUR: ");
    Serial.println(deserializedJSON["bpi"]["EUR"]["rate"].as<char*>());

    Serial.print("--------------------------");
 
    http.end();
 
  }
  
  delay(60000);
  
}