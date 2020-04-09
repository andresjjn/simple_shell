#ifndef SHELL_H
#define SHELL_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <limits.h>

char **split_string(char *entrada, int len);
void free_argument(char **argumento);
int exec(char **argumento);
char *clean_string(char *entrada, int len);
int _putchar(char c);
void _puts(char *str);
int _strcmp(char *s1, char *s2);

#endif /* SHELL_H */
