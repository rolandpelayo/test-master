void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int sensorValue = analogRead(5);
  double speedoMeter = sensorValue / 7.30714285714; //1023 divided by 140
  
  Serial.println((String)"Speed: " + speedoMeter);
  delay(500);
  
  if(speedoMeter > 100){
    digitalWrite(13, HIGH);
  }else{
    digitalWrite(13, LOW);
  }
}