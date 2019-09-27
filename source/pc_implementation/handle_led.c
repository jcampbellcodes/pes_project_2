//
// Created by Jack Campbell on 2019-09-23.
//

#include "handle_led.h"
#include <stdio.h>

void setLed(uint8_t inValue, enum COLOR inColor)
{
    printf("\nLED %s %s", COLOR_STRINGS[inColor], STATE_STRINGS[inValue]);
#ifdef DEBUG
    printf(" {TIMESTAMP}"); // TODO
#endif
    printf("\n");
}
