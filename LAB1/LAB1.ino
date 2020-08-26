void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  digitalWrite(13, HIGH);
  digitalWrite(5, HIGH);
  delay(6000); // Wait for 6000 millisecond(s) or 6 seconds
  
  digitalWrite(13, LOW);
  digitalWrite(5, LOW);
  delay(500); // Wait for 500 millisecond(s) or 0.5 second
 
  digitalWrite(12, HIGH);
  digitalWrite(6, HIGH);
  delay(5000); // Wait for 1000 millisecond(s) or 5 seconds
  
  digitalWrite(12, LOW);
  digitalWrite(6, LOW);
  delay(500); // Wait for 1000 millisecond(s) or 0.5 second
  
  digitalWrite(11, HIGH);
  digitalWrite(7, HIGH);
  delay(6000); // Wait for 1000 millisecond(s) or 6 seconds
  
  digitalWrite(11, LOW);
  digitalWrite(7, LOW);
  delay(500); // Wait for 1000 millisecond(s) or 0.5 second
  
}
