#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

//Provide your own WiFi credentials
const char* ssid = "SKYfiberC6DE";
const char* password = "430019462";
//String for storing server response
String response = "";
//JSON document
DynamicJsonDocument doc(2048);


void setup() {
  Serial.begin(115200);
  //Initiate WiFi connection
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");
 
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("WiFi connected with IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  //Initiate HTTP client
  HTTPClient http;
  //The API URL to get a random joke
  String request = "http://official-joke-api.appspot.com/jokes/random";
  //Start the request
  http.begin(request);
  //Use HTTP GET request
  http.GET();
  //Response from server
  response = http.getString();
  //Parse JSON, read error if any
  DeserializationError error = deserializeJson(doc, response);
  if(error) {
     Serial.print(F("deserializeJson() failed: "));
     Serial.println(error.f_str());
     delay(5000);
     return;
  }
  //Print parsed value on Serial Monitor
  Serial.print("Joke Type: ");
  Serial.println(doc["type"].as<char*>());
  Serial.print("Joke: ");
  Serial.println(doc["setup"].as<char*>());
  Serial.print("Punchline: ");
  Serial.println(doc["punchline"].as<char*>());
  Serial.println("");
  //Close connection  
  http.end();
  //Wait five seconds for next joke
  delay(5000);
}