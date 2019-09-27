//
// Created by Jack Campbell on 2019-09-23.
//
#define _POSIX_C_SOURCE 199309L
#include "delay.h"
#include <time.h> // nanosleep

void delay(int64_t inDelayMs)
{
	volatile int delayCycles = inDelayMs * 1000;
	while(delayCycles--);
//    struct timespec ts;
//    //calculate delay val to milliseconds
//    ts.tv_sec = (inDelayMs / 1000);
//    ts.tv_nsec = inDelayMs * 1000000;
//    //spin for that time
//    nanosleep(&ts, NULL); // TODO: Verify this is included on FRDM board. We may be able to put this in a "common" section
}
