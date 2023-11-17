#include "shell.h"

/**
 * _strcmp - Compare two strings
 * @str1: string
 * @str2: string
 *
 * Return: negative int if str1 < str2, 0 if matching,
 * and positive int if str1 > str2
 */

int _strcmp(char *str1, char *str2)
{
	int gj;

	for (gj = 0; str1[gj] != '\0' || str2[gj] != '\0'; gj++)
	{
		if (str1[gj] != str2[gj])
			return (str1[gj] - str2[gj]);
	}
	return (0);
}
