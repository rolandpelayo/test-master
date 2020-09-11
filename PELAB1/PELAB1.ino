

void setup()
{
  pinMode(13, OUTPUT);
 
}

void loop()
{
  int analogValue = analogRead(A5); 
    
  if (analogValue >= 0 && analogValue <=100){
  digitalWrite(13, LOW);       
  }
  else if(analogValue >=101 && analogValue <=1023){
  digitalWrite(13, HIGH);
  }
  delay(1000); // Wait for 1000 millisecond(s)
