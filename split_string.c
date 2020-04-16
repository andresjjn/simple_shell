#include "shell.h"
/**
 * split_string - divide a string into several within a double pointer.
 * @entrada: string.
 * @d: delimiter.
 * Return: The new double pointer.
 */

char **split_string(char *entrada, char d)
{
	int i = 0, j = 1, k = 0, len = 0, n  = 0, f = 0, fl = 0;
	char **argumento = NULL;

	n = _strlen(entrada);
	if (entrada[0] == '#' && d == ' ')
		return (argumento);
	for (f = 0; entrada[f] && (d != ' ' || entrada[f + 1] != '#'); f++)
		if (entrada[f] == d)
			j++;
	argumento = malloc(sizeof(char *) * (j + 1));
	if (!argumento)
		return (NULL);
	for (i = 0; i < n && entrada[i] && i <= f; i++)
	{
		len = 0;
		j = i;
		while (entrada[j] && entrada[j] != d)
			len++, j++;
		argumento[k] = malloc(sizeof(char) * (len + 1));
		if (!argumento[k])
		{
			free_argument(argumento);
			return (NULL);
		}
		for (j = 0; entrada[i] && (entrada[i] != d || fl == 1); i++, j++)
		{
			if (fl == 0 && entrada[i] == '"')
				fl = 1, i++;
			if (fl == 1 && entrada[i] == '"')
				fl = 0, i++;
			argumento[k][j] = entrada[i];
		}
		argumento[k][j] = 0;
		k++;
		argumento[k] = NULL;
		if (d == ' ' && entrada[i] == '#')
			break;
	}
	return (argumento);
}

/**
 * free_argument - free all mallocs.
 * @argumento: pointer to free.
 */
void free_argument(char **argumento)
{
	int i = 0;

	if (!argumento)
		return;
	while (argumento[i])
	{
		free(argumento[i]);
		argumento[i++] = NULL;
	}
	free(argumento);
	argumento = NULL;
}
/**
 * simple_free - free a pointer
 * @entrada: pointer to free.
 */
void simple_free(char **entrada)
{
	if (entrada[0])
	{
		free(entrada[0]);
		entrada[0] = NULL;
	}
}
/**
 * free_all - free everything.
 * @entrada: pointer to free.
 * @argumento: double pointer to free.
 */
void free_all(char *entrada, char **argumento)
{
	simple_free(&entrada);
	free_argument(argumento);
}

/**
 * free2 - free 2 pointers.
 * @ptr: pointer to free.
 * @str: pointer to free.
 */
void free2(char **ptr, char **str)
{
	free_argument(ptr);
	free_argument(str);
}
