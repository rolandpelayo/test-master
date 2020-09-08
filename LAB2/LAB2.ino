void setup(){
  pinMode(13, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
}
void loop(){
   int x=analogRead(A0);
  double y = x * (4.88/10) - 50;
  Serial.println(y);
  delay(1);
  if(y >= 10){
    digitalWrite(7, HIGH);
  }
  else{
    digitalWrite(7, LOW);
  }
  if(y >= 20){
    digitalWrite(6, HIGH);
  }
  else{
    digitalWrite(6, LOW);
  }
  if(y >= 30){
    digitalWrite(5, HIGH);
  }
  else{
    digitalWrite(5, LOW);
  }
  if(y >= 40){
    digitalWrite(4, HIGH);
    digitalWrite(13, HIGH);
  }
  else{
    digitalWrite(4, LOW);
    digitalWrite(13, LOW);
  }
}