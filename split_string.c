#include "shell.h"
/**
 * split_string - divide a string into several within a double pointer.
 * @entrada: string.
 * @number: len of the string.
 * Return: The new double pointer.
 */

char **split_string(char *entrada, int number)
{
	int i, j = 1, k = 0, len;
	char **argumento;
	char dir[5] = "/bin/";

	for (i = 0; entrada[i] != '\0'; i++)
		if (entrada[i] == ' ' && entrada[i + 1] != ' ' && entrada[i + 1] != '\n')
			j++;
	entrada[i - 1] = 0;
	argumento = malloc((sizeof(char *) * j) + 1);
	for (i = 0; i < number;)
	{
		if (i == 0 || entrada[i++] == ' ')
		{
			j = i;
			len = 0;
			while (entrada[j] != ' ' && entrada[j++] != '\n')
				len++;
			if (k == 0)
			{
				argumento[k] = malloc((sizeof(char) * ++len) + 5);
				for (j = 0; j < 5; j++)
					argumento[k][j] = dir[j];
				while (entrada[i] != ' ' && entrada[i] != '\n')
					argumento[k][j++] = entrada[i++];
				argumento[j] = 0;
				k++;
			}
			else
			{
				argumento[k] = malloc(sizeof(char) * ++len);
				j = 0;
				while (entrada[i] != ' ' && entrada[i] != '\n')
					argumento[k][j++] = entrada[i++];
				argumento[k][j] = 0;
				k++;
				argumento[k] = 0;
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

	while (argumento[i])
		free(argumento[i++]);
	free(argumento[i]);
	free(argumento);
}
