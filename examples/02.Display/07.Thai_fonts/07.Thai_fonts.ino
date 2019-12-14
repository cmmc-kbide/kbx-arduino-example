/*
  This example draws fonts (as used by the Adafruit_GFX library) onto the
  screen. These fonts are called the GFX Free Fonts (GFXFF) in this library.

  Other True Type fonts could be converted using the utility within the
  "fontconvert" folder inside the library. This converted has also been
  copied from the Adafruit_GFX library.

  Since these fonts are a recent addition Adafruit do not have a tutorial
  available yet on how to use the utility.   Linux users will no doubt
  figure it out!  In the meantime there are 48 font files to use in sizes
  from 9 point to 24 point, and in normal, bold, and italic or oblique
  styles.

  This example sketch uses both the print class and drawString() functions
  to plot text to the screen.

  Make sure LOAD_GFXFF is defined in the User_Setup.h file within the
  TFT_eSPI library folder.

  --------------------------- NOTE ----------------------------------------
  The free font encoding format does not lend itself easily to plotting
  the background without flicker. For values that changes on screen it is
  better to use Fonts 1- 8 which are encoded specifically for rapid
  drawing with background.
  -------------------------------------------------------------------------

  >>>>>>>>>>>>>>>>>>>>>>>>>>> WARNING <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

  As supplied with the default settings the sketch has 11 fonts loaded,
  i.e. GLCD (Font 1), Font 2, Font 4, Font 6, Font 7, Font 8 and five Free Fonts,
  even though they are not all used in the sketch.

  Disable fonts you do not need in User_Setup.h in the library folder.

  #########################################################################
  ###### DON'T FORGET TO UPDATE THE User_Setup.h FILE IN THE LIBRARY ######
  #########################################################################
*/

#include <kbxui.h>
#include "Thai_Fonts.h" // Include the header file attached to this sketch

unsigned long drawTime = 0;

void header(const char *string, uint16_t color);
void drawDatumMarker(int x, int y);

void setup(void) {

  KBX.begin();
  KBX.Lcd.setRotation(1);
}

