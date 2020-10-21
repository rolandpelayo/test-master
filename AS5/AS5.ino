#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
 
// Replace with your network credentials
const char* ssid = "reyz";
const char* password = "12345678";
 
ESP8266WebServer server(80);   //instantiate server at port 80 (http port)
 
String page = "";
int LEDPin = 2;
void setup(void){
  //the HTML of the web page
   page = "<h1>Basic Information</h1>"
         "<h2>Name: Reynaldo Pagaran </h2>"
         "<h2>Address: Ruiz Village Agdao </h2>"
         "<h2>Contact Number: 09108976654 </h2>"
         "<h1>Education</h1>"
         "<h2>Primary</h2>"
         "<h3>Don Julian Rodriguez Sr. Elementary School</h3>"
         "<h2>Secondary<h2>" 
         "<h3>Assumption College of Davao</h3>"
         "<h2>Tertiary</h2>"
         "<h3>Holy Cross of Davao College</h3>"
         "<h1>Accomplishments</h1>"
         "<h2>None</h2>";
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