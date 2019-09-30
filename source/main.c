/*
 * @file main.c
 * @brief Project 2
 *
 * @details This file calls the included prototypes and coordinates
 *          state for the LED program. Depending on the platform, this
 *          may just print to the screen or it will actually blink
 *          a physical LED.
 *
 * @author Jack Campbell
 * @tools  PC Compiler: GNU gcc 8.3.0
 *         PC Linker: GNU ld 2.32
 *         PC Debugger: GNU gdb 8.2.91.20190405-git
 *         ARM Compiler: GNU gcc version 8.2.1 20181213
 *         ARM Linker: GNU ld 2.31.51.20181213
 *         ARM Debugger: GNU gdb 8.2.50.20181213-git
 */

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

int main()
{
	static const uint64_t TIMINGS[STEPS_PER_CYCLE] =
	{
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

    initialize();

    bool ledValue = 1;
    enum COLOR ledColor = RED;
    int counter = 0;

    for(int j = 0; j < NUM_CYCLES; j++)
    {
        for(int i = 0; i < STEPS_PER_CYCLE; i++)
        {
        	set_led((uint8_t)ledValue, ledColor);
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

