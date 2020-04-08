#include "shell.h"
/**
 * split_string - divide a string into several within a double pointer.
 * @entrada: string.
 * @number: len of the string.
 * Return: The new double pointer.
 */

char **split_string(char *entrada, int number)
{
	int i = 0, j = 1, k = 0, len = 0;
	char **argumento = NULL;
	char dir[5] = "/bin/";

	for (i = 0; entrada[i] != '\0'; i++)
		if (entrada[i] == ' ' && entrada[i + 1] != ' ' && entrada[i + 1] != '\n')
			j++;
	entrada[i - 1] = 0;
	argumento = malloc((sizeof(char *) * j) + 9);
	for (i = 0; i < number;)
	{
		if (i == 0 || entrada[i++] == ' ')
		{
			j = i;
			len = 0;
			while (entrada[j] != ' ' && entrada[j++] != '\n' && entrada[j] != 0)
				len++;
			if (k == 0)
			{
				argumento[k] = malloc((sizeof(char) * ++len) + 6);
				for (j = 0; j < 5; j++)
					argumento[k][j] = dir[j];
				while (entrada[i] != ' ' && entrada[i] != '\n' && entrada[i] != 0)
					argumento[k][j++] = entrada[i++];
				argumento[k][j] = 0;
				k++;
			}
			else
			{
				argumento[k] = malloc((sizeof(char) * len) + 2);
				j = 0;
				while (entrada[i] != ' ' && entrada[i] != '\n' && entrada[j] != 0)
					argumento[k][j++] = entrada[i++];
				argumento[k][j] = 0;
				k++;
				argumento[k] = NULL;
			}
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
