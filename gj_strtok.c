#include "shell.h"

/**
 * gj_strtok - A custom function that tokenizes a string
 * @string: string to be tokenized which is the first argument.
 * @delim: this represents the delimiter of the string
 *
 * Return: tokenized string on success, else NULL.
 */

char *gj_strtok(char *string, const char *delim)
{
	static char *nxt_tkn;
	char *new_tkn;

	if (string != NULL)
	{
		nxt_tkn = string;
	}

	if (nxt_tkn == NULL || *nxt_tkn == '\0')
	{
		return (NULL);
	}

	while (*nxt_tkn != '\0' && strchr(delim, *nxt_tkn) != NULL)
	{
		nxt_tkn++;
	}

	if (*nxt_tkn == '\0')
	{
		return (NULL);
	}

	new_tkn = nxt_tkn;

	while (*nxt_tkn != '\0' && strchr(delim, *nxt_tkn) == NULL)
	{
		nxt_tkn = nxt_tkn + 1;
	}

	if (*nxt_tkn != '\0')
	{
		*nxt_tkn = '\0';
		nxt_tkn = nxt_tkn + 1;
	}

	return (new_tkn);
}
