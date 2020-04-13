#include "shell.h"

/**
 * exec - Excecute a command with flags.
 * @argumento: Double pointer with command info.
 * @env: Enviroment variable.
 * @name: Program name.
 * Return: 0 works or -1 error.
 */
int exec(char **argumento, char **env, char *name)
{
	pid_t chinga = 0;
	struct stat stats;
	char **path = NULL, *s = NULL, *s1 = NULL;
	int i = 0;

	if (argumento == NULL)
		return (-1);
	chinga = fork();
	if (chinga != 0)
		wait(NULL);
	if (chinga == 0)
	{
		if (!stat(argumento[0], &stats))
			execve(argumento[0], argumento, env);
		path = find_path(env);
		for (i = 0; path[i]; i++)
		{
			if (path[i][_strlen(path[i])] == '/')
				s = string_con(path[i], argumento[0]);
			else
			{
				s1 = string_con(path[i], "/");
				s = string_con(s1, argumento[0]);
				simple_free(&s1);
			}
			if (access(s, X_OK) == 0)
				if (!stat(s, &stats))
					execve(s, argumento, env);
		}
		if (stat(s, &stats))
			not_found(name, argumento);
		free_argument(argumento);
		free_argument(path);
		exit(127);
	}
	free_argument(argumento);
	free_argument(path);
	return (0);
}

/**
 * find_path - Split by arrays the paths into env
 * @env: Enviroment variable.
 * Return: Double pointer with paths.
 */
char **find_path(char **env)
{
	char **path = NULL, *s = NULL;

	s = _getenv("PATH", env);
	path = split_string(s, ':');
	return (path);
}
/**
 * not_found - print when don't found a command
 * @name: name of program.
 * @argumento: command.
 */
void not_found(char *name, char **argumento)
{
	_puts(name);
	_puts(": 1: ");
	_puts(argumento[0]);
	_puts(": not found\n");
}
