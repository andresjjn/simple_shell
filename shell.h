#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
char **split_string(char *entrada, int len);
void free_argument(char **argumento);
int exec(char **argumento);

#endif /* SHELL_H */
