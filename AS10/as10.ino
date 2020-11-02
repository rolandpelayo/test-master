#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <Arduino_JSON.h>

const char* ssid = "SKYfiberC6DE";
const char* password = "430019462";
String openWeatherMapApiKey = "1436fe5a7bc45c20898cc8418e0c165b";
String city = "Bicol";
String countryCode = "PH";
unsigned long lastTime = 0;
unsigned long timerDelay = 3000;
String jsonBuffer;

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  if ((millis() - lastTime) > timerDelay) {
    if(WiFi.status()== WL_CONNECTED){
      String serverPath = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "," + countryCode + "&APPID=" + openWeatherMapApiKey;
      jsonBuffer = httpGETRequest(serverPath.c_str());
      JSONVar myObject = JSON.parse(jsonBuffer);
      
      if (JSON.typeof(myObject) == "undefined") {
        Serial.println("Parsing input failed!");
        return;
      }

      //
      Serial.println("Current Weather at " + city);
      Serial.print("Temperature: ");
      Serial.println(myObject["main"]["temp"]);
      Serial.print("Feels Like: ");
      Serial.println(myObject["main"]["feels_like"]);
      Serial.print("Humidity: ");
      Serial.println(myObject["main"]["humidity"]);
      Serial.print("Pressure: ");
      Serial.println(myObject["main"]["pressure"]);
      Serial.print("Wind: ");
      Serial.println(myObject["wind"]["speed"]);
      Serial.print("Clouds: ");
      Serial.println(myObject["clouds"]["all"]);
      Serial.print("Visibility: ");
      Serial.println(myObject["visibility"]);
      Serial.print("Precipitation: ");
      Serial.println(myObject["precipitation"]);
      Serial.println("Update Every 5 Seconds");
      Serial.println("");
    }
    else {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  }
}

String httpGETRequest(const char* serverName) {
  HTTPClient http;
    
  http.begin(serverName);
 
  int httpResponseCode = http.GET();
  
  String payload = "{}"; 
  
  if (httpResponseCode>0) {
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  http.end();

  return payload;
}