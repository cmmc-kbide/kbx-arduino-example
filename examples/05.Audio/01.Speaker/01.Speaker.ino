#include <kbxui.h>

#define NOTE_D0 -1
#define NOTE_D1 294
#define NOTE_D2 330
#define NOTE_D3 350
#define NOTE_D4 393
#define NOTE_D5 441
#define NOTE_D6 495
#define NOTE_D7 556

#define NOTE_DL1 147
#define NOTE_DL2 165
#define NOTE_DL3 175
#define NOTE_DL4 196
#define NOTE_DL5 221
#define NOTE_DL6 248
#define NOTE_DL7 278

#define NOTE_DH1 589
#define NOTE_DH2 661
#define NOTE_DH3 700
#define NOTE_DH4 786
#define NOTE_DH5 882
#define NOTE_DH6 990
#define NOTE_DH7 112

extern const unsigned char m5stack_startup_music[];

void setup() {
  // Initialize the M5Stack object
  KBX.begin();
  KBX.Lcd.setRotation(1);
  
  KBX.Lcd.printf("KBXStack Speaker test:\r\n");
  KBX.Speaker.setVolume(10);
  //KBX.Speaker.playMusic(m5stack_startup_music, 25000);
}

void loop() {
  if(KBX.BtnA.wasPressed()) {
    KBX.Lcd.printf("wasPressed A \r\n");
    KBX.Speaker.beep(); //beep
    //KBX.Speaker.tone(4000, 500); //frequency 3000, with a duration of 200ms
  }

  if(KBX.BtnB.wasPressed())
  {
    KBX.Lcd.printf("wasPressed B \r\n");
    KBX.Speaker.tone(3000, 500); //frequency 3000, with a duration of 200ms
  }

  if(KBX.BtnC.wasPressed())
  {
    KBX.Lcd.printf("wasPressed C \r\n");
    //KBX.Speaker.tone(2000, 500); //frequency 3000, with a duration of 200ms
    KBX.Speaker.playMusic(m5stack_startup_music, 25000); //play the M5Stack startup sound
  }
  delay( 10 );
  KBX.update();
}

