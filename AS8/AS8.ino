#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <FS.h>

const char* ssid = "COLLANTES";
const char* password = "AJ2Ka3Max1";

ESP8266WebServer server(80);

String text = "";
double data;

void setup(void) {
  
  pinMode(A0, INPUT);
  pinMode(2, OUTPUT);
  delay(1000);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  if (!SPIFFS.begin())
  {
    Serial.println("SPIFFS Mount failed");
  } else {
    Serial.println("SPIFFS Mount succesfull");
  }
  server.onNotFound([]() { 
    if (!handleFileRead(server.uri()))
      server.send(404, "text/plain", "404: Not Found");
  });
  server.begin();
  Serial.println("HTTP server started!");
}
void loop(void) {
  data = analogRead(A0);
  delay(1000);
  server.handleClient();
}
bool handleFileRead(String path) {
  int bytesWritten;
  Serial.println("handleFileRead: " + path);
  if (path.endsWith("/")) path += "index.html";
  String contentType = getContentType(path); 
  if (SPIFFS.exists(path)) { 
    File file = SPIFFS.open(path, "r");
    if (path == "/data.txt") {
      if (data > 980) {
        text = (String)data;
        digitalWrite(2, LOW);
        server.send(200, "text/plain", text);
      }
      else if (data <= 980) {
        text = (String)data;
        digitalWrite(2, HIGH);
        server.send(200, "text/plain", text);
      }
    }
    size_t sent = server.streamFile(file, contentType);
    file.close();
    return true;
  }
  Serial.println("\tFile Not Found");
  return false;
}
String getContentType(String filename) {
  if (filename.endsWith(".htm")) return "text/html";
  else if (filename.endsWith(".html")) return "text/html";
  else if (filename.endsWith(".css")) return "text/css";
  else if (filename.endsWith(".jpg")) return "image/jpeg";
  else if (filename.endsWith(".js")) return "text/js";
  return "text/plain";
}
