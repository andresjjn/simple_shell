#include "shell.h"

/**
 * main - Shell code with C.
 * Return: -
 */
int main(void)
{
	size_t bytes = 0;
	char *entrada;
	char **argumento;
	int i = 0, lectura;

	while (1)
	{
		printf("$ ");
		lectura = getline(&entrada, &bytes, stdin);
		if (strcmp(entrada, "\n") == 0)
			continue;
		argumento = split_string(entrada, lectura);
		while (argumento[i])
		{
			printf("%s", argumento[i]);
			i++;
		}
		i = 0;
		free_argument(argumento);
		free(entrada);
	}
	return (0);
}