/* Second Arduino Program (Strobes Light)
   by Nollan Jay D. Galicia
   on August 25, 2020
*/

void setup()
{
	pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode( 9, OUTPUT);
    pinMode( 8, OUTPUT);
    pinMode( 7, OUTPUT);
}

void loop()
{
  /* Delay adjusted to 200ms to all seven LED lights to create stobe effect */
  	 
	digitalWrite(13, HIGH);
	delay(200);
	digitalWrite(13, LOW);
	delay(200);

    
    digitalWrite(12, HIGH);
	delay(200);
	digitalWrite(12, LOW);
	delay(200);

    digitalWrite(11, HIGH);
	delay(200);
    digitalWrite(11, LOW);
	delay(200);

    digitalWrite(10, HIGH);
	delay(200);
    digitalWrite(10, LOW);
	delay(200);

    digitalWrite(9, HIGH);
	delay(200);
    digitalWrite(9, LOW);
	delay(200);

    digitalWrite(8, HIGH);
	delay(200);
    digitalWrite(8, LOW);
	delay(200);

    digitalWrite(7, HIGH);
	delay(200);
    digitalWrite(7, LOW);
	delay(200);
}
