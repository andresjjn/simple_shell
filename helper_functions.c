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
 * _strcmp - Compare strings.
 * @s1: String 1.
 * @s2: String 2.
 * Return: number.
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
	int i = 0, j = 0;

	while (entrada[i] == ' ')
		i++;
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
			new = malloc(len + 1);
		if (entrada[i] != '\n')
			new[j++] = entrada[i++];
		else
			i++;
	}
	free(entrada);
	if (new)
		new[j] = 0;
	return (new);
}
