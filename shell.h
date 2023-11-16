#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>

#include <stdarg.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 1024

size_t _strlen(const char *string);
char *gj_getenv(char *name);

extern char **environ;
#endif
