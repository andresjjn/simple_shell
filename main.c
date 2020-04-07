#include "shell.h"

/**
 * main - Shell code with C.
 * Return: - 0;
 */
int main(void)
{
	size_t bytes = 0;
	char *entrada;
	char **argumento;
	int lectura;

	while (1)
	{
		printf("$ ");
		lectura = getline(&entrada, &bytes, stdin);
		if (strcmp(entrada, "\n") == 0)
			continue;
		argumento = split_string(entrada, lectura);
		exec(argumento);
		free_argument(argumento);
		free(entrada);
	}
	return (0);
}
