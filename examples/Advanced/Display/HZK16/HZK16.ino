#define USE_INTERNAL_HZK

#include <KBXUI.h>
#include "str.h"

void setup() {
  KBX.begin();
  // Use HZK16 and ASC16 font set
  // NOTE: font file should be copied to your TF card.
  KBX.Lcd.loadHzk16("/Fonts/HZK16","/Fonts/ASC16");
  // Set text with white foreground color and black background color
  KBX.Lcd.setTextColor(WHITE, BLACK);
  // Set text with red highlight color
  KBX.Lcd.setHighlightColor(RED);
  
  // Set text size to 1
  KBX.Lcd.setTextSize(1);
  KBX.Lcd.setCursor(0,10);
  // Print some ASCII text on the screen
  KBX.Lcd.printf(AscStr);
  delay(1000);
  // Highlight the text
  KBX.Lcd.highlight(true);
  KBX.Lcd.setCursor(0,10);
  KBX.Lcd.printf(AscStr);
  
  delay(1000);
  // Clear screen
  KBX.Lcd.clear();
  // Turn highlight off
  KBX.Lcd.highlight(false);
  KBX.Lcd.setCursor(0,10);
  // print some GBK text on the screen
  KBX.Lcd.printf(GbkStr);  
  delay(1000);
  KBX.Lcd.highlight(true);
  KBX.Lcd.setCursor(0,10);
  KBX.Lcd.printf(GbkStr);
  
  delay(1000);
  KBX.Lcd.clear();
  
  // Set text size to 2
  KBX.Lcd.setTextSize(2);
  KBX.Lcd.setCursor(0,10);
  KBX.Lcd.highlight(false);
  KBX.Lcd.printf(AscStr);
  delay(1000);
  KBX.Lcd.highlight(true);
  KBX.Lcd.setCursor(0,10);
  KBX.Lcd.printf(AscStr);  
  delay(1000);
  
  KBX.Lcd.clear();
  KBX.Lcd.highlight(false);
  KBX.Lcd.setCursor(0,10);
  KBX.Lcd.printf(GbkStr);
  delay(1000);
  KBX.Lcd.highlight(true);
  KBX.Lcd.setCursor(0,10);
  KBX.Lcd.printf(GbkStr);
  
  delay(1000);
  
  KBX.Lcd.clear();
  KBX.Lcd.highlight(false);
  
  // Set text with non-transparent back color, BLACK as set at the beginning.
  KBX.Lcd.setTransparentBgColor(false);  
  KBX.Lcd.setCursor(0,10);
  KBX.Lcd.printf(GbkStr);
  
  // Set text with transparent back color
  KBX.Lcd.setTransparentBgColor(true);
  KBX.Lcd.setCursor(0,130);
  KBX.Lcd.printf(GbkStr);
}

void loop() {
  // put your main code here, to run repeatedly:

}
