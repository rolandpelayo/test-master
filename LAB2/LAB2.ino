/* Lab Activity #2
   by Karl Winston Collantes
   on September 8, 2020
*/

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int sensorValue = analogRead(A0);
  double tempCelsius = sensorValue * (4.88/10) - 50;
  Serial.println(tempCelsius);
  delay(1);
  
  if(tempCelsius >= 10){
    digitalWrite(7, HIGH);
  }
  else{
    digitalWrite(7, LOW);
  }
  if(tempCelsius >= 20){
    digitalWrite(6, HIGH);
  }
  else{
    digitalWrite(6, LOW);
  }
  if(tempCelsius >= 30){
    digitalWrite(5, HIGH);
  }
  else{
    digitalWrite(5, LOW);
  }
  if(tempCelsius >= 40){
    digitalWrite(4, HIGH);
    digitalWrite(13, HIGH);
  }
  else{
    digitalWrite(4, LOW);
    digitalWrite(13, LOW);
  }
}