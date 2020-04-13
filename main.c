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
	env = cpy_env();
	signal(SIGINT, sigint_h);
	while (1)
	{
		lectura = 0;
		if (isatty(STDIN_FILENO) != 0 && isatty(STDOUT_FILENO) != 0)
			_puts("$ ");
		lectura = getline(&entrada, &bytes, stdin);
		if (lectura == -1)
			break;
		entrada = clean_string(entrada, lectura);
		if (!entrada)
			continue;
		if (_strcmp(entrada, "exit") == 0)
		{
			free(entrada);
			free_argument(env);
			entrada = NULL;
			fflush(stdout);
			exit(0);
		}
		argumento = split_string(entrada, ' ');
		if (built_ins(argumento, env))
			{
				free(entrada);
				entrada = NULL;
				continue;
			}
		exec(argumento, env, argv[0]);
		if (entrada)
		{
			free(entrada);
			entrada = NULL;
		}
	}
	if (entrada)
	{
		free(entrada);
		entrada = NULL;
	}
	return (0);
}
/**
 * sigint_h - In case of press CTRL + C this don't exit the shell.
 * @n: sigint number.
 */
void sigint_h(int n)
{
	(void)n;
	_puts("\n$ ");
	fflush(stdout);
}
