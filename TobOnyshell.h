#ifndef TOBONY_SHELL_H
#define TOBONY_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define INPUT_LENGTH 1024



void run_input(char *input);
void run_tobonyshell(void);

#endif /*TOBONY_SHELL_H*/

