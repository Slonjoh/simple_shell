#include <stdio.h>
#include <stdlib.h>
#include "TobOnyshell.h"
#include "g_etline.h"

/**
 * main - Entry point of the TobOnyshell program.
 *
 * Return: Always 0.
 */

int main(void)
{

	/*char *line;

	while (1)
	{
		 fflush(stdout);

		 line = get_line();

		 if (line == NULL)
		 {
			 break;
		 }
		 if (strcmp(line, "exit\n") == 0)
		 {
			 free(line);
			 break;
		 }
		 free(line);
	}*/
	run_tobonyshell();
	return (0);
}
