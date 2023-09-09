#include "TobOnyshell.h"

/**
 * process_arguments - Process the input command into arguments.
 * @input: Input command string.
 * @args: Array to store the parsed arguments.
 * @arg_count: Pointer to an integer to store the number of arguments.
 */
void process_arguments(char *input, char *args[], int *arg_count)
{
	char *token = strtok(input, " ");

	for (*arg_count = 0; token != NULL && *arg_count <
			MAX_ARGS - 1; (*arg_count)++)
	{
		args[*arg_count] = token;
		token = strtok(NULL, " ");
	}

	args[*arg_count] = NULL;
}
