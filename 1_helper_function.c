#include "shell.h"

/**
 * _strlen - Lenght of a funtion.
 * @s: String variable input.
 * Return: a (length of string)
 */
int _strlen(char *s)
{
	int a = 0;

	while (*s != '\0')
	{
		a++;
		s++;
	}
	return (a);
}

/**
 * string_con - Function that concatenates two strings.
 * @s1: String 1 to concatenate.
 * @s2: String 2 to concatenate.
 * Return: Pointer of concatenated string.
 */
char *string_con(char *s1, char *s2)
{
	char *s;
	unsigned int i, t, n, m;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	n = _strlen(s1);
	m = _strlen(s2);
	t = (n + m + 1);
	s = malloc(sizeof(char) * t);
	if (s == NULL)
		return (NULL);
	for (i = 0; i < t; i++)
	{
		if (i < n)
			s[i] = s1[i];
		else if (i < t - 1 && i >= n)
			s[i] = s2[i - n];
		else if (i >= t - 1)
			s[i] = '\0';
	}
	return (s);
}

/**
 * _getenv - Get a specific line of path.
 * @arg: Parameter to search in env.
 * Return: Pinter with value required.
 */
char *_getenv(char *arg)
{
	int i = 0, j = 0;

	i = _strlen(arg);
	while (environ[j])
	{
		if (_strcmpn(environ[j], arg, i) == 0)
			break;
		j++;
	}
	return (&environ[j][i + 1]);
}
