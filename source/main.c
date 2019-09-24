#include <stdio.h>
#include "delay.h"
#include "setup_teardown.h"
#include "led_types.h"
#include "handle_led.h"
#include <stdint.h>
#include <stdbool.h>

/* freedom board includes */
#include "fsl_debug_console.h"
#include "MKL25Z4.h"
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"

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

void init() {
	/* board setup */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();

    /* led setup */
    // TODO: should probably move this into led.c and just call led_init() or something like that
    LED_RED_INIT(1);
	LED_BLUE_INIT(1);
	LED_GREEN_INIT(1);

    /* serial debug console setup
     * To use, call PRINTF("some debug message");
     */
    //TODO: need to case this out depending on target... only needed for freedom board
    BOARD_InitDebugConsole();
}

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

