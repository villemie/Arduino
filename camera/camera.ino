#include <Process.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
//Diffent settings for pictures
String resArray[4] ={"320x240","640x480","1280x720","1920x1080"};
String timerArray[6] = {"0","1","2","3","4","5"};
String saveArray[2] = {"Hard Drive","Dropbox"};
//Indexes for picture settings
int iRes = 0;
int iDel = 0;
int iSav = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int pressed = press();
  
  switch(pressed){
    case 0:     
    Serial.print(iRes);
    Serial.print(iDel);
    Serial.println(iSav);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Picture taken"); //Takes picture
    delay(500);
    break;
    
    case 1: 
    if(iSav == 1){
      iSav = 0;
      }
    else{
      iSav++;
      }
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Save location:"); //Changes save location
    lcd.setCursor(0,1);
    lcd.print(saveArray[iSav]);
    delay(500);
    break;
    
    case 2: 
    if(iDel == 5)iDel = 0;
    else iDel++;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Delay:"); // Changes delay
    lcd.setCursor(0,1);
    lcd.print(timerArray[iDel]);
    delay(500);
    break;
    
    case 3: 
    if(iRes == 3)iRes = 0;
    else iRes++;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Resolution:"); // Changes resolution
    lcd.setCursor(0,1);
    lcd.print(resArray[iRes]);
    delay(500);
    break;
    }
   
}
int press(){
    
  if(analogRead(A0)>1020){
    return 0;
  }
  else if(analogRead(A1)>1020){
    return 1;
  }
  else if(analogRead(A2)>1020){
    return 2;
  }
  else if(analogRead(A3)>1020){
    return 3;
  }
  else return -1;
  
}
