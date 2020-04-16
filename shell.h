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
void print_error(char *name, char **argumento, int count, char *msn, char *ar);
int exec(char **argumento, char **env, char *name, int count);
char *clean_string(char *entrada, int len);
int _putchar(char c);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _strcmpn(char *s1, char *s2, int n);
int _strlen(char *s);
char *string_con(char *s1, char *s2);
char *_getenv(char *arg, char **env);
int built_ins(char **argumento, char **env, int *status, char* name, int count);
int cd_built_in(char **argumento, char **env);
char **cpy_env(void);
int _steven(char **env, char **argumento, int n);
char **find_path(char **env);
void free2(char **ptr, char **str);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void print_number(int n);
int _putchar2(char c);
void _puts2(char *str);
int exit_built_in(char **argumento, int status, char **env);
void setenv_from_functions(char **env, char *ar1, char *ar2);
int cd_built_in2(char **argumento, char **env);
int _unsteven(char **env, char **argumento);

#endif /* SHELL_H */
