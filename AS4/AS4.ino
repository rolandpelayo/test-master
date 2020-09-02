int buttonState=0;
void setup()
{
  pinMode(11, OUTPUT);
  pinMode(2, INPUT);
}
void loop()
{
  buttonState = digitalRead(2);
  if (buttonState == HIGH){
    digitalWrite(11, HIGH);
  } else{
    digitalWrite(11, LOW);
  }
  delay(10);
 }