int speaker = 11;
int sensor = 2;

void setup()
{
pinMode(11, OUTPUT);
pinMode(2, INPUT);
}

void loop()
{
sensor = digitalRead(2);
if(sensor == HIGH){
digitalWrite(11, HIGH);
delay(2000);
}else{
digitalWrite(11, LOW);
}
}