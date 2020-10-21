void setup()
{
  for(int a = 13; a > 7; a--){
    pinMode(a, OUTPUT);
  }
  
}

void loop()
{
  digitalWrite(13, HIGH);
  digitalWrite(8, HIGH);
  delay(8000);
  digitalWrite(8, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(9, HIGH);
  delay(2000);
  digitalWrite(9, LOW);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  delay(8000);
  digitalWrite(9, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  delay(2000);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  digitalWrite(12, LOW);
}
