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
	volatile int delayCycles = delaySeconds * 48000000UL;
	while(delayCycles--);
}
