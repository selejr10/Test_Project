#include "shell.h"
#include <stdbool.h>

int main(void);

/**
 * main - Entry point for simple shell.
 * Return: 0 on success.
 */

int main(void)
{
	bool interactive_shell;
	char *chars_read;
	char **cmd_args;
	char *_prompt = "Jerry&Goodnews$ ", *token;
	int _idx = 0;

	interactive_shell = isatty(fileno(stdin));

	while (true)
	{
		if (interactive_shell)
		{
			_printf("%s", _prompt);
			fflush(stdout);

			chars_read = gj_getline();

			if (chars_read == NULL)
			{
				break;
			}
		}
		else
		{
			chars_read = gj_non_interactive_get_line();

			if (chars_read == NULL)
			{
				break;
			}
		}

		if (strstr(chars_read, ";") != NULL)
		{
			free(chars_read);
			continue;
		}

		cmd_args = malloc(sizeof(char *) * (MAX_ARGS + 1));

		if (cmd_args == NULL)
		{
			perror("Memory Allocation Fail");
			exit(EXIT_FAILURE);
		}

		token = gj_strtok(chars_read, " \t\r\n\a");

		while (token != NULL && _idx < MAX_ARGS)
		{
			cmd_args[_idx] = token;
			_idx++;
			token = gj_strtok(NULL, " \t\r\n\a");
		}

		cmd_args[_idx] = NULL;

		if (!_idx)
		{
			free(chars_read);
			free(cmd_args);
			continue;
		}

		execute_builtin_command(cmd_args, chars_read);

		free(chars_read);
		free(cmd_args);

		if (interactive_shell == 0)
		{
			break;
		}
	}

	return (0);
}
