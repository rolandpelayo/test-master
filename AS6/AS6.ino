/*
 
ESP8266 WiFi Server with SPIFFS
by Karl Winston Collantes
 
Submitted on 9/24/2020
 
*/
 
//Declare libraries
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <FS.h>
 
//provide your own WiFi SSID and password
const char* ssid = "COLLANTES";
const char* password = "AJ2Ka3Max1";
 
//Create WebServer instance
ESP8266WebServer server(80);
 
void setup() {
  //Setup on-board LED
  pinMode(2, OUTPUT);
  //For debugging
  Serial.begin(115200);
  //Initiate WiFi Connection
  WiFi.begin(ssid, password);
  Serial.println("");
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  //Print your WiFi's SSID (might be insecure)
  Serial.println(ssid);
  Serial.print("IP address: ");
  //Print your local IP address (needed for browsing the app)
  Serial.println(WiFi.localIP());
 
  if(!SPIFFS.begin())
  {
    // Serious problem
    Serial.println("SPIFFS Mount failed");
  } else {
    Serial.println("SPIFFS Mount succesfull");
  }
 
  server.onNotFound([]() { // If the client requests any URI
    if (!handleFileRead(server.uri())) // send it if it exists
      server.send(404, "text/plain", "404: Not Found"); // otherwise, respond with a 404 (Not Found) error
  });
 
  //start web server
  server.begin();
  //Just stating things
  Serial.println("HTTP server started");
}
 
void loop() {
  server.handleClient(); //make the ESP32 respond to web clients
}
 
bool handleFileRead(String path) { // send the right file to the client (if it exists)
  Serial.println("handleFileRead: " + path);
  if (path.endsWith("/")) path += "index.html"; // If a folder is requested, send the index file
  String contentType = getContentType(path); // Get the MIME type
  if (SPIFFS.exists(path)) { // If the file exists
    File file = SPIFFS.open(path, "r"); // Open it
    size_t sent = server.streamFile(file, contentType); // And send it to the client
    if(path == "/LEDOn.html"){
      digitalWrite(2, LOW);
    }else if(path == "/LEDOff.html"){
      digitalWrite(2, HIGH);
    }
    file.close(); // Then close the file again
    return true;
  }
  Serial.println("\tFile Not Found");
  return false; // If the file doesn't exist, return false
}
 
String getContentType(String filename){
  if(filename.endsWith(".htm")) return "text/html";
  else if(filename.endsWith(".html")) return "text/html";
  else if(filename.endsWith(".css")) return "text/css";
  else if(filename.endsWith(".jpg")) return "image/jpeg";
  return "text/plain";
}