#include <kbxui.h>
#include "MakerLABBitmap.h"

void setup()
{
  Serial.begin(115200);

   KBX.begin();
   KBX.Lcd.spi_init();
   KBX.Lcd.fillScreen(BLACK);
   KBX.Lcd.setRotation(1);
   KBX.Lcd.drawRGBBitmap(0, 0, MakerLABBitmap, MakerLAB_WIDTH, MakerLAB_HEIGHT);

   KBX.matrix.clear();
   KBX.matrix.drawPixel(0, 0, LED_ON);  
   KBX.matrix.setRotation(1);
   KBX.matrix.setTextSize(1);
   KBX.matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
   KBX.matrix.writeDisplay();  // write the changes we just made to the display
   

   KBX.lm73.begin(LM73_1_I2C_GND);
   KBX.lm73.setResolution(LM73_RESOLUTION_11BIT); // 11 bit
   KBX.lm73.power(LM73_POWER_OFF); // Turn off sensor (one shot temperature conversion)

}

void loop()
{
  KBX.lm73.startOneShot();
  while(!KBX.lm73.ready());
  double temp = KBX.lm73.temperature();
  
  Serial.print(F("Temperature: "));
  Serial.println(temp, 5);

  for (int8_t x=0; x>=-32; x--) {
    KBX.matrix.clear();
    KBX.matrix.setCursor(x,0);
    if(x==-1)
     delay(1000);
    KBX.matrix.print(temp);
    KBX.matrix.writeDisplay();
    delay(100);
  }
  
}
