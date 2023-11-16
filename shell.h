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
int gj_strncmp(char *string1, char *string2, int numb);
int _putchar(char chr);
char *gj_getline(void);
int error_putchar(char chr);
void print_int(int value);
int _int_len(int integer);
char *gj_non_interactive_get_line(void);
char *gj_strtok(char *string, const char *delim);
void calls_and_executes(char *args[], char *getline_val);
int _fprintf(FILE *stream, const char *format, ...);
int _printf(const char *format, ...);
void exec_builtin_com(char **command, char *valget);
int gj_strcmp(char *str1, char *str2);

extern char **environ;
#endif
