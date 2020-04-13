#include "shell.h"

/**
 * _strcmp - Compare strings.
 * @s1: String 1.
 * @s2: String 2.
 * Return: number.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i] && s1[i] && s2[i])
	{
		i++;
	}
	if (s1[i] == s2[i])
		return (0);
	else
		return (s1[i] - s2[i]);
}
/**
 * _strcmpn - Compare strings.
 * @s1: String 1.
 * @s2: String 2.
 * @n: Number of position to compare starting from 0.
 * Return: 0 to equal strings or other to error.
 */
int _strcmpn(char *s1, char *s2, int n)
{
	int i = 0;

	while ((s1[i] == s2[i] && s1[i] && s2[i]) && i < n - 1)
	{
		i++;
	}
	if ((s1[i] == s2[i]) && i == n - 1)
		return (0);
	else
		return (s1[i] - s2[i]);
}
/**
 * _puts - print string.
 * @str: string.
 * Return: Nothing.
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		_putchar(str[i]);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * clean_string - Clean the string of spaces and new line.
 * @entrada: String to clean.
 * @len: Len of the string.
 * Return: the new string.
 */
char *clean_string(char *entrada, int len)
{
	char *new = NULL;
	int i = 0, j = 0, k = 0, t = 0;

	while (entrada[i] == ' ')
		i++, k++;
	t = i;
	while (entrada[t])
	{
		if (entrada[t] == ' ' && entrada[t + 1] == ' ')
			k++;
		t++;
	}
	while (entrada[i])
	{
		if (entrada[i] == ' ')
		{
			if (entrada[i + 1] == '\n' || entrada[i + 1] == 0)
				break;
			if (entrada[i + 1] == ' ')
			{
				i++;
				continue;
			}
		}
		if (entrada[i] != '\n' && !new)
			new = malloc((len - k) * sizeof(char));
		if (entrada[i] != '\n')
		{
			new[j] = entrada[i];
			j++;
			i++;
		}
		else
			i++;
	}
	free(entrada);
	entrada = NULL;
	if (new)
		new[j] = 0;
	return (new);
}
