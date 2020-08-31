
void setup(){
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
}

void loop(){
  for(int x=11; x>=7;x--){
    digitalWrite(x,HIGH);
    delay(100);
    digitalWrite(x,LOW);
    delay(100);
  }
}
