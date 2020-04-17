#include "shell.h"
/**
 * _steven - set or create a enviroment variable.
 * @argumento: Instructions
 * Return: 0.
 */
int _steven(char **argumento)
{
	char *s = NULL, *t = NULL, **tmp = NULL;
	int i = 0;

	while (argumento[i])
		i++;
	if (i < 3)
	{
		free_argument(argumento);
		_env();
		return (1);
	}
	s = string_con(argumento[1], "=");
	for (i = 0; env[i]; i++)
	{
		if (!_strcmpn(s, env[i], _strlen(s)))
		{
			t = env[i];
			env[i] = string_con(s, argumento[2]);
			simple_free(&t);
			simple_free(&s);
			free_argument(argumento);
			return (0);
		}
	}
	tmp = malloc(sizeof(char *) * (i + 2));
	if (!tmp)
		return (2);
	for (i = 0; env[i]; i++)
		tmp[i] = env[i];
	tmp[i] = string_con(s, argumento[2]);
	tmp[i + 1] = NULL;
	free(env);
	env = tmp;
	simple_free(&s);
	free_argument(argumento);
	return (0);
}
/**
 * _unsteven - Delete a enviroment variable.
 * @argumento: Instructions.
 * Return: 0 on succes 2 on fail.
 */
int _unsteven(char **argumento)
{
	char *s = NULL, **tmp = NULL;
	int i = 0, j = 0, k = 0, len = 0;

	s = string_con(argumento[1], "=");
	while (env[len])
		len++;
	for (i = 0; env[i]; i++)
	{
		if (!_strcmpn(s, env[i], _strlen(s)))
		{
			tmp = malloc(sizeof(char *) * len);
			simple_free(&s);
			while (env[j + k])
			{
				if (j == i)
					k++;
				tmp[j] = env[j + k];
				j++;
			}
			tmp[j] = NULL;
			simple_free(&env[i]);
			free(env);
			env = tmp;
			free_argument(argumento);
			return (1);
		}
	}
	free_argument(argumento);
	return (1);
}

/**
 * _env - Print enviroment variable.
 */
void _env(void)
{
	char *s = NULL;
	int i = 0;

	for (i = 0; env[i]; i++)
	{
		s = string_con(env[i], "\n");
		_puts(s);
		simple_free(&s);
	}
}
