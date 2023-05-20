#include "inc/leds.h"
#include "/Library/Ruby/Gems/2.6.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"








static uint16_t puerto_virtual;



void setUp(void)

{

    leds_inicia(&puerto_virtual);

}





void test_todos_los_leds_inician_apagados(void)

{

    uint16_t puerto_virtual = 0xFFFF;

    leds_inicia(&puerto_virtual);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (((void*)0)), (UNITY_UINT)(19), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_un_led(void)

{

    leds_prende_uno(2);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0002)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (((void*)0)), (UNITY_UINT)(26), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_y_apagar_un_led(void)

{

    leds_prende_uno(2);

    leds_apaga_uno(2);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (((void*)0)), (UNITY_UINT)(34), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_y_apagar_varios_leds(void)

{

    leds_prende_uno(3);

    leds_prende_uno(5);

    leds_apaga_uno(3);

    leds_apaga_uno(7);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0010)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (((void*)0)), (UNITY_UINT)(44), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prede_un_led_consulto_estado(void)

{

    _Bool led_prendido = 0;

    leds_prende_uno(2);

    led_prendido = leds_estado_led(2);

    do {if ((led_prendido)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(53)));}} while(0);

}





void test_apaga_un_led_consulto_estado(void)

{

    _Bool led_prendido = 1;

    leds_apaga_uno(2);

    led_prendido = leds_estado_led(2);

}





void test_prende_todos_los_leds(void)

{



    leds_prende_todos(&puerto_virtual);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (((void*)0)), (UNITY_UINT)(69), UNITY_DISPLAY_STYLE_HEX16);

}





void test_apaga_todos_los_leds_y_consulto_estado(void)

{

    leds_prende_todos(&puerto_virtual);

    leds_apago_todos(&puerto_virtual);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (((void*)0)), (UNITY_UINT)(77), UNITY_DISPLAY_STYLE_HEX16);

}
