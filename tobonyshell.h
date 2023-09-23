#ifndef TOBONY_SHELL_H
#define TOBONY_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>

#define INPUT_LENGTH 1024
#define MAX_ARGS 64

void run_input(char *input);
char **customize_env();
void run_tobonyshell(void);
void process_arguments(char *input, char *args[], int *argument_count);
char *get_command(char *execute);
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
void execute_commands(char *input);
void execute_all_commands(char *input);
void execute_single_command(char *command);
bool execute_one_command(char *command);

#endif /*TOBONY_SHELL_H*/
