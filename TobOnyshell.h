#ifndef TOBONY_SHELL_H
#define TOBONY_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define INPUT_LENGTH 1024
#define MAX_ARGS 64
#define MAX_ALIAS_COUNT 50

/**
 * struct Alias - A structure that stores aliases.
 * @name: a string
 * @value: The value at index.
 */

typedef struct Alias
{
	char *name;
	char *value;
} Alias;

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
bool execute_single_command(char *command);
void execute_commands(char *input);
void print_aliases(void);
int find_alias_index(char *name);
void create_alias(char *name, char *value);
int handle_alias_command(char *args[], int argument_count);

#endif /*TOBONY_SHELL_H*/
