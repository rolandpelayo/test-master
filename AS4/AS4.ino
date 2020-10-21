int inputPin = 2;
int pirState = LOW;
int val = 0;
int pinSpeaker = 11;
void setup() {
pinMode(inputPin, INPUT);
pinMode(pinSpeaker, OUTPUT);
Serial.begin(9600);
}
void loop(){
val = digitalRead(inputPin);
if (val == HIGH) {
playTone(300, 160);
delay(150);
if (pirState == LOW) {
Serial.println("Motion detected!");
pirState = HIGH;
}
} else {
playTone(0, 0);
delay(300);
if (pirState == HIGH){
Serial.println("Motion ended!");
pirState = LOW;
}
}
}
void playTone(long duration, int freq) {
duration *= 2000;
int period = (2.0 / freq) * 1000000;
long elapsed_time = 0;
while (elapsed_time < duration) {
digitalWrite(pinSpeaker,HIGH);
delayMicroseconds(period / 2);
digitalWrite(pinSpeaker, LOW);
delayMicroseconds(period / 2);
elapsed_time += (period);
}
}