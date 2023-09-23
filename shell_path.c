#include "tobonyshell.h"

/**
 * execute_command - Function that handles the actual execution of
 * the command and checks if the executable is found before forking.
 * @executable: String executable
 * @args: argument
 */

void execute_command(char *executable, char *args[])
{
	if (executable)
	{
		if (strcmp(args[0], "exit") == 0)
		{
			if (args[1] != NULL)
				exit(atoi(args[1]));
			else
				exit(0);
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
				perror(args[0]);
				exit(2);
			}
			else
			{
				int status;

				waitpid(pid, &status, 0);
				if (WIFEXITED(status))
					exit(WEXITSTATUS(status));
			}
		}
	}
	else if (strcmp(args[0], "exit") != 0 &&
			strcmp(args[0], "exit_tobonyshell") != 0)
		exit(0);
}

/**
 * get_command -  Function is responsible for searching for the
 * executable file in the PATH and returning the full path if found.
 * @execute: String
 * Return: Copy of the path
 */


char *get_command(char *execute)
{
	char *path = getenv("PATH");

	if (path)
	{
		char *path_copy = strdup(path);
		char *token = strtok(path_copy, ":");

		while (token)
		{
			char full_path[INPUT_LENGTH];

			snprintf(full_path, sizeof(full_path), "%s/%s", token, execute);

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
