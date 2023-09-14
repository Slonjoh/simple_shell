#include "TobOnyshell.h"

/**
 * run_tobonyshell - Run the TobOnyshell main loop.
 */

void run_tobonyshell(void)
{
	char input[INPUT_LENGTH];

	for (;;)
	{
		printf("TobOnyshell$ ");

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
				exit_tobonyshell();
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
	}
}
