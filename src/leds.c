#include "leds.h"

#define LEDS_OFFSET     1
#define FIRST_BIT_ON    1
#define FIRST_ALL_OFF    0

static uint16_t * puerto;

static uint16_t ledToMask(uint8_t led)
{
    return FIRST_BIT_ON << (led - 1);
}

void leds_create(uint16_t * ledAddr)
{
    puerto = ledAddr;
    *puerto = FIRST_ALL_OFF;
}

void leds_turnSingleLedOn(uint8_t bitPos)
{
    *puerto |= ledToMask(bitPos);
}

void leds_turnSingleLedOff(uint8_t bitPos)
{
    *puerto &= ~ledToMask(bitPos);
}

void leds_turnOnAllLeds()
{
    *puerto = 0xFFFF;
}

void leds_turnOffAllLeds()
{
    *puerto = 0x0000;
}

uint8_t leds_checkStatus(uint8_t pin)
{
    uint16_t valBit;
    valBit = *puerto >> pin;
    if(valBit)
        return 1;
    return 0;
}