//
// Created by Jack Campbell on 2019-09-23.
//

#ifndef PES_PROJECT_2_LED_TYPES_H
#define PES_PROJECT_2_LED_TYPES_H

enum COLOR
{
    RED = 0,
    GREEN,
    BLUE,
    NUM_COLORS
};

enum LED_STATES
{
    OFF = 0,
    ON,
    NUM_STATES
};

static const char * const COLOR_STRINGS[3] = {
        "RED",
        "GREEN",
        "BLUE"
};

static const char * const STATE_STRINGS[2] = {
        "OFF",
        "ON"
};

#endif //PES_PROJECT_2_LED_TYPES_H
