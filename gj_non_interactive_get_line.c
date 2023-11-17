#include "shell.h"

#define INITIAL_BUFFER_SIZE 1024
#define BUFFER_INCREMENT 1024

char *gj_non_interactive_get_line(void);

/**
 * gj_non_interactive_get_line - Custom getline for non-interactive shell
 * function reads input from a file stream using the read function.
 *
 * @void - if failure
 * Return:
 * - On sucess: a pointer to the array of characters read from the file stream.
 * - On failure or encountering end-of-file (EOF) or empty input: returns NULL.
 */

char *gj_non_interactive_get_line(void)
{
	ssize_t read_value;

	char *buffer = malloc(INITIAL_BUFFER_SIZE * sizeof(char));

	if (buffer == NULL)
	{
		perror("Memory Allocation Fail");
		exit(EXIT_FAILURE);
	}

	int index = 0;

	size_t buffer_size = INITIAL_BUFFER_SIZE;

	while ((read_value = read(STDIN_FILENO, &buffer[index], 1)) > 0)
	{

		if (buffer[index] == EOF || buffer[index] == '\n')
		{
			break;
		}

		index++;

		if (index >= (int)buffer_size - 1)
		{

			buffer_size += BUFFER_INCREMENT;
			char *temp = realloc(buffer, buffer_size);

			if (temp == NULL)
			{
				perror("Reallocation of memory failed");
				free(buffer);
				exit(EXIT_FAILURE);
			}

			buffer - temp;
		}
	}
	if (read_value == -1)
	{
		perror("Error");
		free(buffer);
		exit(EXIT_FAILURE);
	}
	if (read_value == 0)
	{
		free(buffer);
		exit(EXIT_FAILURE);
	}
	buffer[index] = '\0';
	return (buffer);
}
