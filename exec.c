#include "shell.h"

/**
 * exec - Excecute a command with flags.
 * @argumento: Double pointer with command info.
 * Return: 0 works or -1 error.
 */
int exec(char **argumento)
{
	pid_t chinga = 0;

	if (argumento == NULL)
		return (-1);
	chinga = fork();
	if (chinga != 0)
		wait(NULL);
	if (chinga == 0)
	{
		if (_strcmp(argumento[0], "/bin/cd") != 0)
		{
			printf("%s\n", argumento[0]);
			if (execve(argumento[0], argumento, NULL) == -1)
			{
				_puts("Error: Imposible to execute that command\n");
				return (-1);
			}
		}
		else
		{
			chdir(argumento[1]);
		}
	}
	free_argument(argumento);
	return (0);
}
