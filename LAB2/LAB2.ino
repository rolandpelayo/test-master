/* LAB ACTIVITY #2
   by PRECIOUS ENICA CEPE
   on SEPTEMBER 7, 2020
*/


int baselineTemp = 0;
int celsius = 0;
int fahrenheit = 0;
int BUZZER = 13;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);

  pinMode(BUZZER,OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT); 
}

void loop()
{
  // set threshold temperature to activate LEDs
  baselineTemp = 11;
  // measure temperature in Celsius
  celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  
  // convert to Fahrenheit
  fahrenheit = ((celsius * 9) / 5 + 32);
  Serial.print(celsius);
  Serial.print(" C, ");
  Serial.print(fahrenheit);
  Serial.println(" F");
  
   if (celsius < baselineTemp) {
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(BUZZER, LOW); // turn off Piezo Buzzer
  }
  if (celsius >= baselineTemp && celsius <= baselineTemp + 10) {
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(BUZZER, LOW); // turn off Piezo Buzzer
  }
  if (celsius >= baselineTemp + 10 && celsius <= baselineTemp + 20) {
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(BUZZER, LOW); // turn off Piezo Buzzer
  }
  if (celsius >= baselineTemp + 20 && celsius <= baselineTemp + 30) {
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(BUZZER, LOW); // turn off Piezo Buzzer
  }
  if (celsius >= baselineTemp + 30) {
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(BUZZER, HIGH); // turn on Piezo Buzzer
  }
  delay(1000); // Wait for 1000 millisecond(s)
}
