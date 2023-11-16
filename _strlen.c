#include "shell.h"

/**
 * _strlen - Function returns the length of a string.
 * @string: string.
 *
 * Return: length
 */
size_t _strlen(const char *string)
{
        size_t length;

        length = 0;

        while (*string++)
                length++;

        return (length);
}
