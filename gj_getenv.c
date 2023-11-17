#include "shell.h"
#include <string.h>

/**
 * gj_getenv - Jerry and Goodnews custom getenv function to be used
 * to get current environment to our shell.
 * @name: Name of the environment variable to retrieve
 *
 * Return: It returns the environment on success, else NULL.
 */

char *gj_getenv(char *name)
{
	char **env, *ent_env;
	size_t gj = 0;

	if (name == NULL)
	{
		return (NULL);
	}

	for (env = environ; *env != NULL; env++)
	{
		ent_env = *env;

		gj = _strlen(name);

		if (gj_strncmp(ent_env, name, gj) == 0 && ent_env[gj] == '=')
		{
			return (&ent_env[gj + 1]);
		}
	}

	return (NULL);
}
