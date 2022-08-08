#include "leds.h"

#define LEDS_OFFSET     1
#define FIRST_BIT_ON    1
#define FIRST_ALL_OFF   0
#define ALL_LEDS_ON     0xFFFF
#define ALL_LEDS_OFF    0x0000

#define CHECK_BIT(var,pos) (((var)>>(pos)) & 1)

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
    *puerto = ALL_LEDS_ON;
}

void leds_turnOffAllLeds()
{
    *puerto = ALL_LEDS_OFF;
}

uint8_t leds_checkStatus(uint8_t pin)
{
    return CHECK_BIT(*puerto, pin-1);
}