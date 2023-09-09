#include "TobOnyshell.h"

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
		execlp(input, input, NULL);
		perror("Invalid Command");
		exit(1);
	}
	wait(0);
}
