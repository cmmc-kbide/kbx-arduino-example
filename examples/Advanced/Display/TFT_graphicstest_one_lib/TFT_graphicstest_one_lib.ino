/*
 Adapted from the Adafruit graphicstest sketch, see orignal header at end
 of sketch.

 This sketch uses the GLCD font (font 1) only.

 Make sure all the display driver and pin comnenctions are correct by
 editting the User_Setup.h file in the TFT_eSPI library folder.

 #########################################################################
 ###### DON'T FORGET TO UPDATE THE User_Setup.h FILE IN THE LIBRARY ######
 #########################################################################
*/

#include <KBXUI.h>

unsigned long total = 0;
unsigned long tn = 0;
void setup() {

  KBX.begin();

  Serial.println(""); Serial.println("");
  Serial.println("TFT_eSPI library test!");

  tn = micros();
  KBX.Lcd.fillScreen(TFT_BLACK);

  yield(); Serial.println(F("Benchmark                Time (microseconds)"));

  yield(); Serial.print(F("Screen fill              "));
  yield(); Serial.println(testFillScreen());
  //total+=testFillScreen();
  //delay(500);

  yield(); Serial.print(F("Text                     "));
  yield(); Serial.println(testText());
  //total+=testText();
  //delay(3000);

  yield(); Serial.print(F("Lines                    "));
  yield(); Serial.println(testLines(TFT_CYAN));
  //total+=testLines(TFT_CYAN);
  //delay(500);

  yield(); Serial.print(F("Horiz/Vert Lines         "));
  yield(); Serial.println(testFastLines(TFT_RED, TFT_BLUE));
  //total+=testFastLines(TFT_RED, TFT_BLUE);
  //delay(500);

  yield(); Serial.print(F("Rectangles (outline)     "));
  yield(); Serial.println(testRects(TFT_GREEN));
  //total+=testRects(TFT_GREEN);
  //delay(500);

  yield(); Serial.print(F("Rectangles (filled)      "));
  yield(); Serial.println(testFilledRects(TFT_YELLOW, TFT_MAGENTA));
  //total+=testFilledRects(TFT_YELLOW, TFT_MAGENTA);
  //delay(500);

  yield(); Serial.print(F("Circles (filled)         "));
  yield(); Serial.println(testFilledCircles(10, TFT_MAGENTA));
  //total+= testFilledCircles(10, TFT_MAGENTA);

  yield(); Serial.print(F("Circles (outline)        "));
  yield(); Serial.println(testCircles(10, TFT_WHITE));
  //total+=testCircles(10, TFT_WHITE);
  //delay(500);

  yield(); Serial.print(F("Triangles (outline)      "));
  yield(); Serial.println(testTriangles());
  //total+=testTriangles();
  //delay(500);

  yield(); Serial.print(F("Triangles (filled)       "));
  yield(); Serial.println(testFilledTriangles());
  //total += testFilledTriangles();
  //delay(500);

  yield(); Serial.print(F("Rounded rects (outline)  "));
  yield(); Serial.println(testRoundRects());
  //total+=testRoundRects();
  //delay(500);

  yield(); Serial.print(F("Rounded rects (filled)   "));
  yield(); Serial.println(testFilledRoundRects());
  //total+=testFilledRoundRects();
  //delay(500);

  yield(); Serial.println(F("Done!")); yield();
  //Serial.print(F("Total = ")); Serial.println(total);
  
  //yield();Serial.println(millis()-tn);
}

void loop(void) {
  for (uint8_t rotation = 0; rotation < 8; rotation++) {
    KBX.Lcd.setRotation(rotation);
    Serial.printf("rotation:%d\r\n", rotation);
    testText();
    delay(2000);
  }
}


unsigned long testFillScreen() {
  unsigned long start = micros();
  KBX.Lcd.fillScreen(TFT_BLACK);
  KBX.Lcd.fillScreen(TFT_RED);
  KBX.Lcd.fillScreen(TFT_GREEN);
  KBX.Lcd.fillScreen(TFT_BLUE);
  KBX.Lcd.fillScreen(TFT_BLACK);
  return micros() - start;
}

