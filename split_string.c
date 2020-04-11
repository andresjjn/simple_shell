#include "shell.h"
/**
 * split_string - divide a string into several within a double pointer.
 * @entrada: string.
 * @d: delimiter.
 * Return: The new double pointer.
 */

char **split_string(char *entrada, char d)
{
	int i = 0, j = 1, k = 0, len = 0, number = 0;
	char **argumento = NULL;

	number = _strlen(entrada);
	for (i = 0; entrada[i] != '\0'; i++)
		if (entrada[i] == d)
			j++;
	argumento = malloc(sizeof(char *) * (j + 1));
	for (i = 0; i < number;)
	{
		if (i == 0 || entrada[i++] == d)
		{
			len = 0;
			while (entrada[len] && entrada[len] != d)
				len++;
			argumento[k] = malloc(sizeof(char) * (len + 1));
			if (!argumento[k])
			{
				free_argument(argumento);
				return(NULL);
			}
			for (j = 0; entrada[j] && entrada[j] != d; i++, j++)
				argumento[k][j] = entrada[i];
			argumento[k][j] = 0;
			k++;
			argumento[k] = NULL;
		}
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
