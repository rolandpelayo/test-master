#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

const char* ssid = "PCEPE";
const char* password = "yamachine";

void setup() 
{
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(1000);
    Serial.println("Connecting...");
  }
}

void loop() 
{
  if (WiFi.status() == WL_CONNECTED) 
  {
    HTTPClient http; //Object of class HTTPClient
    http.begin("https://breaking-bad-quotes.herokuapp.com/v1/quotes");
    int httpCode = http.GET();

    if (httpCode > 0) 
    {
      const size_t bufferSize = JSON_OBJECT_SIZE(2) + JSON_OBJECT_SIZE(3) + JSON_OBJECT_SIZE(5) + JSON_OBJECT_SIZE(8) + 370;
      DynamicJsonDocument jsonDocument(bufferSize);
      DeserializationError error = deserializeJson(jsonDocument, http.getString());
      if (error) {
        Serial.println("There was an error while deserializing");
      }
      else {
        JsonObject root = jsonDocument.as<JsonObject>();
        
      const char* quote = root["quote"]; 
      const char* author = root["author"]; 

      Serial.print("Quote:");
      Serial.println(quote);
      Serial.print("Author");
      Serial.println(author);
      }
    http.end(); //Close connection
    }
  delay(60000);
  }
}
