#include "shell.h"
/**
 * main - Shell code with C.
 * Return: - 0;
 */
int main(void)
{
	size_t bytes = 0;
	char *entrada = NULL;
	char path[PATH_MAX];
	char **argumento = NULL;
	int lectura = 0;

	while (1)
	{
		lectura = 0;
			_puts(getcwd(path, sizeof(path)));
			_puts(" $ ");
		lectura = getline(&entrada, &bytes, stdin);
		if (lectura < 1)
		{
			if (isatty(STDIN_FILENO) != 0 && isatty(STDOUT_FILENO) != 0)
			{
				_putchar('\n');
				break;
			}
		}
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
