/* Prelim Laboratory Examination
   by PRECIOUS ENICA CEPE
   on SEPTEMBER 11, 2020
*/


int sensorPin = 0;

void setup()
{
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int sensorValue = analogRead(sensorPin);
  double tempCelsius = sensorValue * (4.88/10) - 50;
  
  if((tempCelsius >= 25) && (tempCelsius <= 35)){
    digitalWrite(9, HIGH);
    delay(1000);
    digitalWrite(9, LOW);
    delay(1500);
  }
  else if((tempCelsius >= 36) && (tempCelsius <= 45)){
    digitalWrite(9, HIGH);
    delay(1000);
    digitalWrite(9, LOW);
    delay(1300);
  }
  else if((tempCelsius >= 46) && (tempCelsius <= 55)){
    digitalWrite(9, HIGH);
    delay(1000);
    digitalWrite(9, LOW);
    delay(1000);
  }
  else if((tempCelsius >= 56) && (tempCelsius <= 65)){
    digitalWrite(9, HIGH);
    delay(800);
    digitalWrite(9, LOW);
    delay(800);
  }
  else if((tempCelsius >= 66) && (tempCelsius <= 75)){
    digitalWrite(9, HIGH);
    delay(500);
    digitalWrite(9, LOW);
    delay(500);
  }
  else if((tempCelsius >= 76) && (tempCelsius <= 85)){
    digitalWrite(9, HIGH);
    delay(300);
    digitalWrite(9, LOW);
    delay(300);
  }
  else if((tempCelsius >= 86) && (tempCelsius <= 100)){
    digitalWrite(9, HIGH);
    delay(100);
    digitalWrite(9, LOW);
    delay(100);
  }
}
