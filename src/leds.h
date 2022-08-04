#include <stdint.h>
//#include "errores.h"

void leds_create(uint16_t * ledAddr);
void leds_turnSingleLedOn(uint8_t outputVal);
void leds_turnSingleLedOff(uint8_t ouputVal);
void leds_turnOnAllLeds();
void leds_turnOffAllLeds();
uint8_t leds_checkStatus(uint8_t pin);