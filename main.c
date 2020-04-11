#include "shell.h"
/**
 * main - Shell code with C.
 * @argc: Number of input args.
 * @argv: Array of parameters.
 * Return: - 0;
 */
int main(int argc, char *argv[])
{
	size_t bytes = 0;
	char *entrada = NULL;
	char path[PATH_MAX];
	char **argumento = NULL, **env = NULL;
	int lectura = 0;

	if (argc != 1)
	{
		exit(127);
	}
	(void)argv;
	env = cpy_env();
	while (1)
	{
		lectura = 0;
		if (isatty(STDIN_FILENO) != 0 && isatty(STDOUT_FILENO) != 0)
		{
			_puts(getcwd(path, sizeof(path)));
			_puts("$ ");
		}
		lectura = getline(&entrada, &bytes, stdin);
		if (lectura == -1)
			break;
		entrada = clean_string(entrada, lectura);
		if (!entrada)
			continue;
		if (_strcmp(entrada, "exit") == 0)
		{
			free(entrada);
			entrada = NULL;
			return (EXIT_SUCCESS);
		}
		argumento = split_string(entrada, ' ');
		if (built_ins(argumento, env))
			continue;
		exec(argumento);
	}
	free(entrada);
	entrada = NULL;
	return (0);
}
