#include <STM32_MAX6675.h>

STM32_MAX6675::STM32_MAX6675(int8_t SCLK, int8_t CS, int8_t SO) {
  sclk = SCLK;
  cs = CS;
  so = SO;
  pinMode(cs, OUTPUT);
  pinMode(sclk, OUTPUT); 
  pinMode(so, INPUT);
  digitalWrite(cs, HIGH);
  }

double STM32_MAX6675::readCelsius(void) {
  uint16_t data;
  digitalWrite(cs, LOW);delay(1);
  data = spiread();data <<= 8;data |= spiread();
  digitalWrite(cs, HIGH);
  if(data & 0x4){return data = 9999;}
  data >>= 3;
  return data*0.25;
}

byte STM32_MAX6675::spiread(void) { 
  int i;byte w = 0;
  for (i=7; i>=0; i--){
    digitalWrite(sclk, LOW);delay(1);
    if (digitalRead(so)){w |= (1 << i);}
    digitalWrite(sclk, HIGH);
    delay(1);
  }
  return w;
}
