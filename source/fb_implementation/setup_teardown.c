//
// Created by Jack Campbell on 2019-09-23.
//

#include "setup_teardown.h"
#include "fsl_debug_console.h"
#include "MKL25Z4.h"
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"

void initialize()
{
	/* board setup */
	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitBootPeripherals();

	/* led setup */
	LED_RED_INIT(1);
	LED_BLUE_INIT(1);
	LED_GREEN_INIT(1);

	/* serial debug console setup: use PRINTF("debug msg"); */
	BOARD_InitDebugConsole();

#ifdef DEBUG
	PRINTF("program start");
#endif

}

void terminate()
{
#ifdef DEBUG
	PRINTF("program end");
#endif
}
