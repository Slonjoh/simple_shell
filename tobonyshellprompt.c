#include "tobonyshell.h"

/**
 * run_tobonyshell - Run the TobOnyshell main loop.
 */

void run_tobonyshell(void)
{
	char input[INPUT_LENGTH];
	int status;

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			printf("$ ");
			if
				(!fgets(input, sizeof(input), stdin)) break;
			input[strcspn(input, "\n")] = '\0';

			if (strlen(input) > 0)
			{
				if
					(!strcmp(input, "exit")) exit_tobonyshell(0);
				else if
					(!strncmp(input, "exit ", 5) && sscanf(input + 5, "%d", &status) == 1)
						exit_tobonyshell(status);
				else if
					(!strcmp(input, "env")) build_env();
				else
					run_input(input);
			}
		}
	}
	else
	{
		while (fgets(input, sizeof(input), stdin))
		{
			input[strcspn(input, "\n")] = '\0';

			if
				(strlen(input) > 0) run_input(input);
		}
	}
}
