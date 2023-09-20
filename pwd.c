#include "tobonyshell.h"
#include <limits.h>
#include <unistd.h>
#include <string.h>

/**
 * cd_home - Change the current directory to the home directory.
 * Return: 0 on success, -1 on failure.
 */

int cd_home(void)
{
	const char *cd_home;

	cd_home = getenv("HOME");
	if (!cd_home)
	{
		perror("cd$ implemented wrongly");
		return (-1);
	}

	if (chdir(cd_home) != 0 || setenv("PWD", cd_home, 1) != 0)
	{
		perror("cd$ implemented wrongly");
		return (-1);
	}

	return (0);
}

/**
 * cd_pwd - Change the current directory to the previous directory.
 * Return: 0 on success, -1 on failure.
 */

int cd_pwd(void)
{
	const char *cd_pwd;

	cd_pwd = getenv("OLDPWD");
	if (!cd_pwd)
	{
		perror("cd- implemented wrongly");
		return (-1);
	}

	if (chdir(cd_pwd) != 0 || setenv("PWD", cd_pwd, 1) != 0)
	{
		perror("cd- implemented wrongly");
		return (-1);
	}
	return (0);
}

/**
 * build_cd - Handle the cd built-in command.
 * @args: Array of arguments, where args[0] is the command itself.
 * @argument_count: Number of arguments.
 * Return: 0 on success, -1 on failure.
 */

int build_cd(char *args[], int argument_count)
{
	char cwd[PATH_MAX];

	if (argument_count == 1 || (argument_count == 2 && strcmp(args[1], "~") == 0))
	{
		return (cd_home());
	}
	else if (argument_count == 2 && strcmp(args[1], "-") == 0)
	{
		return (cd_pwd());
	}
	else if (argument_count == 2)
	{
		if (chdir(args[1]) != 0)
		{
			perror("cd implemented wrongly");
			return (-1);
		}
		if (!getcwd(cwd, sizeof(cwd)) || setenv("PWD", cwd, 1) != 0)
		{
			perror("cd implemented wrongly");
			return (-1);
		}
	}
	else
	{
		const char *default_msg;

		default_msg = "DEFAULT: cd [DIRECTORY]\n";
		write(STDERR_FILENO, default_msg, strlen(default_msg));
		return (-1);
	}

	return (0);
}