unsigned long testText() {
  KBX.Lcd.fillScreen(TFT_BLACK);
  unsigned long start = micros();
  KBX.Lcd.setCursor(0, 0);
  KBX.Lcd.setTextColor(TFT_WHITE);  KBX.Lcd.setTextSize(1);
  KBX.Lcd.println("Hello World!");
  KBX.Lcd.setTextColor(TFT_YELLOW); KBX.Lcd.setTextSize(2);
  KBX.Lcd.println(1234.56);
  KBX.Lcd.setTextColor(TFT_RED);    KBX.Lcd.setTextSize(3);
  KBX.Lcd.println(0xDEADBEEF, HEX);
  KBX.Lcd.println();
  KBX.Lcd.setTextColor(TFT_GREEN);
  KBX.Lcd.setTextSize(5);
  KBX.Lcd.println("Groop");
  KBX.Lcd.setTextSize(2);
  KBX.Lcd.println("I implore thee,");
  //KBX.Lcd.setTextColor(TFT_GREEN,TFT_BLACK);
  KBX.Lcd.setTextSize(1);
  KBX.Lcd.println("my foonting turlingdromes.");
  KBX.Lcd.println("And hooptiously drangle me");
  KBX.Lcd.println("with crinkly bindlewurdles,");
  KBX.Lcd.println("Or I will rend thee");
  KBX.Lcd.println("in the gobberwarts");
  KBX.Lcd.println("with my blurglecruncheon,");
  KBX.Lcd.println("see if I don't!");
  return micros() - start;
}

unsigned long testLines(uint16_t color) {
  unsigned long start, t;
  int           x1, y1, x2, y2,
                w = KBX.Lcd.width(),
                h = KBX.Lcd.height();

  KBX.Lcd.fillScreen(TFT_BLACK);

  x1 = y1 = 0;
  y2    = h - 1;
  start = micros();
  for (x2 = 0; x2 < w; x2 += 6) KBX.Lcd.drawLine(x1, y1, x2, y2, color);
  x2    = w - 1;
  for (y2 = 0; y2 < h; y2 += 6) KBX.Lcd.drawLine(x1, y1, x2, y2, color);
  t     = micros() - start; // fillScreen doesn't count against timing

  KBX.Lcd.fillScreen(TFT_BLACK);

  x1    = w - 1;
  y1    = 0;
  y2    = h - 1;
  start = micros();
  for (x2 = 0; x2 < w; x2 += 6) KBX.Lcd.drawLine(x1, y1, x2, y2, color);
  x2    = 0;
  for (y2 = 0; y2 < h; y2 += 6) KBX.Lcd.drawLine(x1, y1, x2, y2, color);
  t    += micros() - start;

  KBX.Lcd.fillScreen(TFT_BLACK);

  x1    = 0;
  y1    = h - 1;
  y2    = 0;
  start = micros();
  for (x2 = 0; x2 < w; x2 += 6) KBX.Lcd.drawLine(x1, y1, x2, y2, color);
  x2    = w - 1;
  for (y2 = 0; y2 < h; y2 += 6) KBX.Lcd.drawLine(x1, y1, x2, y2, color);
  t    += micros() - start;

  KBX.Lcd.fillScreen(TFT_BLACK);

  x1    = w - 1;
  y1    = h - 1;
  y2    = 0;
  start = micros();
  for (x2 = 0; x2 < w; x2 += 6) KBX.Lcd.drawLine(x1, y1, x2, y2, color);
  x2    = 0;
  for (y2 = 0; y2 < h; y2 += 6) KBX.Lcd.drawLine(x1, y1, x2, y2, color);

  return micros() - start;
}

unsigned long testFastLines(uint16_t color1, uint16_t color2) {
  unsigned long start;
  int           x, y, w = KBX.Lcd.width(), h = KBX.Lcd.height();

  KBX.Lcd.fillScreen(TFT_BLACK);
  start = micros();
  for (y = 0; y < h; y += 5) KBX.Lcd.drawFastHLine(0, y, w, color1);
  for (x = 0; x < w; x += 5) KBX.Lcd.drawFastVLine(x, 0, h, color2);

  return micros() - start;
}

unsigned long testRects(uint16_t color) {
  unsigned long start;
  int           n, i, i2,
                cx = KBX.Lcd.width()  / 2,
                cy = KBX.Lcd.height() / 2;

  KBX.Lcd.fillScreen(TFT_BLACK);
  n     = min(KBX.Lcd.width(), KBX.Lcd.height());
  start = micros();
  for (i = 2; i < n; i += 6) {
    i2 = i / 2;
    KBX.Lcd.drawRect(cx - i2, cy - i2, i, i, color);
  }

  return micros() - start;
}

