/*
 * @file delay.c
 * @brief Project 2
 *
 * @details This file contains prototypes for calculating a spin-wait
 *          on PC, used for delaying LED state changes.
 *
 * @author Jack Campbell
 * @tools  PC Compiler: GNU gcc 8.3.0
 *         PC Linker: GNU ld 2.32
 *         PC Debugger: GNU gdb 8.2.91.20190405-git
 *         ARM Compiler: GNU gcc version 8.2.1 20181213
 *         ARM Linker: GNU ld 2.31.51.20181213
 *         ARM Debugger: GNU gdb 8.2.50.20181213-git
 *
 * - Calculating the timestamp formatting using time.h is from:
 *     http://www.cplusplus.com/reference/ctime/strftime/
 */

#include "delay.h"
#include <time.h>
#include <stdio.h>

/**
 * delay
 *
 * @brief Blocks execution for the specified time.
 * @param inDelayMs Then time in milliseconds to block.
 */
void delay(uint64_t inDelayMs)
{
#ifdef DEBUG
	static int64_t sTotalTime = 0;
	static int64_t sLastTotalTime = 0;
	sTotalTime += inDelayMs;

	// figure out time stamp
	// http://www.cplusplus.com/reference/ctime/strftime/
	time_t rawtime;
    struct tm * timeinfo;
	char buffer [80];
	time (&rawtime);
	timeinfo = localtime (&rawtime);
	strftime (buffer,80,"%T",timeinfo);
	printf(" %s %lld\n", buffer, sTotalTime - sLastTotalTime);
	sLastTotalTime = sTotalTime;
#endif

	const uint64_t clocksPerMillisecond = CLOCKS_PER_SEC / 1000UL;
    uint64_t waitUntil = clock() + inDelayMs*clocksPerMillisecond;
    while( clock() < waitUntil );
}
