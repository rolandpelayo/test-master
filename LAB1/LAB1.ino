/* Arduino Program (Two way Traffic Light)
   by Nollan Jay D. Galicia
   on August 26, 2020
*/

void setup(){
    // Traffic light one
    pinMode(7, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(5, OUTPUT);

    // Traffic light two
    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
}
void loop(){
    changeLights();
    delay(4000);
}
void changeLights(){
    // turn both yellows on 
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(12, HIGH);
    delay(4000);

    // turn both yellows off, and opposite green and red
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    digitalWrite(11, HIGH);
    delay(8000);

    // both yellows on again
    digitalWrite(6, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(7, LOW);
    delay(4000);

    // turn both yellows off, and opposite green and red
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    delay(4000);

}