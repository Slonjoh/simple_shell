#include "TobOnyshell.h"

/**
 * execute_single_command - Function to execute a single command
 * @command: string command
 * Return: 0
 */

int execute__single_command(char *command)
{
	int arg_count = 0;
	char *args[MAX_ARGS];

	/* Parse the command arguments */
	process_arguments(command, args, &arg_count);

	/* Check for built-in commands */
	if (strcmp(args[0], "exit") == 0)
	{
		int exit_status = (arg_count > 1) ? atoi(args[1]) : 0;
		exit_tobonyshell(exit_status);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		build_env();
		return (0);
	}
	else if (strcmp(args[0], "cd") == 0)
	{
		return build_cd(args, arg_count);
	}
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
			/* Child process */
			execute_command(find_executable(args[0]), args);
			exit(1);
			/* If execute_command fails, exit the child process */
		}
		else
		{
			/* Parent process */
			int status;
			wait(&status); /* Wait for the child process to finish*/
			return WEXITSTATUS(status);
		}
	}
	return (0);
}

/**
 * execute_commands - Function to execute multiple 
 * commands separated by operators
 * @input: string
 * Return: status
 */

int execute__commands(char *input)
{
	/* Split input into separate commands using operators && and || */
	char *token = strtok(input, "&|");
	int status = 0;

	while (token != NULL)
	{
		/* Trim leading and trailing whitespaces */
		char *command = strtok(token, " \t");

		if (command != NULL)
		{
			int execute_command = 1;

			if (strcmp(token, "&&") == 0)
			{
				execute_command = (status == 0);
			}
			else if (strcmp(token, "||") == 0)
			{
				execute_command = (status != 0);
			}
			else
			{
				status = execute__single_command(token);
			}
			if (execute_command)
			{
				status = execute__single_command(command);
			}
		}
		/* Get the next command separated by operators */
		token = strtok(NULL, "&|");
	}
	return (status);
}
