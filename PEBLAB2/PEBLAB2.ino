void setup()
{
  pinMode(9, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}
void loop()
{
  int SensorValue = analogRead(A0);
  float temperature = SensorValue * (4.88/10) - 50; 
  Serial.println(temperature);
  if(temperature >=0 && temperature <=25){
   digitalWrite(9, HIGH);
   delay(3000);
   digitalWrite(9,LOW);
   delay(3000);
  }
  else if( temperature >=26 && temperature <=100){
   digitalWrite(9, HIGH);
   delay(1000);
   digitalWrite(9,LOW);
   delay(1000);
  }
}