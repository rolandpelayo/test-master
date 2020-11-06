#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <FS.h>

 
// Replace with your network credentials
const char* ssid = "AN5506-04-FA_a2da8";
const char* password = "T3amB4hay";

ESP8266WebServer server(80); //instantiate server at port 80 (http port

void setup(void){
//For debugging
Serial.begin(115200);
//Initiate WiFi connection
WiFi.begin(ssid, password); //begin WiFi connection
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
server.send(404, "text/plain", "404: Not Found");
});
//start web server
server.begin();
 //Just stating things
  Serial.println("HTTP server started");
}

void loop() {
  delay(1000);
  server.handleClient(); //make the ESP32 respond to web clients
}
 
bool handleFileRead(String path) { // send the right file to the client (if it exists)
  int bytesWritten;
  Serial.println("handleFileRead: " + path);
  if (path.endsWith("/")) path += "As10.html"; // If a folder is requested, send the index file
  String contentType = getContentType(path); // Get the MIME type
  if (SPIFFS.exists(path)) { // If the file exists
    File file = SPIFFS.open(path, "r"); // Open it
    size_t sent = server.streamFile(file, contentType);
    file.close(); // Then close the file again
    return true;
  }
  Serial.println("\tFile Not Found");
  return false; // If the file doesn't exist, return false
}
 
String getContentType(String filename){
  if(filename.endsWith(".html")) return "text/html";
  else if(filename.endsWith(".html")) return "text/html";
  else if(filename.endsWith(".js")) return "js/text";
  else if(filename.endsWith(".json")) return "text/json";
  return "text/plain";
}
