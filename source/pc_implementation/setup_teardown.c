//
// Created by Jack Campbell on 2019-09-23.
//

#include "setup_teardown.h"
#include <stdio.h>

void initialize(void)
{
#ifdef DEBUG
    printf("\nprogram start\n");
#endif
}

void terminate(void)
{
#ifdef DEBUG
    printf("\nprogram end\n");
#endif
}
