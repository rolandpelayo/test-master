/* ASSIGNMENT 4
   by Gericko Maandig
   on September 1
*/

int sensor = 2;
int speaker = 11;

int sensorState = 0;

void setup()
{
  pinMode(sensor, INPUT);
  pinMode(speaker, OUTPUT);
}

void loop()
{
  sensorState = digitalRead(sensor);
  if (sensorState == HIGH) {
  	digitalWrite(speaker, HIGH);
  } else {
    digitalWrite(speaker, LOW);
  }
}