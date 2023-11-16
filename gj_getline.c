#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
* gj_getline - Our getline function that reads input from the shell
*
* Return: this function returns the array of read strings on success.
*/

char *gj_getline(void)
{
        char *buffer = NULL;
        size_t buffer_size = 0;
        ssize_t chars_read;

       /* printf("Jerry&Goodnews$ ");*/


        if ((chars_read = getline(&buffer, &buffer_size,stdin)) == -1)
        {
                if (feof(stdin))
                {
                        printf("\n");
                        free(buffer);
                        exit(EXIT_SUCCESS);
                }

                else
                {
                        perror("Failed to read input");
                        free(buffer);
                        exit(EXIT_FAILURE);
                }
        }

        return (buffer);
}
