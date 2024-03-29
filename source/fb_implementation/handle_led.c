/*
 * @file handle_led.c
 * @brief Project 2
 *
 * @details Contains the prototype for handling LEDs on the FB.
 *          In this implementation, we print debug info in debug builds
 *          and flash the LED either way.
 *
 * @author Jack Campbell
 * @tools  PC Compiler: GNU gcc 8.3.0
 *         PC Linker: GNU ld 2.32
 *         PC Debugger: GNU gdb 8.2.91.20190405-git
 *         ARM Compiler: GNU gcc version 8.2.1 20181213
 *         ARM Linker: GNU ld 2.31.51.20181213
 *         ARM Debugger: GNU gdb 8.2.50.20181213-git
 */

#include <stdint.h>
#include "handle_led.h"
#include "board.h"
#include "fsl_debug_console.h"
#include "fsl_gpio.h"
#include "MKL25Z4.h"

/**
 * set_led
 *
 * @brief Sets the LED state.
 * @details This function controls a physical LED and prints
 *          debug info over UART on debug builds.
 * @param inValue The on/off state of the LED to set.
 * @param inColor The color of the LED to set.
 */
void set_led(uint8_t inValue, enum COLOR inColor)
{
#ifdef DEBUG
	GPIO_TogglePinsOutput(GPIOD, 1U << 7U);
	PRINTF("\nLED %s %s", COLOR_STRINGS[inColor], inValue ? "ON" : "OFF");
#endif

	switch(inColor)
	{
		case RED:
		{
			LED_BLUE_OFF();
			LED_GREEN_OFF();
			if(inValue)
			{
				LED_RED_ON();
			}
			else
			{
				LED_RED_OFF();
			}

			break;
		}
		case GREEN:
		{
			LED_BLUE_OFF();
			LED_RED_OFF();

			if(inValue)
			{
				LED_GREEN_ON();
			}
			else
			{
				LED_GREEN_OFF();
			}
			break;
		}
		case BLUE:
		{
			LED_GREEN_OFF();
			LED_RED_OFF();

			if(inValue)
			{
				LED_BLUE_ON();
			}
			else
			{
				LED_BLUE_OFF();
			}
			break;
		}
		default:
			 break;
	}
}
