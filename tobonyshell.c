#include "tobonyshell.h"

/**
 * run_input - Execute a command inputed by user in a child process.
 * @input: Command to be executed.
 */

void run_input(char *input)
{
	int pid = fork();

	if (pid == -1)
	{
		perror("Fork Error");
		exit(1);
	}
	if (pid == 0)
	{
		char *args[MAX_ARGS];
		int arg_count = 0;
		char **env;


		if (input == NULL || strspn(input, " \t\n\r") == strlen(input))
			exit(2);
		process_arguments(input, args, &arg_count);
		env = customize_env();
		execve(args[0], args, env);
		perror("Invalid Command");
		exit(1);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
	}
}

/**
 * customize_env - Create a custom environment with an additional variable.
 * Return: Pointer to the custom environment.
 */
char **customize_env()
{
	char **env;
	char *custom_env[] = {
		"CUSTOM_VAR=custom_value",
		NULL
	};

	int env_len = 0;
	int i;

	while (environ[env_len] != NULL)
	{
		env_len++;
	}

	env = malloc((env_len + 2) * sizeof(char *));
	if (env == NULL)
	{
		perror("Memory allocation error");
		exit(1);
	}

	for (i = 0; i < env_len; i++)
	{
		env[i] = environ[i];
	}
	for (i = 0; custom_env[i] != NULL; i++)
	{
		env[env_len + i] = custom_env[i];
	}
	env[env_len + i] = NULL;

	return (env);
}

	/*
	 * if (strcmp(args[0], "exit") == 0)
	 {
		int exit_status = 0;

		if (arg_count > 1)
		{
			exit_status = atoi(args[1]);
		}
		exit_tobonyshell(exit_status);
	}
	execvp(args[0], args);
	perror("Invalid Command");
	exit(1);
	}
	wait(0);
}
*/
