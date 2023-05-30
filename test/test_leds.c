#include "unity.h"
#include "leds.h"
#include <stdint.h>

// *** REFERENCIA DE ASSERT UNITY https://github.com/ThrowTheSwitch/Unity  ***

static uint16_t puerto_virtual;

void setUp(void) //es una función de Ceedling para ejecutarse siempre que comienza el test
{
    leds_inicia(&puerto_virtual);
}

// Con la inicialización todos los LEDs quedan apagados.
void test_todos_los_leds_inician_apagados(void)
{
    uint16_t puerto_virtual = 0xFFFF;
    leds_inicia(&puerto_virtual);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

//Con todos los leds apagados, prendo el led 2, verifico que el bit 1 vale 1
void test_prender_un_led(void)
{
    leds_prende_uno(2);
    TEST_ASSERT_EQUAL_HEX16(0x0002, puerto_virtual);
}

//Con el led 2 prendido, apago el led 2, verifico que el bit 1 vale 0
void test_prender_y_apagar_un_led(void)
{
    leds_prende_uno(2);
    leds_apaga_uno(2);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

//Con todos los leds apagados, prendo el 3, prendo el 5, apago el 3 y apago el 7, deberían quedar el bit 4 en 1 y el resto en 0
void test_prender_y_apagar_varios_leds(void)
{
    leds_prende_uno(3);
    leds_prende_uno(5);
    leds_apaga_uno(3);
    leds_apaga_uno(7);
    TEST_ASSERT_EQUAL_HEX16(0x0010, puerto_virtual);
}

//Prendo un led, consulto el estado y tiene que estar prendido
void test_prede_un_led_consulto_estado(void)
{
    leds_prende_uno(2);
    TEST_ASSERT_TRUE(leds_estado_led(2));
}

//Apago un led, consulto el estado y tiene que estar apagado
void test_apaga_un_led_consulto_estado(void)
{
    leds_apaga_uno(2);
    TEST_ASSERT_FALSE(leds_estado_led(2));
}

//Con todos los leds apagados, enciendo todos los leds y verifico que se encienden
void test_prende_todos_los_leds(void)
{

    leds_prende_todos();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, puerto_virtual);
}

//Con todos los leds encendidos, apago todos los leds y verifico que se apagan
void test_apaga_todos_los_leds_y_consulto_estado(void)
{
    leds_prende_todos();
    leds_apago_todos();
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}