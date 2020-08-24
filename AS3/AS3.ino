/* Assignment #3 - Arduino Strobe Lights
   by Karl Winston Collantes
   on 08/24/2020
*/

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop()
{
  //FOR loop for pins 13 to 7
  for (int i=13; i>=7; i--)
  {
  	digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
    delay(100);
  }
}