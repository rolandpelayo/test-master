//PRELIM
//REYNALDO PAGARAN

void setup()
{
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  
  int sensor = analogRead(A0);
  double temp = sensor * (4.88/10) - 50;
  int RoundedTemp = round(temp);
  
  
  
  if(RoundedTemp >= 25 && RoundedTemp <= 34){
    digitalWrite(9, HIGH);
    delay(1500);
    digitalWrite(9, LOW);
    delay(1500);
  }else if(RoundedTemp >= 35 && RoundedTemp <= 44){
    digitalWrite(9, HIGH);
    delay(1300);
    digitalWrite(9, LOW);
    delay(1300);
  }else if(RoundedTemp >= 45 && RoundedTemp <= 54){
    digitalWrite(9, HIGH);
    delay(1100);
    digitalWrite(9, LOW);
    delay(1100);
  }else if(RoundedTemp >= 55 && RoundedTemp <= 64){
    digitalWrite(9, HIGH);
    delay(900);
    digitalWrite(9, LOW);
    delay(900);
  }else if(RoundedTemp >= 65 && RoundedTemp <= 74){
    digitalWrite(9, HIGH);
    delay(700);
    digitalWrite(9, LOW);
    delay(700);
  }else if(RoundedTemp >= 75 && RoundedTemp <= 84){
    digitalWrite(9, HIGH);
    delay(500);
    digitalWrite(9, LOW);
    delay(500);
  }else if(RoundedTemp >= 85 && RoundedTemp <= 94){
    digitalWrite(9, HIGH);
    delay(300);
    digitalWrite(9, LOW);
    delay(300);
  }else if(RoundedTemp >= 95 && RoundedTemp <= 100){
    digitalWrite(9, HIGH);
    delay(100);
    digitalWrite(9, LOW);
    delay(100);
  }else{
  	digitalWrite(9, LOW);
  }
  
 
  Serial.println(RoundedTemp);
}