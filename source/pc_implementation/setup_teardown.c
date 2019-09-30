/*
 * @brief Project 2
 *
 * @details
 *
 * @author Jack Campbell
 * @tools  PC Compiler: GNU gcc 8.3.0
 *         PC Linker: GNU ld 2.32
 *         PC Debugger: GNU gdb 8.2.91.20190405-git
 *         ARM Compiler: GNU gcc version 8.2.1 20181213
 *         ARM Linker: GNU ld 2.31.51.20181213
 *         ARM Debugger: GNU gdb 8.2.50.20181213-git
 */
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
