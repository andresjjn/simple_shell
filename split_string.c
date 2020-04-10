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
	argumento = malloc((sizeof(char *) * j) + 8);
	for (i = 0; i < number;)
	{
		if (i == 0 || entrada[i++] == d)
		{
			j = i;
			len = 0;
			while (entrada[j] != d && entrada[j] != 0)
				len++, j++;
			argumento[k] = malloc((sizeof(char) * len) + 2);
			j = 0;
			while (entrada[i] != d && entrada[j] != 0)
				argumento[k][j++] = entrada[i++];
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
