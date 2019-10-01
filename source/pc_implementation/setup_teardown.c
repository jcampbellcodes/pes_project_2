/*
 * @file setup_teardown.c
 * @brief Project 2
 *
 * @details On PC, there is no setup and teardown to be done, but
 *          we print program start and end in debug builds.
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

/**
 * initialize
 *
 * @brief Print "program start" in debug builds. Shows that the program successfully started.
 *
 */
void initialize(void)
{
#ifdef DEBUG
    printf("\nprogram start\n");
#endif
}

/**
 * terminate
 *
 * @brief Print "program end" in debug builds. Shows that the program successfully completed.
 *
 */
void terminate(void)
{
#ifdef DEBUG
    printf("\nprogram end\n");
#endif
}
