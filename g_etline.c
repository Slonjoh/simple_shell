#include "g_etline.h"

#define BUFFER_SIZE 1024

static char buffer[BUFFER_SIZE];
static int position = 0;
static int size = 0;

/**
 * rm_buffer - Delete the input buffer.
 */
static void rm_buffer(void)
{
	position = 0;
	size = 0;
	memset(buffer, 0, BUFFER_SIZE);
}

/**
 * read_only - Reads a character from the input.
 *
 * Return: Next character read from the input.
 * EOF if the end of the input is reached.
 */
static char read_only(void)
{
	if (position >= size)
	{
		size = read(0, buffer, BUFFER_SIZE);
		position = 0;

		if (size <= 0)
		{
			return (EOF);
		}
	}

	return (buffer[position++]);
}

/**
 * assign_line - Assign memory for a line.
 *
 * @len: Length of the line to be allocated.
 *
 * Return: Pointer to the allocated memory.
 * NULL if memory allocation fails.
 */
static char *assign_line(int len)
{
	char *line;

	line = (char *)malloc(len + 1);
	if (!line)
	{
		perror("Malloc error");
		exit(1);
	}
	return (line);
}

/**
 * form_line - Form a line from the input buffer.
 *
 * @line_len: Length of the line to be built.
 *
 * Return: Allocated string containing the line.
 */
static char *form_line(int line_len)
{
	char *line;

	line = assign_line(line_len);
	strncpy(line, buffer, line_len);
	line[line_len] = '\0';
	return (line);
}

/**
 * handle_EOL - Handle end of line.
 *
 * @line_len: Length of the line.
 *
 * Return: Allocated string containing the line.
 * NULL if the line length is zero.
 */
static char *handle_EOL(int line_len)
{
	if (line_len == 0)
	{
		return (NULL);
	}
	return (form_line(line_len));
}

/**
 * get_line - Get a line from input.
 *
 * Return: Allocated string containing the read line.
 * NULL if an error occurs or end of file is reached.
 */

char *get_line(void)
{
	char *line = NULL;
	int line_len = 0;
	char c;

	for (;;)
	{
		c = read_only();

		switch (c)
		{
			case EOF:
				return (handle_EOL(line_len));
			case '\n':
			case '\r':
				line = handle_EOL(line_len);
				if (line != NULL)
				{
					return (line);
				}
				break;
			default:
				if (line_len == 0)
				{
					line = assign_line(1);
				}
				else
				{
					char *temp = (char *)realloc(line, line_len + 1);

					if (!temp)
					{
						perror("Malloc error");
						exit(1);
					}
					line = temp;
				}
				line[line_len++] = c;
		}
	}
}

/**
 * main - Entry point of the program.
 *
 * Return: 0 Always.
 */

int main(void)
{
	char *line;

	while ((line = get_line()) != NULL)
	{
		printf("You entered: %s\n", line);
		free(line);
	}

	return (0);
}
