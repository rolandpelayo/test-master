/*First Arduino Program
by Jaymark Algabre
on August 20, 2020
*/

void setup()
{
	pinMODE(13, OUTPUT);
}

void loop()
{
	digitalWrite(13, HIGH);
	delay(1000);
	digitalWrite(13, LOW);
	delay(1000);
}
