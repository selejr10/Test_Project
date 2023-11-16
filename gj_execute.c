#include "shell.h"

void exec_builtin_com(char **command, char *valget);

/**
 * exec_builtin_com - A function that handles builtin commands
 *
 * @command: this is the command arguments to be checked.
 * @valget: getline value argument to  free.
 * Return: Always 0
 */

void exec_builtin_com(char **command, char *valget)
{
	char executable_file[MAX_INPUT_SIZE];

	char *file_path = "/bin/";

	if (gj_strcmp(command[0], "exit") == 0)
	{
		if (command[1] != NULL)
		{
			char *endptr;

			long status = strtol(command[1], &endptr, 10);

			if (gj_strcmp(command[1], "-98") == 0)
			{
				char *a = command[0];

				char *b = command[1];

				int n = 1;

				char *ms = "./hsh: %d: %s: Illegal number: %s\n";

				_fprintf(stderr, ms, n, a, b);
				free(valget);
				free(command);
				exit(2);
			}

			if (*endptr == '\0')
			{
				free(valget);
				free(command);
				exit(status);
			}
			else
			{
				char *a = command[0];

				char *b = command[1];

				int n = 1;

				char *ms = "./hsh: %d: %s: invalid input: %s\n";

				_fprintf(stderr, ms, n, a, b);
				free(valget);
				free(command);
				exit(2);
			}
		}
		else
		{
			free(valget);
			free(command);
			exit(0);
		}
	}
	else if (gj_strcmp(command[0], "env") == 0)
	{
		char **env;

		for (env = environ; *env != NULL; env++)
		{
			_printf("%s\n", *env);
		}
	}
	else if (gj_strcmp(command[0], "setenv") == 0)
	{
		/*implement*/
	}
	else if (gj_strcmp(command[0], "unsetenv") == 0)
	{
		/*implement*/
	}
	else if (gj_strcmp(command[0], "cd") == 0)
	{
		/*implement*/
	}
	else if (gj_strcmp(command[0], "#") == 0)
	{
		/*NIL*/
	}
	else
	{
		if (strchr(command[0], '/') != NULL)
		{
			if (access(command[0], X_OK) != -1)
			{
				calls_and_executes(command, valget);
			}
			else
			{
				int n = 1;

				char *ms = "./hsh: %d: %s: unavailable\n";

				_fprintf(stderr, ms, n, command[0]);
				free(valget);
				free(command);
				exit(127);
			}
		}
		else
		{
			strcpy(executable_file, file_path);
			strcat(executable_file, command[0]);

			if (access(executable_file, X_OK) != -1)
			{
				calls_and_executes(command, valget);
			}
			else
			{
				char *ms = "./hsh: %d: %s: unavailable\n";

				_fprintf(stderr, ms, 1, command[0]);
				free(valget);
				free(command);
				exit(127);
			}
		}
	}
}
