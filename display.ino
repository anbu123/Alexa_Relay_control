#include <DMD2.h>
#include <fonts/MyBigFont.h>
#include <fonts/Arial_Black_16.h>
#include <EEPROM.h>
#define Panjang 2                         // Number of height of Display P10
#define Lebar 1                           // Number of width of Display P10
SoftDMD dmd(Panjang, Lebar);  
byte Brightness;
int a=100;
int leftScore = 25;
int i;
char dmdBuff[10];
void setup() {
  Brightness = EEPROM.read(0);
  dmd.setBrightness(255);
  dmd.selectFont(Arial_Black_16);
  dmd.begin();
  dmd.clearScreen();
  Serial.begin(9600);
  //blinkDisplay();
}
void blinkDisplay(){
a+=1;
delay(1000);
}
void loop() {
  dmd.drawString(0,0,"A1");
  dmd.drawString(20,0, "-" );
  sprintf(dmdBuff,"%2d",a);
  dmd.drawString(25,0, dmdBuff);
  blinkDisplay();
}
