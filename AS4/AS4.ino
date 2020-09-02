/* Arduino Program ( Object Detector)
   by Nollan Jay D. Galicia
   on September 02, 2020
*/

int buttonState = 0;

void setup()
{
  // for PIR sensor
  pinMode(2, INPUT);
  
  // for Piezo speaker
  pinMode(11, OUTPUT);
}

void loop()
{
  buttonState = digitalRead(2);
  
  if(buttonState == HIGH)
  {
    digitalWrite(11, LOW);
    delay(2000);
  }
  else
  {
    digitalWrite(11, HIGH);
  }
}