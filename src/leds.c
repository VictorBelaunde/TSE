#include "leds.h"


#define TODOS_LEDS_OFF    0x0000
#define TODOS_LEDS_ON     0xFFFF
#define INDEX_OFFSET      1
#define PRIMER_BIT        1

static uint16_t * puerto_virtual;

uint16_t index_to_mask(uint8_t led)
{
    return (PRIMER_BIT << (led - INDEX_OFFSET ));
}

void leds_inicia(uint16_t *direccion)
{
    puerto_virtual = direccion;
    leds_apago_todos();
}

void leds_prende_uno(uint8_t led)
{
    *puerto_virtual |= index_to_mask(led);
}

void leds_apaga_uno(uint8_t led)
 {
    *puerto_virtual &= ~index_to_mask(led);
 }

bool leds_estado_led(uint8_t led)
{
    uint16_t masked_port_value = * puerto_virtual & index_to_mask(led);
    return (masked_port_value != TODOS_LEDS_OFF);
}

void leds_prende_todos()
{   
    *puerto_virtual = TODOS_LEDS_ON;
}

void leds_apago_todos()
{
    *puerto_virtual = TODOS_LEDS_OFF;
}
