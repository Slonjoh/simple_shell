#include "TobOnyshell.h"

/**
 * run_tobonyshell - Run the TobOnyshell main loop.
 */

void run_tobonyshell(void)
{
	char input[INPUT_LENGTH];

	for (;;)
	{
		printf("TobOnyshell# ");

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		input[strcspn(input, "\n")] = '\0';

		if (strlen(input) > 0)
		{
			if (strcmp(input, "exit") == 0)
			{
				exit_tobonyshell(0);
			}
			else if (strncmp(input, "exit ", 5) == 0)
			{
				int status;

				if (sscanf(input + 5, "%d", &status) == 1)
				{
					exit_tobonyshell(status);
				}
			}
			else if (strcmp(input, "env") == 0)
			{
				build_env();
			}
			else
			{
			run_input(input);
			}
		}
		execute_commands(input);

		/* Execute multiple commands separated by operators */
		int status = execute__commands(input);
		printf("Exit status: %d\n", status);
	}
}
