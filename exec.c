#include "shell.h"

/**
 * exec - Excecute a command with flags.
 * @argumento: Double pointer with command info.
 * @env: Enviroment variable.
 * Return: 0 works or -1 error.
 */
int exec(char **argumento, char **env)
{
	pid_t chinga = 0;
	struct stat stats;
	char **path = NULL, *s = NULL, *s1 = NULL;
	int i = 0;

	if (argumento == NULL)
		return (-1);
	chinga = fork();
	if (chinga != 0)
		wait(NULL);
	if (chinga == 0)
	{
		path = find_path(env);
		while (path[i])
		{
			if (path[i][_strlen(path[i])] == '/')
				s = string_con(path[i], argumento[0]);
			else
			{
				s1 = string_con(path[i], "/");
				s = string_con(s1, argumento[0]);
				free(s1);
				s1 = NULL;
			}
			if (access(s, X_OK) == 0)
			{
				printf("Entró a access");
				if (!stat(s, &stats))
				{
					if (execve(s, argumento, NULL) != -1)
					{
						free(s);
						s = NULL;
						break;
					}
				}
			}
			i++;
		}
		free_argument(argumento);
		free_argument(path);
		exit(0);
	}
	free_argument(argumento);
	free_argument(path);
	return (0);
}

/**
 * find_path - Split by arrays the paths into env
 * @env: Enviroment variable.
 * Return: Double pointer with paths.
 */
char **find_path(char **env)
{
	char **path = NULL, *s = NULL;

	s = _getenv("PATH", env);
	path = split_string(s, ':');
	return (path);
}
