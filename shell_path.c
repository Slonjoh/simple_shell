#include "tobonyshell.h"

/**
 * find_executable -  function is responsible for searching for the
 * executable file in the PATH and returning the full path if found.
 * @command: a string
 * Return: a copy of the path
 */


char *find_executable(char *command)
{
	char *path = getenv("PATH");

	if (path)
	{
		char *path_copy = strdup(path);
		char *token = strtok(path_copy, ":");

		while (token)
		{
			char full_path[INPUT_LENGTH];

			snprintf(full_path, sizeof(full_path), "%s/%s", token, command);

			if (access(full_path, X_OK) == 0)
			{
				char *executable;

				executable = strdup(full_path);
				free(path_copy);
				return (executable);
			}
			token = strtok(NULL, ":");
		}
		free(path_copy);
	}
	return (NULL);
}

/**
 * execute_command - a function that handles the actual execution of
 * the command and checks if the executable is found before forking.
 * @executable: string executable
 * @args: args parameter
 */

void execute_command(char *executable, char *args[])
{
	int exit_status = 0;

	if (executable)
	{
		if (strcmp(args[0], "exit") == 0)
		{
			if (args[1] != NULL)
				exit_status = atoi(args[1]);
			exit_tobonyshell(exit_status);
		}
		else
		{
			pid_t pid = fork();

			if (pid == -1)
			{
				perror("Fork Error");
				exit(1);
			}
			if (pid == 0)
			{
				execv(executable, args);
				perror("Execution Error");
				exit(1);
			}
			else
			{
				int status;

				waitpid(pid, &status, 0);
				if (WIFEXITED(status))
					exit_status = WEXITSTATUS(status);
			}
		}
	}
	else
	{
		perror(args[0]);
	}
	exit(exit_status);
}