void loop() {

  int xpos =  0;
  int ypos = 32;

  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  // Select different fonts to draw on screen using the print class
  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  KBX.Lcd.setPrintUTF8(false);
  header("Text with a datum", TFT_BLACK);
  KBX.Lcd.setPrintUTF8(true);
  KBX.Lcd.setTextColor(TFT_YELLOW, TFT_BLACK);
  //KBX.Lcd.setFreeFont(FSS12);
  KBX.Lcd.setUTF8Font(CF_KN_REG_18_EN,CF_KN_REG_18_TH,NULL);
  KBX.Lcd.setTextDatum(C_BASELINE);
  int y = 80;
  KBX.Lcd.drawString("กก่กี่กป่กปี่", 160, y, GFXFF);
  y += KBX.Lcd.fontHeight(GFXFF);
  KBX.Lcd.drawString("กันกิกีกึกืก็ปัปิปีปึปืป็", 160, y, GFXFF);
  y += KBX.Lcd.fontHeight(GFXFF);
  KBX.Lcd.drawString("ก่ก้ก๊ก๋ก์กป่ป้ป๊ป๋ป์", 160, y, GFXFF);
  y += KBX.Lcd.fontHeight(GFXFF);
  KBX.Lcd.drawString("กี่กี้กี๊กี๋กิ์กปี่ปี้ปี๊ปี๋ปิ์", 160, y, GFXFF);
  //drawDatumMarker(160,120);

  delay(8000);

  KBX.Lcd.setPrintUTF8(false);
  header("Using print() method", TFT_NAVY);

  // For comaptibility with Adafruit_GFX library the text background is not plotted when using the print class
  // even if we specify it.
  KBX.Lcd.setTextColor(TFT_YELLOW);
  KBX.Lcd.setCursor(xpos, ypos);    // Set cursor near top left corner of screen

  KBX.Lcd.setFreeFont(TT1);     // Select the orginal small TomThumb font
  KBX.Lcd.println();             // Move cursor down a line
  KBX.Lcd.print("The really tiny TomThumb font");    // Print the font name onto the TFT screen
  KBX.Lcd.println();

  //KBX.Lcd.setFreeFont(FSB9);   // Select Free Serif 9 point font, could use:
  KBX.Lcd.setUTF8Font(CF_KN_REG_09_EN,CF_KN_REG_09_TH,NULL);
  KBX.Lcd.setPrintUTF8(true);
  // KBX.Lcd.setFreeFont(&FreeSerif9pt7b);
  KBX.Lcd.println();          // Free fonts plot with the baseline (imaginary line the letter A would sit on)
  // as the datum, so we must move the cursor down a line from the 0,0 position
  KBX.Lcd.print("Kanit คณิต 9");  // Print the font name onto the TFT screen

  //KBX.Lcd.setFreeFont(FSB12);       // Select Free Serif 12 point font
  KBX.Lcd.setUTF8Font(CF_KN_REG_12_EN,CF_KN_REG_12_TH,NULL);
  KBX.Lcd.println();          // Free fonts plot with the baseline (imaginary line the letter A would sit on)
  KBX.Lcd.print("Kanit คณิต 12"); // Print the font name onto the TFT screen

  //KBX.Lcd.setFreeFont(FSB18);       // Select Free Serif 12 point font
  KBX.Lcd.setUTF8Font(CF_KN_REG_18_EN,CF_KN_REG_18_TH,NULL);
  KBX.Lcd.println();                // Move cursor down a line
  KBX.Lcd.print("Kanit คณิต 18"); // Print the font name onto the TFT screen

  //KBX.Lcd.setFreeFont(FSB24);       // Select Free Serif 24 point font
  KBX.Lcd.setUTF8Font(CF_KN_REG_24_EN,CF_KN_REG_24_TH,NULL);
  KBX.Lcd.println();                // Move cursor down a line
  KBX.Lcd.print("Kanit คณิต 24"); // Print the font name onto the TFT screen


  delay(4000);

  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  // Now use drawString() so we can set font background colours and the datum
  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  KBX.Lcd.setPrintUTF8(false);
  header("Using drawString()", TFT_BLACK);

  KBX.Lcd.setTextColor(TFT_WHITE, TFT_BLACK);

  KBX.Lcd.setTextDatum(TC_DATUM); // Centre text on x,y position

  xpos = KBX.Lcd.width() / 2; // Half the screen width
  ypos = 32;

  KBX.Lcd.setPrintUTF8(true);
  //KBX.Lcd.setFreeFont(FSB9);                              // Select the font
  KBX.Lcd.setUTF8Font(CF_KN_REG_09_EN,CF_KN_REG_09_TH,NULL);
  KBX.Lcd.drawString("Kanit คณิต 9", xpos, ypos, GFXFF);  // Draw the text string in the selected GFX free font
  ypos += KBX.Lcd.fontHeight(GFXFF);                      // Get the font height and move ypos down

  //KBX.Lcd.setFreeFont(FSB12);
  KBX.Lcd.setUTF8Font(CF_KN_REG_12_EN,CF_KN_REG_12_TH,NULL);
  KBX.Lcd.drawString("Kanit คณิต 12", xpos, ypos, GFXFF);
  ypos += KBX.Lcd.fontHeight(GFXFF);

  //KBX.Lcd.setFreeFont(FSB18);
  KBX.Lcd.setUTF8Font(CF_KN_REG_18_EN,CF_KN_REG_18_TH,NULL);
  KBX.Lcd.drawString("Kanit คณิต 18", xpos, ypos, GFXFF);
  ypos += KBX.Lcd.fontHeight(GFXFF);

  //KBX.Lcd.setFreeFont(FSB24);
  KBX.Lcd.setUTF8Font(CF_KN_REG_24_EN,CF_KN_REG_24_TH,NULL);
  KBX.Lcd.drawString("Kanit คณิต 24", xpos, ypos, GFXFF);
  ypos += KBX.Lcd.fontHeight(GFXFF);

  // Set text padding to 100 pixels wide area to over-write old values on screen
  KBX.Lcd.setTextPadding(100);
  for (int i = 0; i <= 20; i++) {
    KBX.Lcd.drawFloat(i / 10.0, 1, xpos, ypos, GFXFF);
    delay (200);
  }

  KBX.Lcd.setPrintUTF8(false);
  delay(4000);

  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  // Same again but with colours that show bounding boxes
  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


  header("With background", TFT_DARKGREY);

  KBX.Lcd.setTextColor(TFT_YELLOW, TFT_BLACK);

  KBX.Lcd.setTextDatum(TC_DATUM); // Centre text on x,y position

  xpos = KBX.Lcd.width() / 2; // Half the screen width
  ypos = 32;

  KBX.Lcd.setPrintUTF8(true);
  //KBX.Lcd.setFreeFont(FSB9);                              // Select the font
  KBX.Lcd.setUTF8Font(CF_KN_REG_09_EN,CF_KN_REG_09_TH,NULL);
  KBX.Lcd.drawString("Kanit คณิต 9", xpos, ypos, GFXFF);  // Draw the text string in the selected GFX free font
  ypos += KBX.Lcd.fontHeight(GFXFF);                        // Get the font height and move ypos down

  //KBX.Lcd.setFreeFont(FSB12);
  KBX.Lcd.setUTF8Font(CF_KN_REG_12_EN,CF_KN_REG_12_TH,NULL);
  KBX.Lcd.drawString("Kanit คณิต 12", xpos, ypos, GFXFF);
  ypos += KBX.Lcd.fontHeight(GFXFF);

  //KBX.Lcd.setFreeFont(FSB18);
  KBX.Lcd.setUTF8Font(CF_KN_REG_18_EN,CF_KN_REG_18_TH,NULL);
  KBX.Lcd.drawString("Kanit คณิต 18", xpos, ypos, GFXFF);
  ypos += KBX.Lcd.fontHeight(GFXFF);

  //KBX.Lcd.setFreeFont(FSBI24);
  KBX.Lcd.setUTF8Font(CF_KN_REG_24_EN,CF_KN_REG_24_TH,NULL);
  KBX.Lcd.drawString("Kanit คณิต 24", xpos, ypos, GFXFF);
  ypos += KBX.Lcd.fontHeight(GFXFF);

  // Set text padding to 100 pixels wide area to over-write old values on screen
  KBX.Lcd.setTextPadding(100);
  for (int i = 0; i <= 20; i++) {
    KBX.Lcd.drawFloat(i / 10.0, 1, xpos, ypos, GFXFF);
    delay (200);
  }

  KBX.Lcd.setPrintUTF8(false);
  delay(4000);

  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  // Now show setting the 12 datum positions works with free fonts
  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  // Numbers, floats and strings can be drawn relative to a datum
  header("Text with a datum", TFT_BLACK);
  KBX.Lcd.setPrintUTF8(true);
  KBX.Lcd.setTextColor(TFT_LIGHTGREY, TFT_BLACK);
  //KBX.Lcd.setFreeFont(FSS12);
  KBX.Lcd.setUTF8Font(CF_KN_REG_12_EN,CF_KN_REG_12_TH,NULL);
  KBX.Lcd.setTextDatum(TL_DATUM);
  KBX.Lcd.drawString("[ซ้าย-บน]", 160, 120, GFXFF);
  drawDatumMarker(160,120);
  delay(1000);

  KBX.Lcd.fillRect(0, 80, 320, 80, TFT_BLACK);
  KBX.Lcd.setTextDatum(TC_DATUM);
  KBX.Lcd.drawString("[กลาง-บน]", 160, 120, GFXFF);
  drawDatumMarker(160,120);
  delay(1000);

  KBX.Lcd.fillRect(0, 80, 320, 80, TFT_BLACK);
  KBX.Lcd.setTextDatum(TR_DATUM);
  KBX.Lcd.drawString("[ขวา-บน]", 160, 120, GFXFF);
  drawDatumMarker(160,120);
  delay(1000);

  KBX.Lcd.fillRect(0, 80, 320, 80, TFT_BLACK);
  KBX.Lcd.setTextDatum(ML_DATUM);
  KBX.Lcd.drawString("[ซ้าย-กลาง]", 160, 120, GFXFF);
  drawDatumMarker(160,120);
  delay(1000);

  KBX.Lcd.fillRect(0, 80, 320, 80, TFT_BLACK);
  KBX.Lcd.setTextDatum(MC_DATUM);
  KBX.Lcd.drawString("[กลาง-กลาง]", 160, 120, GFXFF);
  drawDatumMarker(160,120);
  delay(1000);

  KBX.Lcd.fillRect(0, 80, 320, 80, TFT_BLACK);
  KBX.Lcd.setTextDatum(MR_DATUM);
  KBX.Lcd.drawString("[ขวา-กลาง]", 160, 120, GFXFF);
  drawDatumMarker(160,120);
  delay(1000);

  KBX.Lcd.fillRect(0, 80, 320, 80, TFT_BLACK);
  KBX.Lcd.setTextDatum(BL_DATUM);
  KBX.Lcd.drawString("[ซ้าย-ล่าง]", 160, 120, GFXFF);
  drawDatumMarker(160,120);
  delay(1000);

  KBX.Lcd.fillRect(0, 80, 320, 80, TFT_BLACK);
  KBX.Lcd.setTextDatum(BC_DATUM);
  KBX.Lcd.drawString("[กลาง-ล่าง]", 160, 120, GFXFF);
  drawDatumMarker(160,120);
  delay(1000);

  KBX.Lcd.fillRect(0, 80, 320, 80, TFT_BLACK);
  KBX.Lcd.setTextDatum(BR_DATUM);
  KBX.Lcd.drawString("[ขวา-ล่าง]", 160, 120, GFXFF);
  drawDatumMarker(160,120);
  delay(1000);

  KBX.Lcd.fillRect(0, 80, 320, 80, TFT_BLACK);
  KBX.Lcd.setTextDatum(L_BASELINE);
  KBX.Lcd.drawString("[ซ้าย-ฐาน]", 160, 120, GFXFF);
  drawDatumMarker(160,120);
  delay(1000);

  KBX.Lcd.fillRect(0, 80, 320, 80, TFT_BLACK);
  KBX.Lcd.setTextDatum(C_BASELINE);
  KBX.Lcd.drawString("[กลาง-ฐาน]", 160, 120, GFXFF);
  drawDatumMarker(160,120);
  delay(1000);

  KBX.Lcd.fillRect(0, 80, 320, 80, TFT_BLACK);
  KBX.Lcd.setTextDatum(R_BASELINE);
  KBX.Lcd.drawString("[ขวา-ฐาน]", 160, 120, GFXFF);
  drawDatumMarker(160,120);
  //delay(1000);


  //delay(1000);


  //while(1);
  delay(8000);

}

