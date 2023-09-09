#include "TobOnyshell.h"

/**
 * run_tobonyshell - Run the TobOnyshell main loop.
 */

void run_tobonyshell(void)
{
	char input[INPUT_LENGTH];

	for (;;)
	{
		printf("TobOnyshell> ");

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		input[strcspn(input, "\n")] = '\0';

		if (strlen(input) > 0)
		{
			run_input(input);
		}
	}
}
