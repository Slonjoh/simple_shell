#include "TobOnyshell.h"

/**
 * print_aliases - a function that prints all aliases
 * @void: No parameter
 * Return: void
 */

void print_aliases(void)
{
	Alias aliases[MAX_ALIAS_COUNT];
	int alias_count = 0;

	for (int i = 0; i < alias_count; i++)
	{
		printf("%s='%s'\n", aliases[i].name, aliases[i].value);
	}
}

/**
 * find_alias_index - a function to find the index of an alias by name
 * @name: string parameter
 * Return: number of index or -1
 */

int find_alias_index(char *name)
{
	Alias aliases[MAX_ALIAS_COUNT];
	int alias_count = 0;

	for (int i = 0; i < alias_count; i++)
	{
		if (strcmp(aliases[i].name, name) == 0)
		{
			return (i);
		}
	}
	return (-1);
}

/**
 * create_alias - a function to create or update an alias
 * @name: string parameter
 * @value: string parameter
 * Return: void
 */

void create_alias(char *name, char *value)
{
	Alias aliases[MAX_ALIAS_COUNT];
	int alias_count = 0;
	int index = find_alias_index(name);

	if (index != -1)
	{
		/* Update existing alias */
		free(aliases[index].value);
		aliases[index].value = strdup(value);
	}
	else if (alias_count < MAX_ALIAS_COUNT)
	{
		/* Create a new alias */
		aliases[alias_count].name = strdup(name);
		aliases[alias_count].value = strdup(value);
		alias_count++;
	}
	else
	{
		printf("Alias limit reached. Cannot create more aliases.\n");
	}
}

/**
 * handle_alias_command - a function to handle the alias built-in command
 * @args: string of chars
 * @argument_count: int parameter
 * Return: 0
 */

int handle_alias_command(char *args[], int argument_count)
{
	if (argument_count == 1)
	{
		/* Print all aliases */
		print_aliases();
	}
	else if (argument_count > 1)
	{
		for (int i = 1; i < argument_count; i++)
		{
			char *arg = args[i];
			char *equal_sign = strchr(arg, '=');

			if (equal_sign != NULL)
			{
				/* Define or update an alias (e.g., alias name='value') */
				*equal_sign = '\0'; /* Separate name and value */
				create_alias(arg, equal_sign + 1);
			}
			else
			{
				/*  Print the alias (e.g., alias name) */
				int index = find_alias_index(arg);

				if (index != -1)
				{
					printf("%s='%s'\n", aliases[index].name, aliases[index].value);
				}
			}
		}
	}
	return (0);
}
