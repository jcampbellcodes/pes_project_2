#include <stdio.h>
#include "delay.h"
#include "setup_teardown.h"
#include "led_types.h"
#include "handle_led.h"
#include <stdint.h>
#include <stdbool.h>

#define NUM_CYCLES 10
#define NUM_COLOR_STEPS 3
#define STEPS_PER_CYCLE 20
static const int TIMINGS[STEPS_PER_CYCLE] = {
        3000,
        1000,
        2000,
        600,
        1000,
        400,
        1000,
        200,
        500,
        100,
        500,
        100,
        500,
        100,
        1000,
        200,
        1000,
        400,
        2000,
        600
};



int main() {

    initialize();

    bool ledValue = 1;
    enum COLOR ledColor = RED;
    int counter = 0;

    for(int j = 0; j < NUM_CYCLES; j++)
    {
        for(int i = 0; i < STEPS_PER_CYCLE; i++)
        {
            setLed((uint8_t)ledValue, ledColor);
            delay(TIMINGS[i]);

            // update LED state
            ledValue = !ledValue;
            if(++counter % NUM_COLOR_STEPS == 0)
                ledColor = ((ledColor + ledValue) % NUM_COLORS);
        }
    }

    terminate();

    return 0;
}

