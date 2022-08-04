/*
    Prender todos los LEDS de una vez
    Apagar todos los LEDS de una vez
    Consultar el estado de un LED que esta encendido
    Consultar el estado de un LED que esta apagado
    
    Revisar limites de los parametros
    Revisar parametros fuera de los limites
*/


#include "unity.h"
#include "leds.h"

uint16_t ledsVirtuales;

void setUp(void)
{
    leds_create(&ledsVirtuales);
}

void test_todos_los_leds_inician_apagados(void)
{
    uint16_t ledsVirtuales = 0xFFFF;
    leds_create(&ledsVirtuales);
    TEST_ASSERT_EQUAL(0x0000, ledsVirtuales);
}

void test_prender_un_led(void)
{
    leds_turnSingleLedOn(3);
    TEST_ASSERT_EQUAL(1 << 2, ledsVirtuales);
}

void test_apagar_un_led(void)
{
    leds_turnSingleLedOn(3);
    leds_turnSingleLedOff(3);
    TEST_ASSERT_EQUAL(0, ledsVirtuales);
}

void test_prender_apagar_led(void)
{
    leds_turnSingleLedOn(3);
    leds_turnSingleLedOn(7);
    leds_turnSingleLedOff(7);
    TEST_ASSERT_EQUAL(1 << 2, ledsVirtuales);
}

void test_prender_todos_leds_de_una(void)
{
    leds_turnOnAllLeds();
    TEST_ASSERT_EQUAL(0xFFFF, ledsVirtuales);
}

void test_apagar_todos_leds(void)
{
    leds_turnOnAllLeds();
    leds_turnOffAllLeds();
    TEST_ASSERT_EQUAL(0x0000, ledsVirtuales);
}

//Consultar el estado de un LED que esta encendido
void test_consultar_estado_led_on(void)
{
    leds_turnSingleLedOn(3);
    uint8_t flag = leds_checkStatus(3);
    TEST_ASSERT_EQUAL_HEX(1, flag);
}