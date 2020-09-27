void setup()
{
  pinMode(5,  OUTPUT);
  pinMode(6,  OUTPUT);
  pinMode(7,  OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(7,  LOW);
  digitalWrite(6,  HIGH);
  digitalWrite(5,  LOW);
  delay(2000); // Wait for 1000 millisecond(s)
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(7,  HIGH);
  digitalWrite(6,  LOW);
  digitalWrite(5,  HIGH);
  delay(2000); // Wait for 1000 millisecond(s)
}