#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

#define LED 2
// WiFi SSID and PASSWORD
const char* ssid = "GlobeAtHome_5E7BF";
const char* password = "DES081983DEN";

DynamicJsonDocument doc(2048);

void setup() {
  pinMode(LED, OUTPUT);
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
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Check WiFi Status
  digitalWrite(LED, LOW);
  if(WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin("http://api.openweathermap.org/data/2.5/weather?q=Cebu&appid=4e9da2c87397ff82778dd8f344686af3&units=metric");
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
      Serial.println("   ESP8266 Weather Monitor   ");
      Serial.print("           ");
      Serial.println(doc["name"].as<char*>()); // City name
      
      Serial.print("  Weather Forecast: ");
      Serial.println(doc["weather"][0]["description"].as<char*>()); // Weather

      Serial.print("--Temperature: ");
      Serial.print(doc["main"]["temp"].as<float>()); // Temperature in celsius
      Serial.println("°C");

      Serial.print("--Feels Like: ");
      Serial.print(doc["main"]["feels_like"].as<float>()); // Feels temperatire in clesius
      Serial.println("°C");

      Serial.print("--Humidity: ");
      Serial.print(doc["main"]["humidity"].as<int>()); // Humidity in percentage
      Serial.println("%");

      Serial.print("--Atmospheric pressure (sea level): ");
      Serial.print(doc["main"]["pressure"].as<int>()); // Preassure in Hectopascal Pressure Unit
      Serial.println(" hPa");

      Serial.print("--Wind Speed: ");
      Serial.print(doc["wind"]["speed"].as<float>()); // Wind speed in meters per second
      Serial.println(" meters/sec");

      Serial.print("--Cloudiness: ");
      Serial.print(doc["clouds"]["all"].as<int>()); // Clouds in percentage
      Serial.println("%");

      Serial.print("--Visibility: ");
      Serial.print(doc["visibility"].as<int>()); // Visibility in meters
      Serial.println("m");

      Serial.print("--Precipitation: ");
      Serial.print(doc["rain"]["1h"].as<float>()); // precipication in 1hr in milimeter
      Serial.println("mm");
      Serial.print(" (Rain volume for the last 1 hour)");

    }
    http.end();
  }
  digitalWrite(LED, HIGH);
  delay(1800000); // displays JSON API data every30 Minutes.
}
