int timer = 100;
void setup() {
  for (int thisPin = 6; thisPin < 13; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }

}

void loop() {
   for (int thisPin = 6; thisPin < 13; thisPin++) {
    // turn the pin on:
    digitalWrite(thisPin, HIGH);
    delay(timer);
    // turn the pin off:
    if(thisPin-2 > 5){
      digitalWrite(thisPin-2, LOW);
    }
  }
  delay(timer);
  digitalWrite(11, LOW);
  delay(timer);
    // loop from the highest pin to the lowest:
  for (int thisPin = 12; thisPin >= 6; thisPin--) {
    // turn the pin on:
    digitalWrite(thisPin, HIGH);
    delay(timer);
    // turn the pin off:
    if(thisPin+2 < 13){
      digitalWrite(thisPin+2, LOW);
    }
    
  }
  delay(timer);
  digitalWrite(7, LOW);
  delay(timer);

}
