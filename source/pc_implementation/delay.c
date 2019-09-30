//
// Created by Jack Campbell on 2019-09-23.
//
#include "delay.h"
#include <time.h> // nanosleep
#include <stdio.h>

//https://c-for-dummies.com/blog/?p=69
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

    clock_t now,then;
    uint64_t pause = inDelayMs*((uint64_t)(CLOCKS_PER_SEC)/1000UL);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}
