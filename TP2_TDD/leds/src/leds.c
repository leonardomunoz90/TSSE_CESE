#include "leds.h"
#include <stddef.h>

#define INDEX_OFFSET 1
#define FIRST_BIT 1
#define ALL_LED_OFF 0x0000
#define ALL_LED_ON 0xFFFF
#define LAST_BIT 16

static uint16_t *puerto_virtual;

uint16_t indexToMask(uint16_t led)
{
    return (FIRST_BIT << (led - INDEX_OFFSET));
}

bool limitCheckCorrect(uint16_t led)
{
    return ((led >= FIRST_BIT) && (led <= LAST_BIT));
}

bool ledsInit(uint16_t *direccion)
{
    if (direccion != NULL)
    {
        *direccion = ALL_LED_OFF;
        puerto_virtual = direccion;
        return true;
    }
    else
    {
        return false;
    }
}

bool ledTurnOnSingle(uint16_t led)
{
    if (limitCheckCorrect(led))
    {
        *puerto_virtual |= indexToMask(led);
        return true;
    }
    else
    {
        return false;
    }
}

bool ledTurnOffSingle(uint16_t led)
{
    if (limitCheckCorrect(led))
    {
        *puerto_virtual &= ~indexToMask(led);
        return true;
    }
    else
    {
        return false;
    }
}

bool isLedOn(uint16_t led)
{
    return ((*puerto_virtual & indexToMask(led)) == indexToMask(led));
}

void ledTurnOnAll(void)
{
    *puerto_virtual = ALL_LED_ON;
}

void ledTurnOffAll(void)
{
    *puerto_virtual = ALL_LED_OFF;
}