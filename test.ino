#include <STM32_MAX6675.h>

int thermoDO = PB7;
int thermoCS = PB9;
int thermoCLK = PB8;

STM32_MAX6675 max6675(thermoCLK, thermoCS, thermoDO);

void setup() {
  Serial.begin(9600);
}

void loop() {
  
   Serial.print("C = "); 
   Serial.println(max6675.readCelsius());
   delay(1000);
}
