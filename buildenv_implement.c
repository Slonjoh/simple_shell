#include "TobOnyshell.h"
#include <string.h>

#ifndef _putchar
#define _putchar(c) putchar(c)
#endif

/**
 * set_env_var - Custom implementation of set_env_var.
 * @var: Environment variable name.
 * @value: Value to set for the env variable.
 * @overwrite: Flag to indicate overwrite if the variable exists.
 * Return: 0 on success, -1 on failure.
 */
int set_env_var(const char *var, const char *value, int overwrite)
{
	if (overwrite)
	{
		if (setenv(var, value, 1) != 0)
		{
			perror("set_env_variable");
			return (-1);
		}
	}
	else
	{
		if (getenv(var) == NULL)
		{
			if (setenv(var, value, 1) != 0)
			{
				perror("set_env_variable");
				return (-1);
			}
		}
	}
	return (0);
}

/**
 * unset_env_var - Custom Impletation of unset_env_var.
 * @var: Name of the environment variable to unset.
 * Return: 0 on success, -1 on failure.
 */
int unset_env_var(const char *var)
{
	if (unsetenv(var) != 0)
	{
		perror("unset_env_variable");
		return (-1);
	}
	return (0);
}

/**
 * build_setenv - Handle the setenv built-in command using custom functions.
 * @args: Array of arguments, where args[0] is the command itself.
 * @argument_count: Number of arguments.
 * Return: 0 on success, -1 on failure.
 */
int build_setenv(char *args[], int argument_count)
{
	if (argument_count != 3)
	{
		int j;

		const char *default_msg;

		default_msg = "Usage: setenv VARIABLE VALUE\n";

		for (j = 0; default_msg[j] != '\0'; j++)
		{
			_putchar(default_msg[j]);
		}
		return (-1);
	}

	return (set_env_var(args[1], args[2], 1));
}

/**
 * build_unsetenv - Handle  unsetenv built-in cmd using custom functions.
 * @args: Array of arguments, where args[0 is the command itself.
 * @argument_count: Number of arguments.
 * Return: 0 on success, -1 on failure.
 */

int build_unsetenv(char *args[], int argument_count)
{
	if (argument_count != 2)
	{
		int j;

		const char *default_msg;

		default_msg = "Usage: unsetenv VARIABLE\n";

		for (j = 0; default_msg[j] != '\0'; j++)
		{
			_putchar(default_msg[j]);
		}
		return (-1);
	}

	return (unset_env_var(args[1]));
}

/**
 * process_commands - Process and execute built-in commands.
 * @args: Array of arguments, where args[0] is the command itself.
 * @argument_count: Number of arguments.
 * Return: 0 on success, -1 on failure.
 */

int process_commands(char *args[], int argument_count)
{
	if (strcmp(args[0], "setenv") == 0)
	{
		return (build_setenv(args, argument_count));
	}
	else if (strcmp(args[0], "unsetenv") == 0)
	{
		return (build_unsetenv(args, argument_count));
	}
	else
	{
		return (-1);
	}
}
