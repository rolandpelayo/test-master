/* First Arduino Program
   by <Rojien Mancao>
   on <08-19-20>
*/

void setup()
{
	pinMode(13, OUTPUT);
}

void loop()
{
	digitalWrite(13, HIGH);
	delay(1000);
	digitalWrite(13, LOW);
	delay(1000);
}