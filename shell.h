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

extern char **environ;

char **split_string(char *entrada, char d);
void free_argument(char **argumento);
int exec(char **argumento);
char *clean_string(char *entrada, int len);
int _putchar(char c);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _strcmpn(char *s1, char *s2, int n);
int _strlen(char *s);
char *string_con(char *s1, char *s2);
char *_getenv(char *arg);
int built_ins(char **argumento, char **env);
int cd_built_in(char **argumento);
char **cpy_env(void);
char **_steven(char *name, char *ptr, char **env);

#endif /* SHELL_H */
