/* Prelim Laboratory Examination
   by PRECIOUS ENICA CEPE
   on SEPTEMBER 11, 2020
*/


int potentiometerPin = A5;
int buzzerPin = 13;

void setup()
{
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int SensorValue = analogRead(potentiometerPin);
  double speedometer = SensorValue / 7.30;
  
  Serial.println(speedometer);
  delay(100);
  
  //RIGHT TO LEFT
  if (SensorValue >= 600) 
  {
    digitalWrite(buzzerPin, HIGH);
  }
  else
  {
    digitalWrite(buzzerPin, LOW);
  }
}
