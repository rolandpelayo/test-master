/* Arduino Traffic Lights
   by Gericko Maandig
   on August 26
*/

void setup()
{
  for (int j=10; j>=5; j--){
    pinMode(j, OUTPUT);
  }
}

void loop()
{
  int TL1_Green_Time = 10000;
  int TL2_Green_Time = 10000;
  int TL1_to_TL2_Delay = 8000;
  int TL2_to_TL1_Delay = 8000;
  
  digitalWrite(5, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);
  delay(5000);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
  delay(TL1_Green_Time); // Green time for the 1st lane
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  delay(5000);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  delay(TL1_to_TL2_Delay);
  
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  delay(5000);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  delay(TL2_Green_Time); // Green time for 2nd lane
  digitalWrite(7, LOW);
  digitalWrite(6, HIGH);
  delay(5000);
  digitalWrite(6, LOW);
  digitalWrite(5, HIGH);
  delay(TL2_to_TL1_Delay);
}