#include "shell.h"

/**
 * built_ins - Commands without PATH.
 * @argumento: Double pointer with input args.
 * @env: Enviroment variable.
 * Return: Integer of success or failure.
 */
int built_ins(char **argumento, char **env)
{
	int i = 0;
	char *s = NULL;

	if (!_strcmp(argumento[0], "cd"))
	{
		cd_built_in(argumento, env);
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
	/*
	*if (!_strcmp(argumento[0]), "exit")
	*{
	*
	*}
	*
	*if (!_strcmp(argumento[0]), "unsetenv")
	*{
	*
	*}
	*/
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
		return (s);
	}
	if (!_strcmp(argumento[1], "-"))
	{
		dir = _getenv("OLDPWD", env);
		s = chdir(dir);
		_puts(string_con(dir, "\n"));
		return (s);
	}
	if (!_strcmp(argumento[1], "~"))
	{
		dir = _getenv("HOME", env);
		s = chdir(dir);
		return (s);
	}
	s = chdir(argumento[1]);
	return (s);
}
