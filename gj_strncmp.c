#include "shell.h"

/**
 * gj_strcmp - Compare two strings
 * @str1: string
 * @str2: string
 *
 * Return: negative int if str1 < str2, 0 if matching,
 * and positive int if str1 > str2
 */

int gj_strcmp(char *str1, char *str2)
{
	int gjj;

	for (gjj = 0; str1[gjj] != '\0' || str2[gjj] != '\0'; gjj++)
	{
		if (str1[gjj] != str2[gjj])
			return (str1[gjj] - str2[gjj]);
	}
	return (0);
}
