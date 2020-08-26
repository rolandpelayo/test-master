
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
  digitalWrite(12, HIGH);
  digitalWrite(6, HIGH);
  delay(3000); // Wait for 1000 millisecond(s)
 
  digitalWrite(12, LOW);
  digitalWrite(6, LOW);
  digitalWrite(13, HIGH);
  digitalWrite(7, HIGH);
  delay(3000); // Wait for 1000 millisecond(s)
  
  
  digitalWrite(13, LOW);
  digitalWrite(7, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(6, HIGH);
  delay(3000); // Wait for 1000 millisecond(s)
  
   digitalWrite(12, LOW);
   digitalWrite(6, LOW);
   digitalWrite(11, HIGH);
   digitalWrite(5, HIGH);
   delay(3000); // Wait for 1000 millisecond(s)
   digitalWrite(5, LOW);
   digitalWrite(11, LOW);
  
}