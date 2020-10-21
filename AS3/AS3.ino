/* Arduino Program
   by Reynaldo Pagaran
   on 05/09/20
*/

void setup()
{
   for(int i = 13; i > 6; i--){
   pinMode(i, OUTPUT);
 }
}

void loop()
{ 
  for(int a = 13; a > 6; a--){
  	digitalWrite(a, HIGH);
	delay(1000);
	digitalWrite(a, LOW);
	delay(1000);
  }
}