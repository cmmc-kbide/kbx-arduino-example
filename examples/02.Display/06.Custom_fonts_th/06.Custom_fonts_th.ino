/*
  Example for TFT_eSPI library

  Created by Bodmer 11/03/17

  Make sure LOAD_GFXFF is defined in the used User_Setup file
  within the library folder.

  --------------------------- NOTE ----------------------------------------
  The free font encoding format does not lend itself easily to plotting
  the background without flicker. For values that changes on screen it is
  better to use Fonts 1- 8 which are encoded specifically for rapid
  drawing with background.
  -------------------------------------------------------------------------

  #########################################################################
  ###### DON'T FORGET TO UPDATE THE User_Setup.h FILE IN THE LIBRARY ######
  ######   TO SELECT YOUR DISPLAY TYPE, PINS USED AND ENABLE FONTS   ######
  #########################################################################
*/

// Note the the tilda symbol ~ does not exist in some fonts at the moment
#define TEXT "abc MWy 123 |" // Text that will be printed on screen in any font

#include <kbxui.h>

// Stock font and GFXFF reference handle
#define GFXFF 1
#define FF18 &FreeSans12pt7b

// Custom are fonts added to library "TFT_eSPI\Fonts\Custom" folder
// a #include must also be added to the "User_Custom_Fonts.h" file
// in the "TFT_eSPI\User_Setups" folder. See example entries.
#include "Fonts/Kanit-Regular-9-en.h"
#include "Fonts/Kanit-Regular-12-en.h"
#include "Fonts/Kanit-Regular-18-en.h"
#include "Fonts/Kanit-Regular-24-en.h"

#include "Fonts/Kanit-Regular-9-th.h"
#include "Fonts/Kanit-Regular-12-th.h"
#include "Fonts/Kanit-Regular-18-th.h"
#include "Fonts/Kanit-Regular-24-th.h"



#include "Fonts/Kanit-Bold-9-en.h"
#include "Fonts/Kanit-Bold-12-en.h"
#include "Fonts/Kanit-Bold-18-en.h"
#include "Fonts/Kanit-Bold-24-en.h"

#include "Fonts/Kanit-Italic-9-en.h"
#include "Fonts/Kanit-Italic-12-en.h"
#include "Fonts/Kanit-Italic-18-en.h"
#include "Fonts/Kanit-Italic-24-en.h"

#include "Fonts/Kanit-BoldItalic-9-en.h"
#include "Fonts/Kanit-BoldItalic-12-en.h"
#include "Fonts/Kanit-BoldItalic-18-en.h"
#include "Fonts/Kanit-BoldItalic-24-en.h"


#include "Fonts/Kanit-Bold-9-th.h"
#include "Fonts/Kanit-Bold-12-th.h"
#include "Fonts/Kanit-Bold-18-th.h"
#include "Fonts/Kanit-Bold-24-th.h"

#include "Fonts/Kanit-Italic-9-th.h"
#include "Fonts/Kanit-Italic-12-th.h"
#include "Fonts/Kanit-Italic-18-th.h"
#include "Fonts/Kanit-Italic-24-th.h"

#include "Fonts/Kanit-BoldItalic-9-th.h"
#include "Fonts/Kanit-BoldItalic-12-th.h"
#include "Fonts/Kanit-BoldItalic-18-th.h"
#include "Fonts/Kanit-BoldItalic-24-th.h"

#define CF_KN_REG_09_EN &Kanit_Regular9pt7b
#define CF_KN_REG_09_TH &Kanit_Regular9pt8b
#define CF_KN_REG_12_EN &Kanit_Regular12pt7b
#define CF_KN_REG_12_TH &Kanit_Regular12pt8b
#define CF_KN_REG_18_EN &Kanit_Regular18pt7b
#define CF_KN_REG_18_TH &Kanit_Regular18pt8b
#define CF_KN_REG_24_EN &Kanit_Regular24pt7b
#define CF_KN_REG_24_TH &Kanit_Regular24pt8b


void setup(void) {

  KBX.begin();
  KBX.Lcd.setRotation(1);
  
  KBX.Lcd.setTextDatum(MC_DATUM);

  // Set text colour to white with black background
  // Unlike the stock Adafruit_GFX library, the TFT_eSPI library DOES draw the background
  // for the custom and Free Fonts
  
}

