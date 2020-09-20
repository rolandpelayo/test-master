/* ASSIGNMENT 5
   by Gericko S. Maandig
   on September 20
*/

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server;

#define pin_led D2

char* ssid = "TP-LINK";
char* password = "09998321149";

char webpage[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
<title> BASIC INFORMATION </title>
</head>
<body>
<h> BASIC INFORMATION </h>
<p> Full Name: Gericko S. Maandig </p>
<p> Address: P10-A Tibungco, Davao City </p>
<p> Contact Number: 09496517417 </p>
<p> <=============================================================================================> </p>
<p> [Education] </p>
<p> Elementary: Anthony and Mark Cavanis Elemetary School </p>
<p> School Year: 2007 - 2013 </p>
<p> Jinior HighSchool: Philippine Nikkei Jin Kai International School </p>
<p> School Year: 2013 - 2017 </p>
<p> Senior HighSchool: Philippine Nikkei Jin Kai International School </p>
<p> School Year: 2017 - 2019 </p>
<p> <=============================================================================================> </p>
<p> Accomplishments: Finishing Kinder, Elementary, Jinior HighSchool and Senior HighSchool </p>
</body>
</html>
)=====";

void setup() {
  // To connect the ESP8266 to your home wifi
  pinMode(pin_led, OUTPUT);
  
  
  WiFi.begin(ssid, password);
  Serial.begin(115200);
  while(WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.print("IP Address: ");
  Serial.print(WiFi.localIP());

  server.on("/", [](){
    server.send(200, "text/html", webpage);
  });
  server.begin();
}

void loop() {
  server.handleClient();
}