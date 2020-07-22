void setup() {
  Serial.begin(9600);
  }

void loop() {
  int pressed = press();
  if(pressed != -1){
    Serial.print(pressed);
    Serial.print("\n");
  }
  
    
}
int press(){
  int SV = 0;//Sensor value
  int nextHigh = 0;
  int okHigh = 0;
  int backHigh = 0;
  for (int i = 0; i <= 10; i++) {
    SV = analogRead(A0);
    if(SV > nextHigh)nextHigh = SV;
    SV = analogRead(A1);
    if(SV > okHigh)okHigh = SV;
    SV = analogRead(A2);
    if(SV > backHigh)backHigh = SV;
    delay(50);
  }
  int pressed = 0;
  int highest = 0;
  if(nextHigh > okHigh && nextHigh > backHigh){
    pressed = 0;
    highest = nextHigh;
    }
  if(okHigh > nextHigh && okHigh > backHigh){
    pressed = 1;
    highest = okHigh;
    }
  if(backHigh > okHigh && backHigh > nextHigh){
    pressed = 2;
    highest = backHigh;
    }

    if(highest > 1020){
      /*
      Serial.print("Painoit "); Serial.print(pressed);
      Serial.print(". Volttimäärät: next:"); Serial.print(nextHigh);
      Serial.print(" ok: ");Serial.print(okHigh);Serial.print(" back: ");
      Serial.print(backHigh);Serial.print("\n");
      */
      return pressed;
      delay(500);
    }
    return -1;
}
