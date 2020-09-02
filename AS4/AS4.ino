int objDetected = 0;

void setup()
{
  pinMode(2, INPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  objDetected = digitalRead(2);
  
  if(objDetected == HIGH)
  {
    digitalWrite(11, HIGH);
    delay(2000);
  }
  else
  {
    digitalWrite(11, LOW);
  }
}