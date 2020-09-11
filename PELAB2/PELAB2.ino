void setup(){
pinMode(9, OUTPUT);
Serial.begin(9600);
}

void loop(){

int sensorValue = analogRead(A0);
double tempCelsius = sensorValue * (4.88/10) - 50;
  
  if((tempCelsius >= 25) && (tempCelsius <= 39)){
    digitalWrite(9, HIGH);
    delay(1500);
    digitalWrite(9, LOW);
    delay(1500);
  }else if((tempCelsius >= 40) && (tempCelsius <= 54)){
    digitalWrite(9, HIGH);
    delay(1250);
    digitalWrite(9, LOW);
    delay(1250);
  }else if((tempCelsius >= 55) && (tempCelsius <= 69)){
    digitalWrite(9, HIGH);
    delay(1000);
    digitalWrite(9, LOW);
    delay(1000);
  }else if((tempCelsius >= 70) && (tempCelsius <= 84)){
    digitalWrite(9, HIGH);
    delay(750);
    digitalWrite(9, LOW);
    delay(750);
  }else if((tempCelsius >= 85) && (tempCelsius <= 99)){
    digitalWrite(9, HIGH);
    delay(500);
    digitalWrite(9, LOW);
    delay(500);
  }else if(tempCelsius >= 100){
    digitalWrite(9, HIGH);
    delay(250);
    digitalWrite(9, LOW);
    delay(250);
  }

Serial.println(tempCelsius);
}