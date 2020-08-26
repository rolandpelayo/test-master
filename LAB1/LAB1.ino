/* LAB Activity #1
   by Karl Winston Collantes
   on August 26, 2020
*/

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop()
{
  digitalWrite(11, 1);
  digitalWrite(4, 1);
  delay(8000);
  digitalWrite(11, 0);
  digitalWrite(12, 1);
  delay(2000);
  digitalWrite(12, 0);
  digitalWrite(4, 0);
  digitalWrite(13, 1);
  digitalWrite(2, 1);
  delay(8000);
  digitalWrite(2, 0);
  digitalWrite(3, 1);
  delay(2000);
  digitalWrite(3, 0);
  digitalWrite(13, 0);
}