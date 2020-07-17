#include <Morse.h>
Morse morse(13);
void setup() {

}

void loop() {
  String word = "TESTI";
  for(char x: word){
    alphabet((int)x);
    delay(2000);
  }
  delay(5000);
  
}

void alphabet(int letter){
  switch (letter){
    case 65: //A
    morse.dot();morse.dash();
    break;
    case 66: //B
    morse.dash();morse.dot();morse.dot();morse.dot();
    break;
    case 67: //C
    morse.dash();morse.dot();morse.dash();morse.dot();
    break;
    case 68: //D
    morse.dash();morse.dot();morse.dot();
    break;
    case 69: //E
    morse.dot();
    break;
    case 70: //F
    morse.dot();morse.dot();morse.dash();morse.dot();
    break;
    case 71: //G
    morse.dash();morse.dash();morse.dot();
    break;
    case 72: //H
    morse.dot();morse.dot();morse.dot();morse.dot();
    break;
    case 73: //I
    morse.dot();morse.dot();
    break;
    case 74: //J
    morse.dot();morse.dash();morse.dash();morse.dash();
    break;
    case 75: //K
    morse.dash();morse.dot();morse.dash();
    break;
    case 76: //L
    morse.dot();morse.dash();morse.dot();morse.dot();
    break;
     case 77: //M
    morse.dash();morse.dash();
    break;
    case 78: //N
    morse.dash();morse.dot();
    break;
    case 79: //O
    morse.dash();morse.dash();morse.dash();
    break;
    case 80: //P
    morse.dot();morse.dash();morse.dash();morse.dot();
    break;
    case 81: //Q
    morse.dash();morse.dash();morse.dot();morse.dash();
    break;
    case 82: //R
    morse.dot();morse.dash();morse.dot();
    break;
     case 83: //S
    morse.dot();morse.dot();morse.dot();
    break;
    case 84: //T
    morse.dash();
    break;
    case 85: //U
    morse.dot();morse.dot();morse.dash();
    break;
    case 86: //V
    morse.dot();morse.dot();morse.dot();morse.dash();
    break;
    case 87: //W
    morse.dot();morse.dash();morse.dash();
    break;
    case 88: //X
    morse.dash();morse.dot();morse.dot();morse.dash();
    break;
    case 89: //Y
    morse.dash();morse.dot();morse.dash();morse.dash();
    break;
    case 90: //Z
    morse.dash();morse.dash();morse.dot();morse.dot();
    break;
  }
}
