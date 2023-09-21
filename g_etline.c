#include "g_etline.h"

#define BUFFER_SIZE 1024

static char buffer[BUFFER_SIZE];
static int position;
static int size;

/**
 * rm_buffer - Delete the input buffer.
 */
void rm_buffer(void)
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
char read_only(void)
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
char *assign_line(int len)
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
char *form_line(int line_len)
{
	char *line;

	line = assign_line(line_len);
	strncpy(line, buffer, line_len);
	line[line_len] = '\0';
	return (line);
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
				free(line);
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
