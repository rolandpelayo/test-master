#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>


const char* ssid = "DJR";
const char* password = "@lgabr3store";

DynamicJsonDocument doc(1024);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  Serial.println();
  Serial.print("Connecting.");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  if(WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin("http://shibe.online/api/shibes?count=5&urls=true&httpsUrls=true");
    int httpCode = http.GET();
    if (httpCode > 0) {
      String data = http.getString();
      DeserializationError error = deserializeJson(doc, data);
    
      if(error) {
        Serial.print(F("deserializeJson() failed: "));
        Serial.println(error.f_str());
        delay(5000);
        return;
      }  

      Serial.println();
      Serial.println("------------------------------------------------------------");
      Serial.print("Search for the URLs\n\n");
      Serial.print("URL: ");
      Serial.println(doc[0].as<char*>());

      Serial.print("URL: ");
      Serial.println(doc[1].as<char*>());

      Serial.print("URL: ");
      Serial.println(doc[2].as<char*>());

      Serial.print("URL: ");
      Serial.println(doc[3].as<char*>());

      Serial.print("URL: ");
      Serial.println(doc[4].as<char*>());
      
    }
    http.end();
  }
  delay(20000);
}