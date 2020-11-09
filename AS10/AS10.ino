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
  String request = "http://api.openweathermap.org/data/2.5/weather?q=Houston&appid=1163124e913b6075db60dc473f12156c&units=metric";
  http.begin(request);
  http.GET();
  response = http.getString();
  DeserializationError error = deserializeJson(doc, response);
  if(error) {
     Serial.print(F("deserializeJson() failed: "));
     Serial.println(error.f_str());
     return;
  }

  const char* name = doc["name"];
  float temp = doc["main"]["temp"];
  float feels_like = doc["main"]["feels_like"];
  int humidity = doc["main"]["humidity"];
  int pressure = doc["main"]["pressure"];
  float wind_speed = doc["wind"]["speed"];
  int wind_deg = doc["wind"]["deg"];
  int clouds = doc["clouds"]["all"];
  int visibility = doc["visibility"];
  const char* weather = doc["weather"][0]["description"]; //no precipitation data in API, weather description instead

  
  Serial.print("City: ");
  Serial.println(name);
  Serial.print("Temperature: ");
  Serial.println(temp);
  Serial.print("Feels Like: ");
  Serial.println(feels_like);
  Serial.print("Humidity: ");
  Serial.println(humidity);
  Serial.print("Pressure: ");
  Serial.println(pressure);
  Serial.print("Wind Speed: ");
  Serial.println(wind_speed);
  Serial.print("Wind Degree: ");
  Serial.println(wind_deg);
  Serial.print("Clouds: ");
  Serial.println(clouds);
  Serial.print("Visibility: ");
  Serial.println(visibility);
  Serial.print("Weather: ");
  Serial.println(weather);
  Serial.println("All units in metric.");
 
  http.end();
  delay(60000);
  //update weather every hour
}
