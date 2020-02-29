//  STM32_MAX6675 v1.0
//  Alexander Liman
//  liman324@yandex.ru
//  rcl-radio.ru
//  Библиотека основана на https://github.com/adafruit/MAX6675-library

#ifndef  STM32_MAX6675_H
#define  STM32_MAX6675_H

#include <Arduino.h>

class  STM32_MAX6675
  {
    public:
  STM32_MAX6675(int8_t, int8_t, int8_t);
  double readCelsius(void);
    private:
     uint8_t spiread(void);
     uint8_t sclk, cs, so;
  };
#endif
