#include "tobonyshell.h"

/**
 * process_arguments - Process the input command into arguments.
 * @input: Input command string.
 * @args: Array to store the parsed arguments.
 * @argument_count: Pointer to an integer to store the number of arguments.
 */
void process_arguments(char *input, char *args[], int *argument_count)
{
	char *start_token = NULL;
	int token_door = 0;
	int i;

	*argument_count = 0;

	for (i = 0; input[i] != '\0' && *argument_count < MAX_ARGS - 1; i++)
	{
		if (input[i] == ' ' || input[i] == '\n')
		{
			if (token_door)
			{
				input[i] = '\0';
				args[(*argument_count)++] = start_token;
				token_door = 0;
			}
		}
		else
		{
			if (!token_door)
			{
				start_token = &input[i];
				token_door = 1;
			}
		}
	}
	if (token_door)
	{
		args[(*argument_count)++] = start_token;
	}

	args[*argument_count] = NULL;
}
