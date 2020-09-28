#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server;

#define pin_led D2

char* ssid = "CIDG CYBERCRIME";
char* password = "1980treborobet";

char webpage[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
  <head>
    <title>My Web Server Page</title>
  </head>
  <body>
    <h1>Full Name: Precious Enica L. Cepe</h1>
    <h1>Address: Brgy 38 - D Poblacion, Trading Boulevard, Davao City</h1>
    <h1>Contact Number: 09101061885</h1>
    <h1>Education</h1>
    <dl>
      <dd><p style="font-size: 30px;">- Elementary: San Roque Central Elementary School</p></dd>
      <dd><p style="font-size: 30px;">- Junior High School: Davao City National High School</p></dd>
      <dd><p style="font-size: 30px;">- Senior High School: Philippine Womens College of Davao</p></dd>
      <dd><p style="font-size: 30px;">- College: Holy Cross of Davao College</p></dd>
    </dl>
    <h1>Accomplishment</h1>
    <dd><p style="font-size: 30px;">I CAN'T THINK OF ANY ACCOMPLISHMENT OF MINE.</p></dd>
  </body>
  </html>
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
