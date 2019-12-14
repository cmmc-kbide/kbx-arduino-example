#include <Wire.h>
#include <kbxui.h>
unsigned long previousReadMillis = 0;        
const long intervalRead = 100; 

void setup() {
   Serial.begin(115200);
   KBX.begin();
   //set baudrate
   Wire.beginTransmission(0x34);//address 0x34
   Wire.write(0x25);
   Wire.write(0x9);//9600
   Wire.endTransmission(true);
}


void loop() {
 unsigned long currentMillis = millis();
 if (currentMillis - previousReadMillis >= intervalRead) {

    previousReadMillis = currentMillis;
    
    /*------------ read register from KBX-IO -------------*/
    Wire.beginTransmission(0x34);//address 0x34
    Wire.write(0x26);//read from serial register
    Wire.endTransmission(false);
    Wire.requestFrom((uint8_t)0x34, (uint8_t)64, true);//request 64 Bytes index 0 is byte count
    byte buff[64];
    byte idx = 0;
    buff[0]=0;
    while(Wire.available()) {
      ((uint8_t*)buff)[idx] = Wire.read();
      idx+=1;
      //Serial.print(buff[idx-1]);
    }
    
    if(buff[0]>0){
      Serial.println(buff[0]);
      for(int i =1;i<=buff[0];i++){
       Serial.print(char(buff[i]));
      }
    }
    Wire.endTransmission(false);
    
    //write echo back
    Wire.beginTransmission(0x34);//address 0x34
    Wire.write(0x26);
    if(buff[0]>0){
      for(int i =1;i<=buff[0];i++){
       Wire.write(buff[i]);
      }
    }
    Wire.endTransmission(true);
 }
}
