#include "shell.h"

/**
 * built_ins - Commands without PATH.
 * @argumento: Double pointer with input args.
 * @env: Enviroment variable.
 * @status: Status for exit.
 * Return: Integer of success or failure.
 */
int built_ins(char **argumento, char **env, int *status)
{
	int i = 0;
	char *s = NULL;

	if (!_strcmp(argumento[0], "cd"))
	{
		*status = cd_built_in(argumento, env);
		free_argument(argumento);
		return (1);
	}
	if (!_strcmp(argumento[0], "env"))
	{
		for (i = 0; env[i]; i++)
		{
			s = string_con(env[i], "\n");
			_puts(s);
			simple_free(&s);
		}
		free_argument(argumento);
		return (1);
	}
	if (!_strcmp(argumento[0], "setenv"))
	{
		while (argumento[i])
			i++;
		_steven(env, argumento, i);
		free_argument(argumento);
		return (1);
	}
	if (!_strcmp(argumento[0], "exit"))
	{
		i = exit_built_in(argumento, *status, env);
		return (1);
	}

	return (0);
}

/**
 * cd_built_in - Funtion to use chdir command.
 * @argumento: Double pointer with input args.
 * @env: Enviroment variable.
 * Return: Integer of success or failure.
 */
int cd_built_in(char **argumento, char **env)
{
	char *dir;
	int s = 0;

	if (!argumento[1])
	{
		dir = _getenv("HOME", env);
		s = chdir(dir);
		if (s == -1)
			return (2);
		return (s);
	}
	if (!_strcmp(argumento[1], "-"))
	{
		dir = _getenv("OLDPWD", env);
		s = chdir(dir);
		_puts(string_con(dir, "\n"));
		if (s == -1)
			return (2);
		return (s);
	}
	if (!_strcmp(argumento[1], "~"))
	{
		dir = _getenv("HOME", env);
		s = chdir(dir);
		if (s == -1)
			return (2);
		return (s);
	}
	s = chdir(argumento[1]);
	if (s == -1)
		return (2);
	return (s);
}
/**
 * exit_built_in - Function that controls the exit
 * @argumento: Double pointer with the instructions.
 * @status: status for the exit.
 * @env: Enviroment variable.
 * Return: 1.
 */
int exit_built_in(char **argumento, int status, char **env)
{
	int n = 0, i = 0;

	if (!argumento[1])
	{
		free2(argumento, env);
		exit(status);
	}
	while (argumento[1][i])
	{
		if (argumento[1][i] >= '0' && argumento[1][i] <= '9')
			n = (n * 10) + (argumento[1][i] - '0');
		else
			return (2);
		i++;
	}
	exit(n);

	return (1);
}
