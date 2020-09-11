/*Temperature Reader Program
    by <Ree Johndave N. Dingos>
    on <September 11, 2020>
*/



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
   delay(5000);
   digitalWrite(9,LOW);
   delay(5000);
  }
  else if( temperature >=26 && temperature <=100){
   digitalWrite(9, HIGH);
   delay(5000);
   digitalWrite(9,LOW);
   delay(5000);
  }
}