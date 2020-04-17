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
	char **argumento = NULL;
	int lectura = 0, count = 1, status = 0;

	if (argc != 1)
		exit(127);
	env = cpy_env();
	signal(SIGINT, sigint_h);
	for (; 1; lectura = 0, count++)
	{
		if (isatty(STDIN_FILENO) != 0 && isatty(STDOUT_FILENO) != 0)
			_puts("$ ");
		lectura = getline(&entrada, &bytes, stdin);
		if (lectura == -1)
			break;
		entrada = clean_string(entrada, lectura);
		if (!entrada)
			continue;
		argumento = split_string(entrada, ' ');
		simple_free(&entrada);
		if (argumento == NULL)
			continue;
		if (built_ins(argumento, &status, argv[0], count))
			continue;
		status = exec(argumento, argv[0], count);
		status = status >> 8;
	}
	free_all(entrada, env);
	return (status);
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
