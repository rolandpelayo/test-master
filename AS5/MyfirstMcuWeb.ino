
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
 
// Replace with your network credentials
const char* ssid = "AN5506-04-FA_a2da8";
const char* password = "T3amB4hay";
const char myhtml[] PROGMEM={"<!DOCTYPE html>\n"
"<html>\n"
"<head>\n"
"\t<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n"
"\t<style>\n"
"     \t@import url('https://fonts.googleapis.com/css2?family=Philosopher:wght@700&display=swap');\n"
"\t\t@import url('https://fonts.googleapis.com/css2?family=Amaranth:ital,wght@1,700&family=Philosopher:wght@700&display=swap');\n"
"\t\t@import url('https://fonts.googleapis.com/css2?family=Noto+Serif:wght@700&display=swap');\n"
"\t\t@import url('https://fonts.googleapis.com/css2?family=Noto+Serif:ital@1&display=swap');\n"
"    body{\n"
"    \tmargin-left: 100px;\n"
"    \tmargin-right: 100px;\n"
"        }\n"
"\t\th2{\n"
"\t   background-color: #A30933;\n"
"\t   margin-top: 0px;\n"
"\t   padding: 12px;\n"
"       font-family: Philosopher;\n"
"       font-size: 27px;\n"
"       color: white;   \n"
"        }\n"
"\t\th3{\n"
"\t\t\tcolor:#050B47;\n"
"\t\t\tfont-family: 'Noto Serif';\n"
"\t\t}\n"
"      h4{\n"
"      \tpadding:12px;\n"
"      \tbackground-color: #A30933;\n"
"      \tcolor: white;  \n"
"      \tfont-size: 25px;\n"
"      \tfont-family: Philosopher;\n"
"      }\n"
"table{\n"
"\tborder: 2px solid black;\n"
"\twidth: 100%;\n"
"}\n"
"table, th,td{\n"
"\tborder: 2px solid black;\n"
"  border-collapse: collapse;\n"
"}\n"
"th, td{\n"
"\tpadding: 10px;\n"
"\t\n"
"}\n"
"th{\n"
"\tfont-size: 20px;\n"
"\tfont-family: 'Noto Serif', serif;\n"
"\t\n"
"}\n"
"tr{\n"
"    font-size: 17px;\n"
"\tfont-family: 'Noto Serif', serif\n"
"}\n"
"\t</style>\n"
"\t<title>My First NodeMCU WebServer</title>\n"
"</head>\n"
"<body>\n"
"\t<h2>Students' Information</h2>\n"
"<h3>Name: Fairy Blessa Y. Eyas</h3>\n"
"<h3>Address: #45 Nidea Street Brgy. 17-B Obrero, Davao City</h3>\n"
"<h3>Contact Number: 09952234806</h3>\n"
"<h3>BSIT - 2nd Year</h3>\n"
"\n"
"<h4>Education</h4>\n"
"<table>\n"
"\t<th>School</th>\n"
"\t<th>School Year</th>\n"
"\t<tr>\n"
"\t<td>San Roque Central Elementary School</td>\n"
"\t<td>2012-2013</td>\t\n"
"\t</tr>\n"
"\t<td>Davao City National High School</td>\n"
"\t<td>2016-2017</td>\n"
"  </tr>\n"
"  <tr>\n"
"  \t<td>Davao City National High School (Senior High) <br>\n"
"      Track/Strand: TVL (Animation/Programming)\n"
"  \t </td>\n"
"  \t<td>2018-2019</td>\n"
"  </tr>\n"
"</table>\n"
"\n"
"<h4>Accomplishments</h4>\n"
"<table>\n"
"\t<tr>\n"
"\t\t<td>NCll Passer in Animation</td></tr>\n"
"</table>\n"
"\n"
"\n"
"\n"
"</body>\n"
"</html>"};
ESP8266WebServer server(80);   //instantiate server at port 80 (http port)
 
String page = "";

void setup(void){

   
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
    server.send_P(200, "text/html", myhtml);
  });
  
  server.begin();
  Serial.println("Web server started!");
}
 
void loop(void){
  server.handleClient();
}
