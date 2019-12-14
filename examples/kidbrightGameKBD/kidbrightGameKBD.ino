#include <Wire.h>
#include <kbxui.h>
#include "MakerLABBitmap.h"
uint8_t ledPin[] = {17,2,15,12}; // BT WIFI NTP IOT
uint8_t ledIndex = 0;

#ifndef _BV
  #define _BV(bit) (1<<(bit))
#endif



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
    KBX.matrix.drawBitmap(curY, curX, pacman, 8, 8, LED_ON);
    KBX.matrix.writeFastHLine(0,counter-1,8,LED_OFF);
    KBX.matrix.writeFastHLine(0,counter,8,LED_ON);
    if(curX>10)
     KBX.matrix.writeLine(curY,2,curY+2 ,2,LED_ON);
    if(fire==true){
      fire=false;
      curBullet=curX-1;
    }
    if(fire==false && curBullet>0){
      if(curBullet>2){
        curBullet--;
        KBX.matrix.writePixel(curY+1,curBullet,LED_ON);
      }
    }
    
    KBX.matrix.writeDisplay();
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
   
    //buf[0]-[3] keyboard
    //buf[8]-buf[15] joystick
    //read in USBIIC_protocol.pdf
    if(buff[1]==82 || buff[2]==82 || buff[3]==82){
      if(curX>0)
        curX--;
      Serial.println("UP");
      KBX.matrix.clear();
    }

    if(buff[9]==0){
      if(curX>0)
        curX--;
      Serial.println("UP");
      KBX.matrix.clear();
    }
    
    if(buff[1]==81 || buff[2]==81 || buff[3]==81){
      if(curX<14)
        curX++;
      //Serial.println("Down");
      KBX.matrix.clear();
    }

    if(buff[9]==255){
      if(curX<14)
        curX++;
      //Serial.println("Down");
      KBX.matrix.clear();
    }

    
    if(buff[1]==80 || buff[2]==80 || buff[3]==80){
      if(curY>0)
        curY--;
      //Serial.println("Left");
      KBX.matrix.clear();
    }

    if(buff[8]==0){
      if(curY>0)
        curY--;
      //Serial.println("Left");
      KBX.matrix.clear();
    }
    
    if(buff[1]==79 || buff[2]==79 || buff[3]==79){
      if(curY<5)
        curY++;
      //Serial.println("Right");
      KBX.matrix.clear();
    }

    if(buff[8]==255 ){
      if(curY<5)
        curY++;
      //Serial.println("Right");
      KBX.matrix.clear();
    }
   
    if(buff[1]==19 || buff[2]==19 || buff[3]==19){
      //Serial.println(curBullet);
      if(curBullet<3){
        fire=true;
        //Serial.println("fire");
      }
    }

    if(buff[13]==31 ){
      //Serial.println(curBullet);
      if(curBullet<3){
        fire=true;
        //Serial.println("fire");
      }
    }
    
    if(buff[1]!=0){
      Serial.print(buff[0],BIN);
      Serial.print("==");
      Serial.print(buff[1],DEC);
      Serial.print("==");
      Serial.print(buff[2]);
      Serial.print("==");
      Serial.println(buff[3]);
    } 
  }
}