void loop() {

  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  // Show custom fonts
  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  // Where font sizes increase the screen is not cleared as the larger fonts overwrite
  // the smaller one with the background colour.

  // We can set the text datum to be Top, Middle, Bottom vertically and Left, Centre
  // and Right horizontally. These are the text datums that can be used:
  // TL_DATUM = Top left (default)
  // TC_DATUM = Top centre
  // TR_DATUM = Top right
  // ML_DATUM = Middle left
  // MC_DATUM = Middle centre <<< This is used below
  // MR_DATUM = Middle right
  // BL_DATUM = Bottom left
  // BC_DATUM = Bottom centre
  // BR_DATUM = Bottom right
  // L_BASELINE = Left character baseline (Line the 'A' character would sit on)
  // C_BASELINE = Centre character baseline
  // R_BASELINE = Right character baseline

  //Serial.println();
  
  // Set text datum to middle centre (MC_DATUM)
  KBX.Lcd.setTextDatum(MC_DATUM);

  // Set text colour to white with black background
  // Unlike the stock Adafruit_GFX library, the TFT_eSPI library DOES draw the background
  // for the custom and Free Fonts
  KBX.Lcd.setTextColor(TFT_WHITE, TFT_BLACK);

  KBX.Lcd.fillScreen(TFT_DARKGREY);            // Clear screen
  KBX.Lcd.setFreeFont(FF18);                 // Select the font
  KBX.Lcd.drawString("Kanit Regular 09", 160, 40, GFXFF);// Print the string name of the font
  KBX.Lcd.setUTF8Font(CF_KN_REG_09_EN,CF_KN_REG_09_TH,NULL);                 // Select the font
  KBX.Lcd.drawString(TEXT, 160, 110, GFXFF);// Print the string name of the font
  KBX.Lcd.drawUTF8String("ABay กุขคก่กี่ป่ปี่๐๑๒", 160, 110+KBX.Lcd.fontHeight(GFXFF), GFXFF);// Print the string name of the font
  
  delay(2000);

  KBX.Lcd.fillScreen(TFT_DARKGREY);            // Clear screen
  KBX.Lcd.setFreeFont(FF18);                 // Select the font
  KBX.Lcd.drawString("Kanit Regular 12", 160, 40, GFXFF);// Print the string name of the font
  KBX.Lcd.setUTF8Font(CF_KN_REG_12_EN,CF_KN_REG_12_TH,NULL);                 // Select the font
  KBX.Lcd.drawString(TEXT, 160, 110, GFXFF);// Print the string name of the font
  KBX.Lcd.drawUTF8String("ABay กุขก่กี่ป่ปี่๐๑๒", 160, 110+KBX.Lcd.fontHeight(GFXFF), GFXFF);// Print the string name of the font
  delay(2000);

  KBX.Lcd.fillScreen(TFT_DARKGREY);            // Clear screen
  KBX.Lcd.setFreeFont(FF18);                 // Select the font
  KBX.Lcd.drawString("Kanit Regular 18", 160, 40, GFXFF);// Print the string name of the font
  KBX.Lcd.setUTF8Font(CF_KN_REG_18_EN,CF_KN_REG_18_TH,NULL);                 // Select the font
  KBX.Lcd.drawString(TEXT, 160, 110, GFXFF);// Print the string name of the font
  KBX.Lcd.drawUTF8String("Ay กุขก่กี่ป่ปี่๐๑", 160, 110+KBX.Lcd.fontHeight(GFXFF), GFXFF);// Print the string name of the font
  delay(2000);

  KBX.Lcd.fillScreen(TFT_DARKGREY);            // Clear screen
  KBX.Lcd.setFreeFont(FF18);                 // Select the font
  KBX.Lcd.drawString("Kanit Regular 24", 160, 40, GFXFF);// Print the string name of the font
  KBX.Lcd.setUTF8Font(CF_KN_REG_24_EN,CF_KN_REG_24_TH,NULL);                 // Select the font
  KBX.Lcd.drawString(TEXT, 160, 110, GFXFF);// Print the string name of the font
  KBX.Lcd.drawUTF8String("Ay กุขก่กี่ป่ปี่๐๑", 160, 110+KBX.Lcd.fontHeight(GFXFF), GFXFF);// Print the string name of the font
  delay(2000);

  // Reset text padding to zero (default)
  KBX.Lcd.setTextPadding(0);
  
}

