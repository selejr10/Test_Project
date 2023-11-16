#include "shell.h"
#include <string.h>

/**
 * gj_getenv - Jerry and Goodnews custom getenv function to be used
 * to get current environment to our shell.
 * @name: Nmae of the environment variable to retrieve
 *
 * Return: it returns the environment on success, else NULL.
 */

char *gj_getenv(char *name)
{
        char **env,  *ent_env;

        size_t gj = 0;

        /*gj = 0;*/

        if (name == NULL)
        {
                return (NULL);
        }

	for (; *env != NULL; env++)
        /*for (char **env = environ; *env != NULL; env++)*/
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
