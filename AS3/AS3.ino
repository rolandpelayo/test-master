void setup(){
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
}

void loop(){
  
for (int x=13; x>=7;x--){
  	digitalWrite(x,HIGH);
    delay(100);
    digitalWrite(x,LOW);
    delay(100);
  }
}