void setup(){
  pinMode(9, OUTPUT);
}
void loop(){
  int x=analogRead(A0);
  float y=x*(4.88/10)-50;
  if((y>=25)&&(y<=49 )){
    digitalWrite(9,HIGH);
    delay(1500);
    digitalWrite(9,LOW);
    delay(1500);
  }
  else if((y>=50)&&(y<=64)){
    digitalWrite(9,HIGH);
    delay(1000);
    digitalWrite(9,LOW);
    delay(1000);
  }
  else if((y>=65)&&(y<=79)){
    digitalWrite(9,HIGH);
    delay(500);
    digitalWrite(9,LOW);
    delay(500);
  }
  else if((y>=80)&&(y<=99)){
    digitalWrite(9,HIGH);
    delay(250);
    digitalWrite(9,LOW);
    delay(250);
  }
  else if(y>=100){
    digitalWrite(9,HIGH);
    delay(150);
    digitalWrite(9,LOW);
    delay(150);
  }
}