/* Arduino Temperature Warning LED
   by Gericko Maandig
   on September 11
*/

#define led_1 9
#define tempSensor A0

double temp;
int tempCelcius;
int timeSub;
int time;

void setup()
{
  Serial.begin(9600);
  pinMode(led_1, OUTPUT);
  pinMode(tempSensor, INPUT);
}

void loop()
{
  temp = analogRead(tempSensor);
  tempCelcius = temp * (4.88/10) - 50;
  //Serial.println(tempCelcius);
  timeSub = tempCelcius * 4;
  time = 620 - timeSub;
  //Serial.println(time);
  
  if(tempCelcius >= 25){
    digitalWrite(led_1, LOW); 
    delay(time);
    digitalWrite(led_1, HIGH);
  }else{
  	digitalWrite(led_1, LOW); 
  }
  
  delay(time);
}
