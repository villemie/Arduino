#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int piezoPin = 9; // change to pin of Piezo
int program = 0;
int pState = 0;
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  start();
  
  }

void loop() {
  lcd.print("Laskin");
  menu();
  
    
}
void menu(){
  String programs[] = {"Laskin", "Sekuntikello", "Aaniohjelma"};
  int mIndex = 0;
  while(true){
    int pressed = press();
    if(pressed != -1 || pressed != 2){
    if(pressed == 0){
      if(mIndex == 2)mIndex = 0;
      else mIndex++;
      lcd.clear();
      lcd.print(programs[mIndex]);
      Serial.println(mIndex);
    }
    if(pressed == 1){
      switch(mIndex){
        case 0:
          lcd.clear();
          lcd.print("Ohjelmaa ei ole :(");
          delay(1000);
          lcd.clear();
          lcd.print(programs[mIndex]);
        break;
        case 1:
          lcd.clear();
          sekuntikello();
          lcd.clear();
          lcd.print(programs[mIndex]);
        break;
        case 2:
          lcd.clear();
          lcd.print("Ohjelmaa ei ole :(");
         delay(1000);
         lcd.clear();
         lcd.print(programs[mIndex]);
        break;
        }
     
    }
  }
  }
}
void start(){
  
  String intro = "ArduOS v1.0";
  
    for(int i = 0; i < intro.length(); i++){
    lcd.setCursor(i,0);
    lcd.print(intro[i]);
    delay(100);
    }
       
    delay(500);
    
  //startSound();  
  lcd.clear();
  delay(250);
}
void sekuntikello(){
  lcd.print("Paina ok");
  int painettu = -1;
  bool counting = false;
  int curTime, startTime;
  
  while(painettu != 2){
    painettu = press();
    if(painettu == 1 && counting == false){
      counting = true;
      startTime = millis();
      
    }
    else if(painettu == 1 && counting == true){
      counting = false;
      curTime = millis();
      lcd.clear();
      lcd.print(formatTime(curTime-startTime));
    }
    else if(counting == true){
      lcd.clear();
      curTime = millis();
      lcd.print(formatTime(curTime-startTime));
      
    }
  }
}
String formatTime(int ms){
  int sec = ms/1000;
  ms = ms%1000;
  String form = (String)sec;
  form += ".";
  form += (String)ms;
  form += "s";
  return form;
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
      tone(piezoPin, 31, 30);
      return pressed;
      
    }
    return -1;
}
void startSound(){
  /* 
  Nokia Tune
  Connect a piezo buzzer or speaker to pin 11 or select a new pin.
  More songs available at https://github.com/robsoncouto/arduino-songs                                            
                                              
                                              Robson Couto, 2019
*/

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0


// change this to make the song slower or faster
int tempo = 200;

// change this to whichever pin you want to use
int buzzer = 9;

// notes of the moledy followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
int melody[] = {

  // Nokia Ringtone 
  // Score available at https://musescore.com/user/29944637/scores/5266155
  
  NOTE_E5, 8, NOTE_D5, 8, NOTE_FS4, 4, NOTE_GS4, 4, 
  NOTE_CS5, 8, NOTE_B4, 8, NOTE_D4, 4, NOTE_E4, 4, 
  NOTE_B4, 8, NOTE_A4, 8, NOTE_CS4, 4, NOTE_E4, 4,
  NOTE_A4, 2, 
};

// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes
int notes = sizeof(melody) / sizeof(melody[0]) / 2;

// this calculates the duration of a whole note in ms
int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;


  // iterate over the notes of the melody.
  // Remember, the array is twice the number of notes (notes + durations)
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    // calculates the duration of each note
    divider = melody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, melody[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzer);
  
}
  }
