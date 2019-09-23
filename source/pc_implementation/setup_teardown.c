//
// Created by Jack Campbell on 2019-09-23.
//

#include "setup_teardown.h"

void initialize()
{
#ifdef DEBUG
    printf("\nprogram start\n");
#endif
}

void terminate()
{
#ifdef DEBUG
    printf("\nprogram end\n");
#endif
}