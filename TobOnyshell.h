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
void process_arguments(char *input, char *args[], int *argument_count);
char *find_executable(char *command);
void execute_command(char *executable, char *args[]);
void exit_tobonyshell(int status);
extern char **environ;
void build_env(void);
int set_env_var(const char *var, const char *value, int overwrite);
int unset_env_var(const char *var);
int build_setenv(char *args[], int argument_count);
int build_unsetenv(char *args[], int argument_count);
int process_commands(char *args[], int argument_count);
int cd_home(void);
int cd_pwd(void);
int build_cd(char *args[], int argument_count);

#endif /*TOBONY_SHELL_H*/
