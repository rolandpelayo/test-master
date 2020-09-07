
void setup()
{
  pinMode(A0, INPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int sensorValue = analogRead(A0);
  float tempCelsius = sensorValue * (4.88/10) - 50; 
  Serial.println(tempCelsius);
  
  if(tempCelsius <= 10){
  digitalWrite(7, HIGH);
   }
  else if(tempCelsius >= 40){
   digitalWrite(7, HIGH);
   digitalWrite(6, HIGH);
   digitalWrite(5, HIGH);
   digitalWrite(4, HIGH);
   digitalWrite(13, HIGH);
  }
 delay(1000);
}