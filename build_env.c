#include "tobonyshell.h"

/**
 * build_env - Environment built-in command.
 */

void build_env(void)
{
	char **env = environ;
	int j;

	for (j = 0; env[j] != NULL; j++)
	{
		printf("%s\n", env[j]);
	}
}
