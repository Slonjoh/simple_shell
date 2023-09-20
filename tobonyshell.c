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

		 process_arguments(input, args, &arg_count);
		 execute_command(args[0], args);
		 exit(1);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
	}
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
