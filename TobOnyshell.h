#ifndef TOBONY_SHELL_H
#define TOBONY_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define INPUT_LENGTH 1024
#define MAX_ARGS 64


void run_input(char *input);
void run_tobonyshell(void);
void process_arguments(char *input, char *args[], int *arg_count);
char *find_executable(char *command);
void execute_command(char *executable, char *args[]);

#endif /*TOBONY_SHELL_H*/
