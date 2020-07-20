int timer = 100;
void setup() {
  for (int thisPin = 6; thisPin < 13; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }

}

void loop() {
   for (int thisPin = 6; thisPin < 12; thisPin++) {
    // turn the pin on:
    digitalWrite(thisPin, HIGH);
    delay(timer);
    // turn the pin off:
    digitalWrite(thisPin, LOW);
  }
  
  // loop from the highest pin to the lowest:
  for (int thisPin = 12; thisPin >= 6; thisPin--) {
    // turn the pin on:
    digitalWrite(thisPin, HIGH);
    delay(timer);
    // turn the pin off:
    digitalWrite(thisPin, LOW);
  }

}
