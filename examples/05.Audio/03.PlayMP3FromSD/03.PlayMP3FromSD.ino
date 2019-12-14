//#pragma mark - Depend ESP8266Audio and ESP8266_Spiram libraries
/* 
cd ~/Arduino/libraries
git clone https://github.com/earlephilhower/ESP8266Audio
git clone https://github.com/Gianbacchio/ESP8266_Spiram
*/


#include <kbxui.h>
#include <WiFi.h>
#include "utility/audio/AudioFileSourceSD.h"
#include "utility/audio/AudioFileSourceID3.h"
#include "utility/audio/AudioGeneratorMP3.h"
#include "utility/audio/AudioOutputI2S.h"


AudioGeneratorMP3 *mp3;
AudioFileSourceSD *file;
AudioOutputI2S *out;
AudioFileSourceID3 *id3;

void setup()
{
  Serial.begin(115200);
  KBX.begin();
  WiFi.mode(WIFI_OFF); 
  delay(500);

  if(!SD.begin(TFCARD_CS_PIN)){
        KBX.Lcd.spi_init();
        KBX.Lcd.println("Card Mount Failed");
        Serial.println("Card Mount Failed");
        return;
    }
    
  KBX.Lcd.setTextFont(2);
  KBX.Lcd.println("Card Mount OK");
  Serial.println("Card Mount OK");
  KBX.Lcd.printf("Sample MP3 playback begins...\n");
  Serial.printf("Sample MP3 playback begins...\n");
  KBX.Lcd.spi_init();

  // pno_cs from https://ccrma.stanford.edu/~jos/pasp/Sound_Examples.html
  file = new AudioFileSourceSD("/pno-cs.mp3");
  id3 = new AudioFileSourceID3(file);
  out = new AudioOutputI2S(0, 1); // Output to builtInDAC
  out->SetOutputModeMono(true);
  mp3 = new AudioGeneratorMP3();
  mp3->begin(id3, out);
}

void loop()
{
  if (mp3->isRunning()) {
    if (!mp3->loop()) mp3->stop();
  } else {
    Serial.printf("MP3 done\n");
    delay(1000);
  }
}
