#ifndef LEDS_H
#define LEDS_H

#include "stdint.h"
#include "stdbool.h"

bool ledsInit(uint16_t * direccion);
bool ledTurnOnSingle(uint16_t led);
bool ledTurnOffSingle(uint16_t led);

bool isLedOn(uint16_t led);

void ledTurnOnAll (void);
void ledTurnOffAll (void);

uint16_t indexToMask(uint16_t led);
bool limitCheckCorrect (uint16_t led);

#endif