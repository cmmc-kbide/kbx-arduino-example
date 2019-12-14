/***********************************************************************************
 * ESP32Spiram.h - Library designed to manage SRAM Memory chip 23LC1024 via HSPI *
 * Created by Giancarlo Bacchio - August 15, 2015.                                 *
 * see datasheet at http://ww1.microchip.com/downloads/en/DeviceDoc/25142A.pdf     *
 * Released into the public domain.                                                *
 ***********************************************************************************/


/* 
 In this library, the Ram is connected to HSPI using the following pins:
(see SPI Mode, para3.8 pg.13 of 23LC1024 datasheet)
		pin1	   C/S-->GPIO15
		pin2	  MISO-->GPIO12
		pin3       N/C-->Gnd
		pin4	   Vss-->Gnd
		pin5	  MOSI-->GPIO13
		pin6	   SCK-->GPIO14
		pin7	  HOLD-->V+
		pin8	   Vcc-->V+

************************************************************************************/



#include "ESP32Spiram.h"

ESP32Spiram Spiram;

// setup of C/S line as per HSPI default
ESP32Spiram::ESP32Spiram() {
      Cs=15; // default value for HSPI port
      clkSpeed=20e6; // The 23LC1024 supports theorically up to 20MHz
}

ESP32Spiram::ESP32Spiram(int cs, int clockspeedhz) {
      Cs = cs;
      clkSpeed = clockspeedhz;
}

// Activate the library setting up ByteMode of operation (see 2.2 pg.5)
void ESP32Spiram::begin(void)	{

      SPI.begin();
      pinMode (Cs, OUTPUT);
      digitalWrite(Cs, HIGH);

      digitalWrite(Cs, HIGH);
      delay(50);
      digitalWrite(Cs, LOW);
      delay(50);
      digitalWrite(Cs, HIGH);
      setByteMode();
}

/***********************************************
 * this function Read SRAM                     *
 *   - addr: address to start read             *
 *   - *buff: list where read bytes are copied *
 *   - len: amount of bytes to read            *
 * (see sequence in figure 2-1)                *
 ***********************************************/


void ESP32Spiram::read(uint32_t addr, uint8_t *buff, int len) {
        switch (opMode) {
            case REG_BM:
                readBytes(addr, buff, len);
                break;
            case REG_SM:
                readSeq(addr, buff, len);
                break;
            default:
                readBytes(addr, buff, len);
	}
}


void ESP32Spiram::readBytes(uint32_t addr, uint8_t *buff, int len) {
        uint32_t instr;
        int i=0;
        while (len--) {
          instr=(READ<<24)|(addr++&0x00ffffff);
          beginTrans_();
          transfer32(instr);   // code to set Read mode in the SRAM
          buff[i++]=transfer8(0);
          endTrans_();
        }
}

void ESP32Spiram::readSeq(uint32_t addr, uint8_t *buff, int len) {
        uint32_t instr;
        int i=0;
        instr=(READ<<24)|(addr++&0x00ffffff);
        beginTrans_();
        transfer32(instr);   // code to set Read mode in the SRAM
        while (len--) {
          buff[i++]=transfer8(0);
        }
        endTrans_();
}


/**************************************
 * this function Write in the SRAM    *
 *   - addr: address to start write   *
 *   - *buff: list of bytes to write  *
 *   - len: amount of bytes to write  *
 * (see sequence in figure 2-2)       *
 **************************************/

void ESP32Spiram::write(uint32_t addr, uint8_t *buff, int len) {
        switch (opMode) {
            case REG_BM:
                writeBytes(addr, buff, len);
                break;
            case REG_SM:
                writeSeq(addr, buff, len);
                break;
            default:
                writeBytes(addr, buff, len);
	}
}

void ESP32Spiram::writeBytes(uint32_t addr, uint8_t *buff, int len) {
        uint32_t instr;
        int i=0;
        while (len--) {
          instr=(WRITE<<24)|(addr++&0x00ffffff);
          beginTrans_();
          transfer32(instr);   // code to set Read mode in the SRAM
          transfer8(buff[i++]);
          endTrans_();
        }
}

void ESP32Spiram::writeSeq(uint32_t addr, uint8_t *buff, int len) {
        uint32_t instr;
        int i=0;
        instr=(WRITE<<24)|(addr++&0x00ffffff);
        beginTrans_();
        transfer32(instr);   // code to set Read mode in the SRAM
        while (len--) {
          transfer8(buff[i++]);
        }
        endTrans_();
}


/*************************************************
 * this function Read the configuration register *
 *************************************************/

uint8_t ESP32Spiram::readReg_(void) {
       beginTrans_();
       transfer8(RDMR);
       uint8_t reg=transfer8(0);
       endTrans_();
       return reg;
}

/**************************************************
 * this function Write the configuration register *
 **************************************************/

void ESP32Spiram::writeReg_(uint8_t reg) {
       beginTrans_();
       transfer8(WRMR);
       transfer8(reg);
       endTrans_();
}

/********************************
 * this function reset the SRAM *
 ********************************/

void ESP32Spiram::reset_(void) {  
       beginTrans_();
       SPI.transfer(RSTIO);
       endTrans_();
}

uint8_t ESP32Spiram::transfer8(uint8_t data){
 /* FOR DEBUG:
  Serial.print("sending: ");
  Serial.println(data,BIN);
  data = SPI.transfer(data);
  Serial.print("receving: ");
  Serial.println(data,BIN);
  return data;*/
  return SPI.transfer(data);
}

uint16_t ESP32Spiram::transfer16(uint16_t data){
        union {
            uint16_t val;
            struct {
                    uint8_t lsb;
                    uint8_t msb;
            };
        } in, out;
        in.val = data;

        out.msb = transfer8(in.msb);
        out.lsb = transfer8(in.lsb);

        return out.val;
}

uint32_t ESP32Spiram::transfer32(uint32_t data){
        union {
            uint32_t val;
            struct {
                    uint16_t lsb;
                    uint16_t msb;
            };
        } in, out;
        in.val = data;

        out.msb = transfer16(in.msb);
        out.lsb = transfer16(in.lsb);

        return out.val;
}

void ESP32Spiram::setByteMode(void){
	writeReg_(REG_BM);
        opMode = getMode();
}

void ESP32Spiram::setPageMode(void){
        writeReg_(REG_PM);
	opMode = getMode();
}

void ESP32Spiram::setSeqMode(void){
        writeReg_(REG_SM);
        opMode = getMode();
}

uint8_t ESP32Spiram::getMode(void){
        return readReg_();
}

void ESP32Spiram::beginTrans_(void){
        SPI.beginTransaction(SPISettings(clkSpeed, MSBFIRST, SPI_MODE0));
        digitalWrite(Cs, LOW);
}

void ESP32Spiram::endTrans_(void){
        digitalWrite(Cs, HIGH);
        SPI.endTransaction();  
}
