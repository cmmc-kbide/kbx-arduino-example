#include <kbxui.h>

void setup() {
  // put your setup code here, to run once:
  // put your setup code here, to run once:
  KBX.begin();
  KBX.Lcd.setRotation(1);

    // First we test them with a background colour set
  KBX.Lcd.setTextSize(1);
  KBX.Lcd.fillScreen(TFT_BLACK);
  KBX.Lcd.setTextColor(TFT_GREEN, TFT_BLACK);

  int y = 0;
  KBX.Lcd.drawString("Font 1 ABCabc 012345", 0, y, 1); y += 8+2;
  KBX.Lcd.drawString("Font 2 ABCabc 012345", 0, y, 2); y += 16+2;
  KBX.Lcd.drawString("Font 4 ABCabc 012345", 0, y, 4); y += 26+2;
  KBX.Lcd.drawString("6 0123456789", 0, y, 6); y += 48+2;
  KBX.Lcd.drawString("7 01234567", 0, y, 7); y += 48+2;
  KBX.Lcd.drawString("8 0123", 0, y, 8); y += 75+2;
}

void loop() {
  // put your main code here, to run repeatedly:

}
