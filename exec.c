#include "shell.h"

/**
 * exec - Excecute a command with flags.
 * @argumento: Double pointer with command info.
 * @env: Enviroment variable.
 * @name: Program name.
 * @count: Counter of iterations.
 * Return: 0 works or -1 error.
 */
int exec(char **argumento, char **env, char *name, int count)
{
	struct stat stats;
	char **path = NULL, *s = NULL, *s1 = NULL;
	int i = 0, status = 0;

	if (argumento == NULL)
		return (-1);
	if (fork() == 0)
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
			if (argumento[0][0] == '/' || argumento[0][0] == '.')
				break;
			if (access(s, X_OK) == 0)
				if (!stat(s, &stats))
					execve(s, argumento, env);
			if (path[i + 1])
				simple_free(&s);
		}
		if (stat(s, &stats))
			print_error(name, argumento, count, ": not found", "");
		simple_free(&s);
		free2(argumento, path);
		exit(127);
	}
	else
		wait(&status);
	free2(argumento, path);
	return (status);
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
 * print_error - print the erros.
 * @name: name of program.
 * @argumento: command.
 * @count: counter of iterarions.
 * @msn: error message.
 * @ar: last argument of a command.
 */
void print_error(char *name, char **argumento, int count, char *msn, char *ar)
{
	_puts2(name);
	_puts2(": ");
	print_number(count);
	_puts2(": ");
	_puts2(argumento[0]);
	_puts2(msn);
	_puts2(ar);
	_puts2("\n");
}

/**
 * _puts2 - print string.
 * @str: string.
 * Return: Nothing.
 */
void _puts2(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		_putchar2(str[i]);
}
/**
 * _putchar2 - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar2(char c)
{
	return (write(2, &c, 1));
}
