#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
 
// Replace with your network credentials
const char* ssid = "COLLANTES";
const char* password = "AJ2Ka3Max1";
 
ESP8266WebServer server(80);   //instantiate server at port 80 (http port)
 
String page = "";
int LEDPin = 2;
void setup(void){
  //the HTML of the web page
  page = "<h1>About Me</h1><h2>Full Name</h2><p>Karl Winston Lastimoza Collantes</p><h2>Address</h2><p>Lot 8, Block 7, Phase 1, San Mateo St.<br> La Verna Hills Subd.,Brgy. Cabantian, Davao City</p><h2>Contact Number</h2><p>+639499299697</p><h2>Education</h2><h3>Primary</h3><p>2006-2010<br>San Roque Central Elementary School</p><h3>Secondary</h3><p>2010-2014<br>Davao City National High School</p><h3>Tertiary</h3><p>2014-Present<br>Holy Cross of Davao College<br><i>Bachelor of Science in Information Technology</i></p><h2>Accomplishments</h2><p>Won the first place for the essay writing competition on Holy Cross of Davao College's \"Intramurals 2019\" with the theme, <i>\"Servant Leadership for All\"</i><br><br>Won the first place for the essay writing competition on College of Engineering and Technology's \"CET's Finest 2019\" with the theme, <i>\"Promoting Sportsmanship and Camaraderie Throught Sports, Literary, and Music\"</i><br><br>Attained a general weighted average of 93% on 21 units in the 2nd Semester of A.Y. 2019-2020.</p>";
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
 
  server.begin();
  Serial.println("Web server started!");
}
 
void loop(void){
  server.handleClient();
}