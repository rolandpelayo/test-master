/*Speedometer Program
    by <Ree Johndave N. Dingos>
    on <September 11, 2020>
*/



#define piezo_1 13
#define accelerometer A5

double meterValue;
int speed;

void setup()
{
	pinMode (piezo_1. OUTPUT);
  	pinMode (accelerometer, INPUT);
  	Serial.begin(9600);
}

void loop() 
{
	mterValue = analogRead (accelerometer);
  	speed = (meterValue/1023) * 140;
 	Serial.print("km/h: ");
  	Serial.println(speed);
  
  if (speed >= 100{
    digitalWrite(piezo_1, HIGH);
  }else{
    digitalWrite(piezo_1, LOW);
  }  
}