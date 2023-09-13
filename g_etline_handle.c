#include "g_etline.h"

/**
 * handle_EOL - Handle end of line.
 *
 * @line_len: Length of the line.
 *
 * Return: Allocated string containing the line.
 * NULL if the line length is zero.
 */

char *handle_EOL(int line_len)
{
	if (line_len == 0)
	{
		return (NULL);
	}
	return (form_line(line_len));
}

extern void rm_buffer(void);
extern char read_only(void);
extern char *assign_line(int len);
extern char *form_line(int line_len);
extern char *get_line(void);
