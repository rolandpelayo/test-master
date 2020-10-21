//PRELIM
//REYNALDO PAGARAN

int piezo = 13;

void setup()
{
  Serial.begin(9600);
  pinMode(piezo,OUTPUT);
}

void loop(){
  
  int adcVal = analogRead(A5);
  int speed = adcVal * (140.0 / 1023.0);
  String kmh = " km/h";
  
  if(speed >= 100){
    alarmOn();
  }else{
  	alarmOff();
  }

  delay(1000);
  Serial.print(speed);
  Serial.print(kmh);
  Serial.println(); 

}

void alarmOn(){
  digitalWrite(piezo,HIGH);
}
void alarmOff(){
  digitalWrite(piezo,LOW);
}


 
