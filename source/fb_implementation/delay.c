/*
 * @file delay.c
 * @brief Project 2
 *
 * @details This file contains prototypes for calculating a spin-wait
 *          on various platforms, used for delaying LED state changes.
 *
 * @author Jack Campbell
 * @tools  PC Compiler: GNU gcc 8.3.0
 *         PC Linker: GNU ld 2.32
 *         PC Debugger: GNU gdb 8.2.91.20190405-git
 *         ARM Compiler: GNU gcc version 8.2.1 20181213
 *         ARM Linker: GNU ld 2.31.51.20181213
 *         ARM Debugger: GNU gdb 8.2.50.20181213-git
 */
#include "delay.h"
#include "fsl_debug_console.h"

// https://community.nxp.com/docs/DOC-94734
// https://nicopinkowski.wordpress.com/intro-into-arm-cortex-m0-systick-timer/
void delay(uint64_t inDelayMs)
{
#ifdef DEBUG
	PRINTF(" %llu", inDelayMs);
#endif
	uint64_t delaySeconds = inDelayMs * 1000;
	uint64_t delayCycles = inDelayMs*((uint64_t)(48000000UL)/1000UL);
	while(delayCycles--);
}
