#include "shell.h"

/**
 * main - Shell code with C.
 * Return: -
 */
int main(void)
{
	size_t bytes = 0;
	int lectura;
	char *entrada;
	char *token;
	/*char **argumento;*/

	while (1)
	{
		printf("$ ");
		lectura = getline(&entrada, &bytes, stdin);
		split_string(entrada, lectura);
		if (strcmp(entrada, "\n") == 0)
			continue;
		if (lectura == -1)
			break;
		entrada = strcat("/bin/", "");
		token = strtok(entrada, " ");

		while (token)
		{
			printf("%s", token);
			token = strtok(NULL, " ");
		}
	}
	return (0);
}
