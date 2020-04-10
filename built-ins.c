#include "shell.h"

int built_ins(char **argumento, char **env)
{
	int i;
	char *s = NULL;

	if (!_strcmp(argumento[0], "cd"))
	{
		cd_built_in(argumento);
		return (1);
	}
	if (!_strcmp(argumento[0], "env"))
	{
		for (i = 0; env[i]; i++)
		{
			s = string_con(env[i], "\n");
			_puts(s);
			free(s);
			s = NULL;
		}
		return (1);
	}
	/*
	if (!_strcmp(argumento[0]), "exit")
	{
		
	}
	if (!_strcmp(argumento[0]), "setenv")
	{
		
	}
	if (!_strcmp(argumento[0]), "unsetenv")
	{
		
	} */
	return (0);
}

int cd_built_in(char **argumento)
{
	char *dir;

	if (!argumento[1])
	{
		dir = _getenv("HOME=");
		chdir(dir);
		free_argument(argumento);
		return(1);
	}
	if (!_strcmp(argumento[1], "-"))
	{
		
		dir = _getenv("OLDPWD=");
		chdir(dir);
		_puts(string_con(dir, "\n"));
		return(1);
	}
	if (!_strcmp(argumento[1], "~"))
	{
		dir = _getenv("HOME=");
		chdir(dir);
		return(1);
	}
	return(chdir(argumento[1]));
}
