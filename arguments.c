#include "TobOnyshell.h"

/**
 * process_arguments - Process the input command into arguments.
 * @input: Input command string.
 * @args: Array to store the parsed arguments.
 * @argument_count: Pointer to an integer to store the number of arguments.
 */
void process_arguments(char *input, char *args[], int *argument_count)
{
	char *token;
	char *rest = input;

	*argument_count = 0;

	for (; *argument_count < MAX_ARGS - 1;)
	{
		token = strtok_r(rest, " ", &rest);

		if (token == NULL)
		{
			break;
		}
		args[(*argument_count)++] = token;
	}

	args[*argument_count] = NULL;
}
