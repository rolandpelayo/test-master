int green=13;
 int yellow=12;
 int red=11;
 int green2=10;
 int yellow2=9;
 int red2=8;

 void setup() {
  pinMode(green, OUTPUT);
  pinMode(yellow , OUTPUT);
  pinMode(red , OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(yellow2 , OUTPUT);
  pinMode(red2 , OUTPUT);
  digitalWrite(green ,HIGH);
  digitalWrite(yellow ,HIGH);
  digitalWrite(red ,HIGH);
  digitalWrite(green2 ,HIGH);
  digitalWrite(yellow2 ,HIGH);
  digitalWrite(red2 ,HIGH);
  delay(2000);
  digitalWrite(green ,LOW);
  digitalWrite(yellow ,LOW);
  digitalWrite(red ,LOW);
  digitalWrite(green2 ,LOW);
  digitalWrite(yellow2 ,LOW);
  digitalWrite(red2 ,LOW);
 }
 

 void loop() {
  digitalWrite(green ,HIGH);
  digitalWrite(red2 ,HIGH);
  delay(15000); 
  digitalWrite(green ,LOW);
  digitalWrite(yellow ,HIGH);
  delay(5000); 
  digitalWrite(yellow ,LOW);
  digitalWrite(red ,HIGH);
  digitalWrite(red2 ,LOW);
  digitalWrite(green2 ,HIGH);
  delay(15000); 
  digitalWrite(green2 ,LOW);
  digitalWrite(yellow2 ,HIGH);
  delay(5000); 
  digitalWrite(red ,LOW);
  digitalWrite(yellow2 ,LOW);
 }
