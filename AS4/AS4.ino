/* ASSIGNMENT #4
   by PRECIOUS ENICA CEPE
   on SEPTEMBER 2, 2020
*/

void setup() {

  pinMode(2, INPUT); //PIR Sensor as INPUT
  pinMode(11, OUTPUT); // Piezo Speaker 11 as OUTPUT

}

void loop() {

  if (digitalRead(2) == HIGH){
    digitalWrite(11, HIGH);
    delay(2000); // 2 seconds
  }
  else {
    digitalWrite(11, LOW);
  }
}
