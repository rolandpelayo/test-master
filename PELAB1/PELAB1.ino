/* Arduino OverSpeeding Alert
   by Gericko Maandig
   on September 11
*/

#define speaker_1 13
#define accelerometer A5

double meterValue;
int speed;

void setup()
{
  pinMode(speaker_1, OUTPUT);
  pinMode(accelerometer, INPUT);
  Serial.begin(9600);
}

void loop()
{
  meterValue = analogRead(accelerometer);
  speed = (meterValue/1023) * 140; // 1023 to 140
  Serial.print("km/h: ");
  Serial.println(speed);
  
  if(speed >= 100){
    digitalWrite(speaker_1, HIGH);
  }else{
    digitalWrite(speaker_1, LOW);
  }
}