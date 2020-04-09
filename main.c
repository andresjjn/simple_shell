#include "shell.h"
/**
 * main - Shell code with C.
 * Return: - 0;
 */
int main(void)
{
	size_t bytes = 0;
	char *entrada = NULL;
	char **argumento = NULL;
	int lectura = 0;

	while (1)
	{
		lectura = 0;
		_puts("$ ");
		lectura = getline(&entrada, &bytes, stdin);
		entrada = clean_string(entrada, lectura);
		if (!entrada)
			continue;
		if (_strcmp(entrada, "exit") == 0)
		{
			free(entrada);
			entrada = NULL;
			return(EXIT_SUCCESS);
		}
		argumento = split_string(entrada, lectura);
		exec(argumento);
	}
	free(entrada);
	entrada = NULL;
	return (0);
}
