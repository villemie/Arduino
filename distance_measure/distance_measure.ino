//Uses ezButton library https://arduinogetstarted.com/tutorials/arduino-button-library
#include <ezButton.h>
const int trigPin = 2;
const int echoPin = 3;
ezButton btn(4); //Pin 4 is connected to button which triggers measuring
float duration, distance;

void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
btn.loop();
if(btn.isPressed()){
    measure();     
  }
   delay(10);
}

void measure(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  distance = ((int) (distance * 10.0 + 0.5) / 10.0);
  Serial.print("Distance: ");
  Serial.println(distance,1);
  delay(10);
  }
