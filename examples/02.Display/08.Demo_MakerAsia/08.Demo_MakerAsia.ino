

/*************************************************** 
  This is a library for our I2C LED Backpacks & FeatherWings

  Designed specifically to work with the Adafruit 16x8 LED Matrix FeatherWing

  These displays use I2C to communicate, 2 pins are required to 
  interface. There are multiple selectable I2C addresses. For backpacks
  with 2 Address Select pins: 0x70, 0x71, 0x72 or 0x73. For backpacks
  with 3 Address Select pins: 0x70 thru 0x77

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/
#include "kbxui.h"
//#include <Wire.h>
//#include <Adafruit_GFX.h>
//#include "Adafruit_LEDBackpack.h"
#include "MakerLABBitmap.h"
uint8_t ledPin[] = {23,2,15,12}; // BT WIFI NTP IOT
//Adafruit_8x16minimatrix matrix = Adafruit_8x16minimatrix();

//#include <Adafruit_ILI9341.h>
//#define TFT_DC 18
//#define TFT_CS 19
//#define TFT_MOSI 21
//#define TFT_CLK 22

//Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK);

bool statusLCD = true;

void textShow(void) {
  KBX.Lcd.spi_init();
  KBX.Lcd.fillScreen(ILI9341_BLACK);
  KBX.Lcd.setCursor(0, 0);
  KBX.Lcd.setTextColor(ILI9341_WHITE);  KBX.Lcd.setTextSize(1);
  KBX.Lcd.println("Hello World!");
  KBX.Lcd.setTextColor(ILI9341_YELLOW); KBX.Lcd.setTextSize(2);
  KBX.Lcd.println(1234.56);
  KBX.Lcd.setTextColor(ILI9341_RED);    KBX.Lcd.setTextSize(3);
  KBX.Lcd.println(0xDEADBEEF, HEX);
  KBX.Lcd.println();
  KBX.Lcd.setTextColor(ILI9341_GREEN);
  KBX.Lcd.setTextSize(5);
  KBX.Lcd.println("Groop");
  KBX.Lcd.setTextSize(2);
  KBX.Lcd.println("I implore thee,");
  KBX.Lcd.setTextSize(1);
  KBX.Lcd.println("my foonting turlingdromes.");
  KBX.Lcd.println("And hooptiously drangle me");
  KBX.Lcd.println("with crinkly bindlewurdles,");
  KBX.Lcd.println("Or I will rend thee");
  KBX.Lcd.println("in the gobberwarts");
  KBX.Lcd.println("with my blurglecruncheon,");
  KBX.Lcd.println("see if I don't!");
}

void setup() {
  //while (!Serial);
  Serial.begin(115200);
  Serial.println("16x8 LED Mini Matrix Test");

  KBX.begin();
  KBX.Lcd.fillScreen(BLACK);
  KBX.Lcd.setRotation(1);
  KBX.Lcd.drawRGBBitmap(0, 0, MakerLABBitmap, MakerLAB_WIDTH, MakerLAB_HEIGHT);
    
  for (uint8_t i=0; i<4; i++) pinMode(ledPin[i],OUTPUT);
  for (uint8_t i=0; i<4; i++) digitalWrite(ledPin[i],HIGH);
  
  //KBX.Led.begin(0x70);  // pass in the address
  KBX.Led.clear();
  KBX.Led.drawPixel(0, 0, LED_ON);  
  KBX.Led.writeDisplay();  // write the changes we just made to the display
}

void loop() {

  uint8_t j = 0;

  KBX.Led.setTextSize(1);
  KBX.Led.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  KBX.Led.setTextColor(LED_ON);
  KBX.Led.setRotation(1);
  for (int8_t x=16; x>=-126; x--) {
    KBX.Led.clear();
    KBX.Led.setCursor(x,0);
    KBX.Led.print("MakerLAB by MakerAsia");
    KBX.Led.writeDisplay();

    digitalWrite(ledPin[j],LOW);
    delay(95);
    digitalWrite(ledPin[j],HIGH);

    j++;
    if (j >= 4) j=0;
  }
  KBX.Led.setRotation(0);
  if (statusLCD) {
	  textShow();
	  statusLCD = false;
  } else {
      KBX.Lcd.spi_init();
	  KBX.Lcd.drawRGBBitmap(0, 0, MakerLABBitmap, MakerLAB_WIDTH, MakerLAB_HEIGHT);
	  statusLCD = true;
  }
}
