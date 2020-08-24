

int led3 = 13;
int led2 = 12;
int led4 = 11;
int led5 = 10;
int led6 = 9;
int led7 = 8;
int led8 = 7;

void setup()
{
    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(7, OUTPUT);
}

void loop()
{
    digitalWrite(13, HIGH);
	delay(1000);
	digitalWrite(13, LOW);
	delay(1000);
    digitalWrite(12, HIGH);
	delay(1000);
	digitalWrite(12, LOW);
	delay(1000);
    digitalWrite(11, HIGH);
	delay(1000);
	digitalWrite(11, LOW);
	delay(1000);
    digitalWrite(10, HIGH);
	delay(1000);
	digitalWrite(10, LOW);
	delay(1000);
    digitalWrite(9, HIGH);
	delay(1000);
	digitalWrite(9, LOW);
	delay(1000);
    digitalWrite(8, HIGH);
	delay(1000);
	digitalWrite(8, LOW);
	delay(1000);
    digitalWrite(7, HIGH);
	delay(1000);
	digitalWrite(7, LOW);
	delay(1000);
}