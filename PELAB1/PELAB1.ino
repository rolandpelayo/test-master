/* Arduino Program (Speed Indicator)
   by Nollan Jay D. Galicia
   on September 11, 2020
*/

void setup()
{
  
  pinMode(A5, INPUT); // Potentiometer
  pinMode(13,OUTPUT); // LED
  
  Serial.begin(9600);
}

void loop()
{
 
  int SensorValue = analogRead(A5);
  float km = (1023/140); // 140 km/h represents an ADC value of 1023 so just devide it

  int speed = SensorValue/km; //then devide the SensorValue of the potentiometer to the reult of the variable km
  
  Serial.println(speed);
  delay(1); 
  
  if(SensorValue >= 730)
  {
    digitalWrite(13,HIGH);
  }
  else
  {
    digitalWrite(13,LOW);
  }
}