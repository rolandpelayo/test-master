void setup(){
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  int x= analogRead(5);
  float y = x/7.30714285714;
  Serial.println((String)"Speed: "+ y);
  delay(500);
  if(y > 100){
    digitalWrite(13,HIGH);
  }
  else{
    digitalWrite(13,LOW);
  }
}
  