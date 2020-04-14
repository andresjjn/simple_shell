#include "shell.h"
/**
 * _steven - set or create a enviroment variable.
 * @name: Name of new/set variable.
 * @ptr: Pointer of new value for env.
 * @env: Enviroment variable.
 * Return: New/set of enviroment variable.
 */
int _steven(char **env, char **argumento, int n)
{
	char *s = NULL, *t = NULL;
	int i = 0;

	if (n != 3)
		return(-1);
	s = string_con(argumento[1], "=");
	for (i = 0; env[i]; i++)
	{
		if (!_strcmpn(s, env[i], _strlen(s)))
		{
			printf("%s\n", env[i]);
			t = env[i];
			env[i] = string_con(s, argumento[2]);
			simple_free(&t);
			printf("%s\n", env[i]);
			simple_free(&s);
			return (0);
		}
	}
    env = _realloc(env, i + 1, i + 2);
    printf("%s\n", env[i]);
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
