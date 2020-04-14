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
#include <errno.h>
extern char **environ;

void sigint_h(int);
char **split_string(char *entrada, char d);
void free_argument(char **argumento);
void free_all(char *entrada, char **argumento);
void simple_free(char **entrada);
void not_found(char *name, char **argumento);
int exec(char **argumento, char **env, char *name);
char *clean_string(char *entrada, int len);
int _putchar(char c);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _strcmpn(char *s1, char *s2, int n);
int _strlen(char *s);
char *string_con(char *s1, char *s2);
char *_getenv(char *arg, char **env);
int built_ins(char **argumento, char **env);
int cd_built_in(char **argumento, char **env);
char **cpy_env(void);
int _steven(char **env, char **argumento, int n);
char **find_path(char **env);
void free2(char **ptr, char **str);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif /* SHELL_H */
