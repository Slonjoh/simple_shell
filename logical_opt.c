#include "tobonyshell.h"
#include <stdbool.h>

/**
 * execute_one_command - Function to execute a single command
 * @command: accepts string
 * Return: returns true on  successful, false otherwise
 */
bool execute_one_command(char *command)
{
	int arg_count = 0;
	char *args[MAX_ARGS];

	process_arguments(command, args, &arg_count);
	if (strcmp(args[0], "exit") == 0)
	{
		int exit_status = (arg_count > 1) ? atoi(args[1]) : 0;

		exit_tobonyshell(exit_status);
	}
	else if (strcmp(args[0], "env") == 0)
		build_env();
	else if (strcmp(args[0], "cd") == 0)
		build_cd(args, arg_count);
	else
	{
		/* Execute non-built-in commands */
		pid_t pid = fork();

		if (pid == -1)
		{
			perror("Fork Error");
			exit(1);
		}
		else if (pid == 0)
		{
			execute_command(find_executable(args[0]), args);
			exit(1); /*If execute_command fails, exit the child process*/
		}
		else
		{
			int status;

			wait(&status);
			return (WIFEXITED(status) && (WEXITSTATUS(status) == 0));
		}
	}
	return (true); /* Successful execution for built-in commands*/
}

/**
 * execute_all_commands - Function to execute multiple
 * commands separated by ';', '&&', or '||'
 * @input: accepts string input
 */

void execute_all_commands(char *input)
{
	/* Split input into separate commands using ';' */
	char *token = strtok(input, ";");

	while (token != NULL)
	{
		/* Trim leading and trailing whitespaces */
		char *command = strtok(token, " \t");

		if (command != NULL)
		{
			bool success = true;
			char *next_token;

			while (success && (next_token = strtok(NULL, " \t")))
			{
				if (strcmp(next_token, "&&") == 0)
				{
					success = execute_one_command(command);
					command = strtok(NULL, " \t");
				}
				else if (strcmp(next_token, "||") == 0)
				{
					success = !execute_one_command(command);
					command = strtok(NULL, " \t");
				}
				else
				{
					/* Invalid operator; treat it as a separate command*/
					command = next_token;
				}
			}
			if (command != NULL)
			{
				success = execute_one_command(command);
			}
		}
		/* Get the next command separated by ';' */
		token = strtok(NULL, ";");
	}
}