// Print the header for a display screen
void header(const char *string, uint16_t color)
{
  KBX.Lcd.fillScreen(color);
  KBX.Lcd.setTextSize(1);
  KBX.Lcd.setTextColor(TFT_MAGENTA, TFT_BLUE);
  KBX.Lcd.fillRect(0, 0, 320, 30, TFT_BLUE);
  KBX.Lcd.setTextDatum(MC_DATUM);
  KBX.Lcd.drawString(string, 160, 15, 4); // Font 4 for fast drawing with background
}

// Draw a + mark centred on x,y
void drawDatumMarker(int x, int y)
{
  KBX.Lcd.drawLine(x - 5, y, x + 5, y, TFT_GREEN);
  KBX.Lcd.drawLine(x, y - 5, x, y + 5, TFT_GREEN);
}


// There follows a crude way of flagging that this example sketch needs fonts which
// have not been enbabled in the User_Setup.h file inside the TFT_HX8357 library.
//
// These lines produce errors during compile time if settings in User_Setup are not correct
//
// The error will be "does not name a type" but ignore this and read the text between ''
// it will indicate which font or feature needs to be enabled
//
// Either delete all the following lines if you do not want warnings, or change the lines
// to suit your sketch modifications.

#ifndef LOAD_GLCD
//ERROR_Please_enable_LOAD_GLCD_in_User_Setup
#endif

#ifndef LOAD_FONT2
//ERROR_Please_enable_LOAD_FONT2_in_User_Setup!
#endif

#ifndef LOAD_FONT4
//ERROR_Please_enable_LOAD_FONT4_in_User_Setup!
#endif

#ifndef LOAD_FONT6
//ERROR_Please_enable_LOAD_FONT6_in_User_Setup!
#endif

#ifndef LOAD_FONT7
//ERROR_Please_enable_LOAD_FONT7_in_User_Setup!
#endif

#ifndef LOAD_FONT8
//ERROR_Please_enable_LOAD_FONT8_in_User_Setup!
#endif

#ifndef LOAD_GFXFF
ERROR_Please_enable_LOAD_GFXFF_in_User_Setup!
#endif

