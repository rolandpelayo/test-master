#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
 
// Replace with your network credentials
const char* ssid = "CIDG CYBERCRIME";
const char* password = "1980treborobet";
 
ESP8266WebServer server(80);   //instantiate server at port 80 (http port)
 
int LEDPin = 2;

  //the HTML of the web page
  const char page[] PROGMEM = R"=====(
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
  )=====";

  void setup() {
  //make the LED pin output and initially turned off
  pinMode(LEDPin, OUTPUT);
  digitalWrite(LEDPin, LOW);
   
  delay(1000);
  Serial.begin(115200);
  WiFi.begin(ssid, password); //begin WiFi connection
  Serial.println("");
 
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
   
  server.on("/", [](){
    server.send(200, "text/html", page);
  });
  server.on("/LEDOn", [](){
    server.send(200, "text/html", page);
    digitalWrite(LEDPin, HIGH);
    delay(1000);
  });
  server.on("/LEDOff", [](){
    server.send(200, "text/html", page);
    digitalWrite(LEDPin, LOW);
    delay(1000); 
  });
  server.begin();
  Serial.println("Web server started!");
}
 
void loop(void){
  server.handleClient();
}
