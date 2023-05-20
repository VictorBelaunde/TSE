#ifndef LEDS_H
#define LEDS_H

#include  <stdint.h>
#include <stdbool.h>

void leds_inicia(uint16_t *direccion);

void leds_prende_uno(uint8_t led);
void leds_apaga_uno(uint8_t led);
bool leds_estado_led(uint8_t led);
void leds_prende_todos(uint16_t * direccion);
void leds_apago_todos(uint16_t *direccion);

#endif