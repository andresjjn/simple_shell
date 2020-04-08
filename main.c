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
		printf("$ ");
		lectura = getline(&entrada, &bytes, stdin);
		if (strcmp(entrada, "\n") == 0)
		{
			free(entrada);
			entrada = NULL;
			continue;
		}

		if (strcmp(entrada, "exit\n") == 0)
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
