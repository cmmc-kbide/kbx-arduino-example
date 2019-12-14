/*  
 Test the KBX.Lcd.print() viz embedded KBX.Lcd.write() function

 This sketch used font 2, 4, 7

 Make sure all the display driver and pin comnenctions are correct by
 editting the User_Setup.h file in the TFT_eSPI library folder.

 #########################################################################
 ###### DON'T FORGET TO UPDATE THE User_Setup.h FILE IN THE LIBRARY ######
 #########################################################################
 */

#include <KBXUI.h>

#define TFT_GREY 0x5AEB // New colour


void setup(void) {
  KBX.begin();
  // KBX.Lcd.setRotation(2);
}

void loop() {
  
  // Fill screen with grey so we can see the effect of printing with and without 
  // a background colour defined
  KBX.Lcd.fillScreen(TFT_GREY);
  
  // Set "cursor" at top left corner of display (0,0) and select font 2
  // (cursor will move to next line automatically during printing with 'KBX.Lcd.println'
  //  or stay on the line is there is room for the text with KBX.Lcd.print)
  KBX.Lcd.setCursor(0, 0, 2);
  // Set the font colour to be white with a black background, set text size multiplier to 1
  KBX.Lcd.setTextColor(TFT_WHITE,TFT_BLACK);  
  KBX.Lcd.setTextSize(1);
  // We can now plot text on screen using the "print" class
  KBX.Lcd.println("Hello World!");
  
  // Set the font colour to be yellow with no background, set to font 7
  KBX.Lcd.setTextColor(TFT_YELLOW); KBX.Lcd.setTextFont(7);
  KBX.Lcd.println(1234.56);
  
  // Set the font colour to be red with black background, set to font 4
  KBX.Lcd.setTextColor(TFT_RED,TFT_BLACK);    KBX.Lcd.setTextFont(4);
  //KBX.Lcd.println(3735928559L, HEX); // Should print DEADBEEF

  // Set the font colour to be green with black background, set to font 4
  KBX.Lcd.setTextColor(TFT_GREEN,TFT_BLACK);
  KBX.Lcd.setTextFont(4);
  KBX.Lcd.println("Groop");
  KBX.Lcd.println("I implore thee,");

  // Change to font 2
  KBX.Lcd.setTextFont(2);
  KBX.Lcd.println("my foonting turlingdromes.");
  KBX.Lcd.println("And hooptiously drangle me");
  KBX.Lcd.println("with crinkly bindlewurdles,");
  // This next line is deliberately made too long for the display width to test
  // automatic text wrapping onto the next line
  KBX.Lcd.println("Or I will rend thee in the gobberwarts with my blurglecruncheon, see if I don't!");
  
  // Test some print formatting functions
  float fnumber = 123.45;
   // Set the font colour to be blue with no background, set to font 4
  KBX.Lcd.setTextColor(TFT_BLUE);    KBX.Lcd.setTextFont(4);
  KBX.Lcd.print("Float = "); KBX.Lcd.println(fnumber);           // Print floating point number
  KBX.Lcd.print("Binary = "); KBX.Lcd.println((int)fnumber, BIN); // Print as integer value in binary
  KBX.Lcd.print("Hexadecimal = "); KBX.Lcd.println((int)fnumber, HEX); // Print as integer number in Hexadecimal
  delay(10000);
}



