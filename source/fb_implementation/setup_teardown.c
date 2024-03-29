/*
 * @file setup_teardown.c
 * @brief Project 2
 *
 * @details Initializes the LEDs, board, and debug console.
 *
 * @author Jack Campbell
 * @tools  PC Compiler: GNU gcc 8.3.0
 *         PC Linker: GNU ld 2.32
 *         PC Debugger: GNU gdb 8.2.91.20190405-git
 *         ARM Compiler: GNU gcc version 8.2.1 20181213
 *         ARM Linker: GNU ld 2.31.51.20181213
 *         ARM Debugger: GNU gdb 8.2.50.20181213-git
 */

#include "setup_teardown.h"
#include "fsl_debug_console.h"
#include "MKL25Z4.h"
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"

/**
 * initialize
 *
 * @details Initializes the LEDs, board, and debug console.
 *          Print "program start" in debug builds.
 *          Shows that the program successfully started.
 *
 */
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



#ifdef DEBUG
	/* serial debug console setup: use PRINTF("debug msg"); */
	BOARD_InitDebugConsole();

	PRINTF("program start");
#endif

}

/**
 * terminate
 *
 * @details Print "program end" in debug builds.
 *          Shows that the program successfully completed.
 *
 */
void terminate()
{
#ifdef DEBUG
	PRINTF("program end");
#endif
}
