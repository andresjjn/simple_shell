#include "shell.h"

/**
 * built_ins - Commands without PATH.
 * @argumento: Double pointer with input args.
 * @status: Status for exit.
 * @name: Name of the program.
 * @count: Iteration count.
 * Return: Integer of success or failure.
 */
int built_ins(char **argumento, int *status, char *name, int count)
{

	if (!_strcmp(argumento[0], "cd"))
	{
		*status = cd_built_in(argumento);
		free_argument(argumento);
		return (1);
	}
	if (!_strcmp(argumento[0], "env"))
	{
		_env();
		free_argument(argumento);
		return (1);
	}
	if (!_strcmp(argumento[0], "setenv"))
	{
		*status = _steven(argumento);
		return (1);
	}
	if (!_strcmp(argumento[0], "unsetenv"))
		return (_unsteven(argumento));
	if (!_strcmp(argumento[0], "exit"))
	{
		if (exit_built_in(argumento, *status) == 2)
		{
			print_error(name, argumento, count, ": Illegal number: ", argumento[1]);
			free_argument(argumento);
			*status = 2;
		}
		return (1);
	}
	return (0);
}

/**
 * cd_built_in - Funtion to use chdir command.
 * @argumento: Double pointer with input args.
 * Return: Integer of success or failure.
 */
int cd_built_in(char **argumento)
{
	char *dir = NULL, *current = NULL;
	int s = 0, i = 0;
	char path[PATH_MAX];

	current = getcwd(path, sizeof(path));
	if (!argumento[1])
	{
		dir = _getenv("HOME");
		if (_strcmp(dir, current))
			i = 1;
		s = chdir(dir);
		if (s == -1)
			return (2);
		if (i)
		{
			setenv_from_functions("OLDPWD", current);
			setenv_from_functions("PWD", getcwd(path, sizeof(path)));
		}
		return (s);
	}
	if (!_strcmp(argumento[1], "-"))
	{
		dir = _getenv("OLDPWD");
		s = chdir(dir);
		dir = string_con(dir, "\n");
		_puts(dir);
		if (s == -1)
		{
			simple_free(&dir);
			return (2);
		}
		setenv_from_functions("OLDPWD", current);
		setenv_from_functions("PWD", getcwd(path, sizeof(path)));
		simple_free(&dir);
		return (s);
	}
	s = cd_built_in2(argumento);
	return (s);
}
/**
 * cd_built_in2 - Funtion to use chdir command.
 * @argumento: Double pointer with input args.
 * Return: Integer of success or failure.
 */
int cd_built_in2(char **argumento)
{
	char *dir = NULL, *current = NULL;
	int s = 0, i = 0;
	char path[PATH_MAX];

	current = getcwd(path, sizeof(path));
	if (!_strcmp(argumento[1], "~"))
	{
		dir = _getenv("HOME");
		if (_strcmp(dir, current))
			i = 1;
		s = chdir(dir);
		if (s == -1)
			return (2);
		if (i)
		{
			setenv_from_functions("OLDPWD", current);
			setenv_from_functions("PWD", getcwd(path, sizeof(path)));
		}
		return (s);
	}
	if (_strcmp(argumento[1], current))
		i = 1;
	s = chdir(argumento[1]);
	if (s == -1)
		return (2);
	if (i)
	{
		setenv_from_functions("OLDPWD", current);
		setenv_from_functions("PWD", getcwd(path, sizeof(path)));
	}
	return (s);
}
/**
 * exit_built_in - Function that controls the exit
 * @argumento: Double pointer with the instructions.
 * @status: status for the exit.
 * Return: 1.
 */
int exit_built_in(char **argumento, int status)
{
	int n = 0, i = 0;

	if (!argumento[1])
	{
		free2(argumento, env);
		exit(status);
	}
	if (argumento[1][0] == '+')
		i++;
	if (!argumento[1][i])
		return (2);
	while (argumento[1][i])
	{
		if ((argumento[1][i] >= '0' && argumento[1][i] <= '9'))
			n = (n * 10) + (argumento[1][i] - '0');
		else
			return (2);
		i++;
	}
	free2(argumento, env);
	exit(n);
	return (1);
}
/**
 * setenv_from_functions - functions for setenv from other functions.
 * @ar1: Argumento 1.
 * @ar2: Argumento 2.
 */
void setenv_from_functions(char *ar1, char *ar2)
{
	char **argumento = NULL, *a0 = "setenv";
	int i = 0;

	argumento = malloc(sizeof(char *) * (4));
	if (!argumento)
		return;
	argumento[3] = NULL;
	argumento[0] = malloc(sizeof(char *) * (_strlen(a0)) + 1);
	if (!argumento[0])
	{
		free_argument(argumento);
		return;
	}
	while (a0[i])
	{
		argumento[0][i] = a0[i];
		i++;
	}
	argumento[0][i] = 0;
	argumento[1] = malloc(sizeof(char *) * (_strlen(ar1)) + 1);
	if (!argumento[1])
	{
		free_argument(argumento);
		return;
	}
	for (i = 0; ar1[i]; i++)
		argumento[1][i] = ar1[i];
	argumento[1][i] = 0;
	argumento[2] = malloc(sizeof(char *) * (_strlen(ar2)) + 1);
	if (!argumento[2])
	{
		free_argument(argumento);
		return;
	}
	for (i = 0; ar2[i]; i++)
		argumento[2][i] = ar2[i];
	argumento[2][i] = 0;
	_steven(argumento);
}
