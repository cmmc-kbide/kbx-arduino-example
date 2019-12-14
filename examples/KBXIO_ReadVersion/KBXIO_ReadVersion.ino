#include <Wire.h>
#include <kbxui.h>
unsigned long previousReadMillis = 0;        
const long intervalRead = 100; 

void setup() {
   Serial.begin(115200);
   KBX.begin();
}

void loop() {
 unsigned long currentMillis = millis();
 if (currentMillis - previousReadMillis >= intervalRead) {

    previousReadMillis = currentMillis;
    
    /*------------ read register from KBX-IO -------------*/
    Wire.beginTransmission(0x34);//address 0x34
    Wire.write(0x10);//read version register
    Wire.endTransmission(false);
    Wire.requestFrom((uint8_t)0x34, (uint8_t)2, true);//request 2 Bytes major & minor
    while(Wire.available()) {
      int v = Wire.read(); 
      Serial.print(v,HEX);
      Serial.print(".");
    }
    Serial.println();
    Wire.endTransmission(true);
 }
}
