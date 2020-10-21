int piezo = 13;

void setup()
{
  Serial.begin(9600);
  pinMode(piezo, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
  int sensorValue = analogRead(A0);
  double tempCelsius = sensorValue * (4.88/10)-50;
  
  int RoundedTemp = round(tempCelsius);

  if (RoundedTemp > 9 && RoundedTemp < 20)
  {
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
  	digitalWrite(7, HIGH);
    playAlarm(0, 0);
  }else if(RoundedTemp > 19 && RoundedTemp < 30)
  {
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
  	digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    playAlarm(0, 0);
  }else if(RoundedTemp > 29 && RoundedTemp < 40)
  {
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
  	digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    playAlarm(0, 0);
  }else if(RoundedTemp > 39)
  {
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
  	digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    playAlarm(300, 160);
  }else{
  	digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    playAlarm(0, 0);
  }
}

void playAlarm(long duration, int freq) {
  duration *= 2000;
  int period = (2.0 / freq) * 1000000;
  long elapsed_time = 0;
  while (elapsed_time < duration) {
  digitalWrite(piezo,HIGH);
  delayMicroseconds(period / 2);
  digitalWrite(piezo, LOW);
  delayMicroseconds(period / 2);
  elapsed_time += (period);
  }
 }