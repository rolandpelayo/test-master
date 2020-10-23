double data;
void setup() {
  pinMode(A0, INPUT);
  pinMode(2, OUTPUT);
}

void loop() {
  data = analogRead(A0);
  if (data > 1000) {
        digitalWrite(2, LOW);
      }
      else{
        digitalWrite(2, HIGH);
      }
}