#include <Wire.h>
#include <kbxui.h>
#include "MakerLABBitmap.h"
uint8_t ledPin[] = {17,2,15,12}; // BT WIFI NTP IOT
uint8_t ledIndex = 0;

uint8_t counter = 0;
unsigned long previousDrawMillis,previousReadMillis = 0;        
const long intervalDraw = 40;
const long intervalRead = 50; 
uint8_t curX=14,curY=3,curBullet=0;
bool fire=false;

void setup() {
   Serial.begin(115200);

   KBX.begin();
   KBX.Lcd.spi_init();
   KBX.Lcd.fillScreen(BLACK);
   KBX.Lcd.setRotation(1);
   KBX.Lcd.drawRGBBitmap(0, 0, MakerLABBitmap, MakerLAB_WIDTH, MakerLAB_HEIGHT);

   for (uint8_t i=0; i<4; i++) pinMode(ledPin[i],OUTPUT);
   for (uint8_t i=0; i<4; i++) digitalWrite(ledPin[i],HIGH);
  
   KBX.matrix.clear();
   KBX.matrix.drawPixel(0, 0, LED_ON);  
   KBX.matrix.setTextSize(1);
   KBX.matrix.setTextWrap(false);
   KBX.matrix.writeDisplay();  // write the changes we just made to the display
   
}

static const uint8_t PROGMEM
  pacman[] =
  { B01000000,
    B11100000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000 };

void loop() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousDrawMillis >= intervalDraw) {
    // save the last time you blinked the LED
    previousDrawMillis = currentMillis;
    
    if(counter<16)
      counter+=1;
    else
      counter=0;
    if(counter==0){
     digitalWrite(ledPin[ledIndex],LOW);
    }else if(counter==15){
     digitalWrite(ledPin[ledIndex],HIGH);
     ledIndex++;
    }
    if (ledIndex >= 4) ledIndex=0;
}
 if (currentMillis - previousReadMillis >= intervalRead) {

    previousReadMillis = currentMillis;
    
    /*------------ read register from KBX-IO -------------*/
    Wire.beginTransmission(0x34);//address 0x34
    Wire.write(0);
    Wire.endTransmission(false);
    Wire.requestFrom((uint8_t)0x34, (uint8_t)16, true);//request 16 Bytes
   
    byte buff[16];
    byte idx = 0;
    while(Wire.available()) 
      ((uint8_t*)buff)[idx++] = Wire.read();
      
    
    //Serial.println(buff[13]);
    /*--------------------------------------------------*/
       if(buff[1]!=0 && buff[1]>3 && buff[1]<30){
      
      Serial.print(buff[1]);
      KBX.matrix.setRotation(1);
      KBX.matrix.clear();
      KBX.matrix.setCursor(5,0);
      KBX.matrix.print(char(buff[1]+61));
      KBX.matrix.writeDisplay();
      delay(100);
      
    } 
  }
}
