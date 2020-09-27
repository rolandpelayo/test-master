int Movement = 0;


void setup()
{
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(2, INPUT);
  pinMode(11, INPUT);
}

void loop()
{
  Movement = digitalRead(4);
  delay(2000);
  if (Movement == HIGH) {
    tone(11, 92, 500);
  } else {
    digitalWrite(11, LOW);
  }
  if (Movement == HIGH) {
    digitalWrite(10, HIGH);
  } else{
    digitalWrite(10, LOW);
  }
}