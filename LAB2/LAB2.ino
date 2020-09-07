/* Arduino Program (Temperature Indicator)
   by Nollan Jay D. Galicia
   on September 07, 2020
*/

void setup()
{
  
  pinMode( 7, OUTPUT);
  pinMode( 6, OUTPUT);
  pinMode( 5, OUTPUT);
  pinMode( 4, OUTPUT);

  pinMode(A0, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  
  int sensorValue = analogRead(A0);
  double tempCelsius = sensorValue * (4.88/10) - 50; 
  Serial.println(tempCelsius);
  delay(1);

  if (tempCelsius < 10) {
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(13,LOW);
  }
  else if(tempCelsius >= 10 && tempCelsius < 20) {
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(13, LOW);
  }
  else if (tempCelsius >= 20 && tempCelsius < 30){
  	digitalWrite(7, HIGH);
  	digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(13,LOW);
  }
  else if (tempCelsius >= 30 && tempCelsius < 40){
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
  	digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(13,LOW);
  }
  else if (tempCelsius >= 40){
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
  	digitalWrite(4, HIGH);
    digitalWrite(13, HIGH);
  }
  
}