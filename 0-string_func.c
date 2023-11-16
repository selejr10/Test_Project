#include "shell.h"


/**
* _putchar - Function prints a character to the standard output.
* @chr: character to be printed.
* Return: the printed character to stdout.
*/
int _putchar(char chr)
{
        return (write(1, &chr, 1));
}


/**
* gj_strncmp - the function gj_strncmp compares two strings
* @string1: first string to be comapred.
* @string2: second string to be compared.
* @numb: byte size to be comapared.
* Return: on success returns 0.
*/

int gj_strncmp(char *string1, char *string2, int numb)
{
        int g = 0;
        int j = 0;

        while ((*string1 != '\0' || *string2 != '\0') && j < numb)
        {
                if (*string1 != *string2)
                {
                        g += 1;
                }

                string1 = string1 + 1;

                string2 += 1;

                j = j + 1;
        }

        if (g != 0)
        {
                return (-1);
        }

        return (g);
}