unsigned long testFilledRects(uint16_t color1, uint16_t color2) {
  unsigned long start, t = 0;
  int           n, i, i2,
                cx = KBX.Lcd.width()  / 2 - 1,
                cy = KBX.Lcd.height() / 2 - 1;

  KBX.Lcd.fillScreen(TFT_BLACK);
  n = min(KBX.Lcd.width(), KBX.Lcd.height());
  for (i = n - 1; i > 0; i -= 6) {
    i2    = i / 2;
    start = micros();
    KBX.Lcd.fillRect(cx - i2, cy - i2, i, i, color1);
    t    += micros() - start;
    // Outlines are not included in timing results
    KBX.Lcd.drawRect(cx - i2, cy - i2, i, i, color2);
  }

  return t;
}

unsigned long testFilledCircles(uint8_t radius, uint16_t color) {
  unsigned long start;
  int x, y, w = KBX.Lcd.width(), h = KBX.Lcd.height(), r2 = radius * 2;

  KBX.Lcd.fillScreen(TFT_BLACK);
  start = micros();
  for (x = radius; x < w; x += r2) {
    for (y = radius; y < h; y += r2) {
      KBX.Lcd.fillCircle(x, y, radius, color);
    }
  }

  return micros() - start;
}

unsigned long testCircles(uint8_t radius, uint16_t color) {
  unsigned long start;
  int           x, y, r2 = radius * 2,
                      w = KBX.Lcd.width()  + radius,
                      h = KBX.Lcd.height() + radius;

  // Screen is not cleared for this one -- this is
  // intentional and does not affect the reported time.
  start = micros();
  for (x = 0; x < w; x += r2) {
    for (y = 0; y < h; y += r2) {
      KBX.Lcd.drawCircle(x, y, radius, color);
    }
  }

  return micros() - start;
}

unsigned long testTriangles() {
  unsigned long start;
  int           n, i, cx = KBX.Lcd.width()  / 2 - 1,
                      cy = KBX.Lcd.height() / 2 - 1;

  KBX.Lcd.fillScreen(TFT_BLACK);
  n     = min(cx, cy);
  start = micros();
  for (i = 0; i < n; i += 5) {
    KBX.Lcd.drawTriangle(
      cx    , cy - i, // peak
      cx - i, cy + i, // bottom left
      cx + i, cy + i, // bottom right
      KBX.Lcd.color565(0, 0, i));
  }

  return micros() - start;
}

unsigned long testFilledTriangles() {
  unsigned long start, t = 0;
  int           i, cx = KBX.Lcd.width()  / 2 - 1,
                   cy = KBX.Lcd.height() / 2 - 1;

  KBX.Lcd.fillScreen(TFT_BLACK);
  start = micros();
  for (i = min(cx, cy); i > 10; i -= 5) {
    start = micros();
    KBX.Lcd.fillTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
                     KBX.Lcd.color565(0, i, i));
    t += micros() - start;
    KBX.Lcd.drawTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
                     KBX.Lcd.color565(i, i, 0));
  }

  return t;
}

unsigned long testRoundRects() {
  unsigned long start;
  int           w, i, i2,
                cx = KBX.Lcd.width()  / 2 - 1,
                cy = KBX.Lcd.height() / 2 - 1;

  KBX.Lcd.fillScreen(TFT_BLACK);
  w     = min(KBX.Lcd.width(), KBX.Lcd.height());
  start = micros();
  for (i = 0; i < w; i += 6) {
    i2 = i / 2;
    KBX.Lcd.drawRoundRect(cx - i2, cy - i2, i, i, i / 8, KBX.Lcd.color565(i, 0, 0));
  }

  return micros() - start;
}

unsigned long testFilledRoundRects() {
  unsigned long start;
  int           i, i2,
                cx = KBX.Lcd.width()  / 2 - 1,
                cy = KBX.Lcd.height() / 2 - 1;

  KBX.Lcd.fillScreen(TFT_BLACK);
  start = micros();
  for (i = min(KBX.Lcd.width(), KBX.Lcd.height()); i > 20; i -= 6) {
    i2 = i / 2;
    KBX.Lcd.fillRoundRect(cx - i2, cy - i2, i, i, i / 8, KBX.Lcd.color565(0, i, 0));
  }

  return micros() - start;
}

/***************************************************
  Original Adafruit text:

  This is an example sketch for the Adafruit 2.2" SPI display.
  This library works with the Adafruit 2.2" TFT Breakout w/SD card
  ----> http://www.adafruit.com/products/1480

  Check out the links above for our tutorials and wiring diagrams
  These displays use SPI to communicate, 4 or 5 pins are required to
  interface (RST is optional)
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  MIT license, all text above must be included in any redistribution
 ****************************************************/

