/* Arduino Program (Temperature Indicator)
   by Nollan Jay D. Galicia
   on September 11, 2020
*/

void setup()
{
  
  pinMode( 9, OUTPUT);

  pinMode(A0, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  
  int sensorValue = analogRead(A0);
  double tempCelsius = sensorValue * (4.88/10) - 50; 
  Serial.println(tempCelsius);
  delay(1);

  if (tempCelsius < 25) {
    digitalWrite(9, HIGH);
    delay (4000);
    digitalWrite(9, LOW);
    delay (4000);
  }
  else if(tempCelsius >= 25 && tempCelsius < 30) {
    digitalWrite(9, HIGH);
    delay (3000);
    digitalWrite(9, LOW);
    delay (3000);
  }
  else if (tempCelsius >= 30 && tempCelsius < 40){
  	digitalWrite(9, HIGH);
  	delay (2000);
    digitalWrite(9, LOW);
  	delay (2000);
    
  }
  else if (tempCelsius >= 40 && tempCelsius < 50){
    digitalWrite(9, HIGH);
    delay (1500);
    digitalWrite(9, LOW);
    delay (1500);
  }
  else if (tempCelsius >= 50 && tempCelsius < 60 ){
    digitalWrite(9, HIGH);
    delay (1000);
    digitalWrite(9, LOW);
    delay (1000);
  }
  else if (tempCelsius >= 60 && tempCelsius < 70 ){
    digitalWrite(9, HIGH);
    delay (800);
    digitalWrite(9, LOW);
    delay (800);
  }
  else if (tempCelsius >= 70 && tempCelsius < 80 ){
    digitalWrite(9, HIGH);
    delay (600);
    digitalWrite(9, LOW);
    delay (600);
  }
  else if (tempCelsius >= 80 && tempCelsius < 90 ){
    digitalWrite(9, HIGH);
    delay (400);
    digitalWrite(9, LOW);
    delay (400);
  }
  else if (tempCelsius >= 90 && tempCelsius < 100 ){
    digitalWrite(9, HIGH);
    delay (200);
    digitalWrite(9, LOW);
    delay (200);
  }
  else if (tempCelsius > 100 ){
    digitalWrite(9, HIGH);
    delay (100);
    digitalWrite(9, LOW);
    delay (100);
  }
}