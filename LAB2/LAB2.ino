void setup()
{
  pinMode(13, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
  int sensorValue = analogRead (A0);
  double tempCelsius = sensorValue * (4.88/10)- 50;
  Serial.println(tempCelsius);
  delay(1);
  if(digitalRead(13)== A0){
    digitalWrite(7, HIGH);
  }
  else{
  digitalWrite(7, LOW);
  }
    if(digitalRead(13)== A0){
    digitalWrite(6, HIGH);
  }
  else{
  digitalWrite(6, LOW);
  }
    if(digitalRead(13)== A0){
    digitalWrite(5, HIGH);
  }
  else{
  digitalWrite(5, LOW);
  }
    if(digitalRead(13)== A0){
    digitalWrite(7, HIGH);
  }
  else{
  digitalWrite(7, LOW);
  }
    if(digitalRead(13)== A0){
    digitalWrite(4, HIGH);
  }
  else{
  digitalWrite(4, LOW);
  }
 
}