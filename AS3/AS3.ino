/* Arduino Strobe Lights
   by Gericko Maandig
   on August 24
*/

void setup()
{
  for(int j = 13; j>=7; j--){
  	pinMode(j, OUTPUT);
  }
}

void loop()
{
  for(int j = 13; j>=7; j--){
    digitalWrite(j, HIGH);
  	delay(1000); // Wait for 1000 millisecond(s)
  	digitalWrite(j, LOW);
  }
}