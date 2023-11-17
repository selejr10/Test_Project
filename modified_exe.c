#include "shell.h"

void calls_and_executes(char *args[], char *getline_val);

/**
 * calls_and_executes - Executes the given command and handles exit status
 * @args: Command line arguments to execute
 * @getline_val: this is the getline value to be freed.
 */

void calls_and_executes(char *args[], char *getline_val)
{
	pid_t pid_value;
	int _status;

	pid_value = fork();

	if (pid_value == -1)
	{
		perror("Fork Error");

		free(getline_val);
		free(args);

		exit(EXIT_FAILURE);
	}

	if (pid_value == 0)
	{
		if (strchr(args[0], '/') != NULL)
		{
			if (execve(args[0], args, environ) == -1)
			{
				perror("Error: Execution terminated");
				free(getline_val);
				free(args);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			char *path = gj_getenv("PATH");
			char *token = gj_strtok(path, ":");

			while (token != NULL)
			{
				char executable_file[MAX_INPUT_SIZE];

				strcpy(executable_file, token);
				strcat(executable_file, "/");
				strcat(executable_file, args[0]);

				if (access(executable_file, X_OK) != -1)
				{
					execve(executable_file, args, environ);
				}

				token = gj_strtok(NULL, ":");
			}
			fprintf(stderr, "./hsh: %d: %s: cannot find\n", 1, args[0]);
			free(getline_val);
			free(args);
			exit(127);
		}
	}
	else
	{
		do {
			waitpid(pid_value, &_status, 0);

			if (WIFEXITED(_status))
			{
				free(getline_val);
				free(args);
				exit(WEXITSTATUS(_status));
			}
			if (WIFSIGNALED(_status))
			{
				raise(WTERMSIG(_status));
			}
		} while (WIFEXITED(_status) && WIFSIGNALED(_status));
	}
}
