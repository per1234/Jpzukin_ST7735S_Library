/*
 * ST7735S.h
 */

#ifndef _JPZUKIN_H_
#define _JPZUKIN_H_

#include <arduino.h>
#include <SPI.h>

/*
 *  System Function Command List
 */
const uint8_t ST7735S_NOP     = 0x00;   // No Operation 
const uint8_t ST7735S_SWRESET = 0x01;   // Software Reset
const uint8_t ST7735S_SLPIN   = 0x10;   // Sleep In
const uint8_t ST7735S_SLPOUT  = 0x11;   // Sleep Out
const uint8_t ST7735S_INVOFF  = 0x20;   // Display Inversion Off
const uint8_t ST7735S_INVON   = 0x21;   // Display Inversion On
const uint8_t ST7735S_DISPOFF = 0x28;   // Display Off 
const uint8_t ST7735S_DISPON  = 0x29;   // Display On 
const uint8_t ST7735S_CASET   = 0x2A;   // Column Address Set
const uint8_t ST7735S_RASET   = 0x2B;   // Row Address Set
const uint8_t ST7735S_RAMWR   = 0x2C;   // Memory Write
const uint8_t ST7735S_MADCTL  = 0x36;   // Memory Data Access Control
const uint8_t ST7735S_COLMOD  = 0x3A;   // Interface Pixel Format

class ST7735S {

  public:
    ST7735S(uint8_t csx, uint8_t dcx, uint8_t reset);

    int16_t Height() { return _height; }
    int16_t Width()  { return _width;  }

    void begin();
    void setAddrWindow();

  private:

    void writeCommand(uint8_t command);
    void writeParam(uint8_t param);
    void writeData(uint16_t data);

    void chipSelect()   { digitalWrite(_csx, LOW);  }
    void chipDeselect() { digitalWrite(_csx, HIGH); }
    void modeCommand()  { digitalWrite(_dcx, LOW);  }
    void modeData()     { digitalWrite(_dcx, HIGH); }

    void hardwareReset();
    void init();

    SPISettings _mySPISetting = SPISettings(8000000, MSBFIRST, SPI_MODE0);
    int16_t  _width;
    int16_t  _height;
    uint8_t  _csx;
    uint8_t  _dcx;
    uint8_t  _reset;

    const int16_t PANEL_WIDTH  = 128;
    const int16_t PANEL_HEIGHT = 160;
};

#endif

