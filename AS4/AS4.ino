/*First Arduino Program
    by <Ree Johndave N. Dingos>
    on <August 25, 2020>
*/

int Movement = 0;

void setup()
{
  pinMode(2, INPUT);
  pinMode(11, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop()
{
  Movement = digitalRead(2);
  delay(2000); // Wait for 2000 millisecond(s)
  if (Movement == HIGH) {
    tone(11, 92, 500); // play tone 30 (F#2 = 92 Hz)
  } else {
    digitalWrite(11, LOW);
  }
  if (Movement == HIGH) {
    digitalWrite(10, HIGH);
  } else {
    digitalWrite(10, LOW);
  }
}