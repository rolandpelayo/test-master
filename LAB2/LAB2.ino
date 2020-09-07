/* Arduino 40 Degrees Celcius Alarm
   by Gericko Maandig
   on September 7
*/

//Pin Led
int Led_1 = 7;
int Led_2 = 6;
int Led_3 = 5;
int Led_4 = 4;

//Speaker Pin
int Speaker_1 = 13;

//Values
double tempCelcius;
double sensorValue;

//TMP36 Sensor on pin A0

void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(Speaker_1, OUTPUT);
  pinMode(Led_1, OUTPUT);
  pinMode(Led_2, OUTPUT);
  pinMode(Led_3, OUTPUT);
  pinMode(Led_4, OUTPUT);
}

void loop()
{
  sensorValue = analogRead(A0);
  tempCelcius = sensorValue * (4.88/10) - 50; 
  //Serial.println();
  //Serial.println(tempCelcius);
  //Serial.println(sensorValue);
  //Serial.println();
  
  if(tempCelcius >= 10){
    digitalWrite(Led_1, HIGH);
  } else if(tempCelcius < 10){
    digitalWrite(Led_1, LOW);
  }
  
  if(tempCelcius >= 20){
    digitalWrite(Led_2, HIGH);
  } else if(tempCelcius < 20){
    digitalWrite(Led_2, LOW);
  }
  
  if(tempCelcius >= 30){
    digitalWrite(Led_3, HIGH);
  } else if(tempCelcius < 30){
    digitalWrite(Led_3, LOW);
  }
  
  if (tempCelcius >= 40){
    digitalWrite(Led_4, HIGH);
    digitalWrite(Speaker_1, HIGH);
  } else if(tempCelcius < 40){
    digitalWrite(Led_4, LOW);
    digitalWrite(Speaker_1, LOW);
  }

  delay(1);
}