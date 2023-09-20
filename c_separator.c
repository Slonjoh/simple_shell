#include "TobOnyshell.h"

/**
 * execute_single_command - Function to execute a single command
 * @command: accepts string
 * Return: returns true on success or false on failure
 */

bool execute_single_command(char *command)
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
		pid_t pid = fork();

		if (pid == -1)
		{
			perror("Fork Error");
			exit(1);
		}
		else if (pid == 0)
		{
			/* Child process*/
			execute_command(find_executable(args[0]), args);
			exit(1); /* If execute_command fails, exit the child process*/
		}
		else
		{
			/* Parent process */
			int status;

			wait(&status);
			return (WIFEXITED(status) && (WEXITSTATUS(status) == 0));
		}
	}
	return (true);/* Successful execution for built-in commands */
}

/**
 * execute_commands - Function to execute multiple commands
 * separated by ';', '&&', or '||'
 * @input: accepts string input
 */
void execute_commands(char *input)
{
	char *token = strtok(input, ";");

	while (token != NULL)
	{
		char *command = strtok(token, " \t");

		while (command != NULL)
		{
			execute_single_command(command);
			command = strtok(NULL, " \t");
		}
		/* Get the next command separated by ';' */
		token = strtok(NULL, ";");
	}
}

