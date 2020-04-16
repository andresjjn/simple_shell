#include "shell.h"
/**
 * _steven - set or create a enviroment variable.
 * @env: Enviroment variable.
 * @argumento: Instructions
 * Return: 0.
 */
int _steven(char **env, char **argumento)
{
	char *s = NULL, *t = NULL;
	int i = 0;

	while (argumento[i])
		i++;
	if (i != 3)
		return (-1);
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
	env = _realloc(env, i + 1, i + 2);
	env[i] = string_con(s, argumento[2]);
	env[i + 1] = NULL;
	simple_free(&s);
	return (0);
}

/**
 * _realloc - function that reallocates a memory block using malloc and free.
 * @ptr: Old pointer.
 * @old_size: Old Size.
 * @new_size: New Size.
 * Return: n or NULL.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *n, *s = ptr;
	unsigned int i = 0;

	if (new_size == old_size)
		return (ptr);
	if (!ptr)
		return (malloc(new_size));
	if (ptr && new_size == 0)
	{
		free(ptr);
		return (0);
	}
	n = malloc(new_size);
	if (n == 0)
		return (0);
	while (i < old_size)
	{
		n[i] = s[i];
		i++;
	}
	free(ptr);
	return (n);
}
/**
 * _unsteven - Delete a enviroment variable.
 * @env: Enviroment variable.
 * @argumento: Instructions.
 * Return: 0 on succes 2 on fail.
 */
int _unsteven(char **env, char **argumento)
{
	char *s = NULL;
	int i = 0;

	s = string_con(argumento[1], "=");
	for (i = 0; env[i]; i++)
	{
		if (!_strcmpn(s, env[i], _strlen(s)))
		{
			simple_free(&s);
			simple_free(&env[i]);
			while (env[i])
			{
				if (env[i + 1])
				{
					env[i] = env[i + 1];
					i++;
					continue;
				}
				env[i + 1] = NULL;
			}
			return (0);
		}
	}
	free_argument(argumento);
	return (0);
}
