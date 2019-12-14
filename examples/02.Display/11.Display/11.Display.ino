#include <kbxui.h>

// the setup routine runs once when KBX-UI starts up
void setup() {
  
  // initialize the KBX-UI object
  KBX.begin();
  //KBX.Lcd.drawBitmap(0, 0, 320, 240, (uint16_t *)gImage_logoM5);
  //KBX.Lcd.drawBitmap(0, 0, 320, 240, (uint16_t *)gImage_logoKBX);
  delay(500);

  // Lcd display
  KBX.Lcd.fillScreen(WHITE);
  delay(500);
  KBX.Lcd.fillScreen(RED);
  delay(500);
  KBX.Lcd.fillScreen(GREEN);
  delay(500);
  KBX.Lcd.fillScreen(BLUE);
  delay(500);
  KBX.Lcd.fillScreen(BLACK);
  delay(500);

  // text print
  KBX.Lcd.fillScreen(BLACK);
  KBX.Lcd.setCursor(10, 10);
  KBX.Lcd.setTextColor(WHITE);
  KBX.Lcd.setTextSize(1);
  KBX.Lcd.printf("Display Test!");

  // draw graphic
  delay(1000);
  KBX.Lcd.drawRect(100, 100, 50, 50, BLUE);
  delay(1000);
  KBX.Lcd.fillRect(100, 100, 50, 50, BLUE);
  delay(1000);
  KBX.Lcd.drawCircle(100, 100, 50, RED);
  delay(1000);
  KBX.Lcd.fillCircle(100, 100, 50, RED);
  delay(1000);
  KBX.Lcd.drawTriangle(30, 30, 180, 100, 80, 150, YELLOW);
  delay(1000);
  KBX.Lcd.fillTriangle(30, 30, 180, 100, 80, 150, YELLOW);

}

// the loop routine runs over and over again forever
void loop(){

  //rand draw 
  KBX.Lcd.fillTriangle(random(KBX.Lcd.width()-1), random(KBX.Lcd.height()-1), random(KBX.Lcd.width()-1), random(KBX.Lcd.height()-1), random(KBX.Lcd.width()-1), random(KBX.Lcd.height()-1), random(0xfffe));

  KBX.update();
}
