//
// Created by Jack Campbell on 2019-09-23.
//

#include "handle_led.h"
#include "board.h"
#include <stdio.h>

void setLed(uint8_t inValue, enum COLOR inColor)
{
#ifdef DEBUG

        //send UART message: LED ${COLOR} ${STATE} ${CYCLE_NUM} TODO

#endif

	printf("\nLED %s %s", COLOR_STRINGS[inColor], STATE_STRINGS[inValue]);

        // toggle led TODO
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
			if(inValue)
			{
				LED_GREEN_ON();
			}
			else
			{
				LED_GREEN_OFF();
			}
			LED_RED_OFF();
			break;
		}
		case BLUE:
		{
			if(inValue)
			{
				LED_BLUE_ON();
			}
			else
			{
				LED_BLUE_OFF();
			}
			LED_GREEN_OFF();
			LED_RED_OFF();
			break;
		}
		default:
			 break;
	}
}
