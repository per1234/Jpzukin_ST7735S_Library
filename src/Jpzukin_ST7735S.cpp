/*
 * ST7735S.cpp
 */

#include <arduino.h>
#include <SPI.h>
#include "jpzukin_ST7735S.h"

ST7735S::ST7735S(uint8_t csx, uint8_t dcx, uint8_t reset)
{
  _height = PANEL_HEIGHT;
  _width  = PANEL_WIDTH;
  _csx    = csx;
  _dcx    = dcx;
  _reset  = reset;
}

inline void ST7735S::writeCommand(uint8_t command)
{
  modeCommand();
  SPI.transfer(command);
}

inline void ST7735S::writeParam(uint8_t param)
{
  modeData();
  SPI.transfer(param);
}

void ST7735S::begin()
{
  pinMode(_csx,   OUTPUT);
  pinMode(_dcx,   OUTPUT);
  pinMode(_reset, OUTPUT);

  SPI.begin();

  hardwareReset();
  init();
}
 
void ST7735S::hardwareReset()
{
  digitalWrite(_reset, HIGH); delay(20);
  digitalWrite(_reset, LOW);  delay(20);
  digitalWrite(_reset, HIGH); delay(150);
}

void ST7735S::init()
{
  SPI.beginTransaction(_mySPISetting);
  chipSelect();

  writeCommand(ST7735S_SLPOUT); delay(200);
  writeCommand(ST7735S_DISPON);

  chipDeselect();
  SPI.endTransaction();
}

