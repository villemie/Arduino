#include <Process.h>
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(analogRead(A0)>1020){
    Serial.println("111");
    
    delay(500);
    }
   else delay(50);
   
}
