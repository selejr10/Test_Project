#include "shell.h"
#define BUFFER_SIZE 12

/**
 * error_putchar - Prints a single character to the standard error output.
 * @chr: The character to be printed.
 *
 * Return: On success, returns the number of printed characters.
 */

int error_putchar(char chr)
{
	return (write(STDERR_FILENO, &chr, 1));
}

/**
 * print_int - A function that prints an integer
 * @value: integer to be printed.
 * Return: Always 0
 */

void print_int(int value)
{
	int n = 0;
	int _idx = 0;
	char buf[BUFFER_SIZE];

	if (value < 0)
	{
		error_putchar('-');
		value = -(value);
	}

	if (value == 0)
	{
		error_putchar('0');
		return;
	}

	while (value > 0 && _idx < BUFFER_SIZE - 1)
	{
		buf[_idx] = '0' + (value % 10);
		value = value / 10;
		_idx = _idx + 1;
	}

	for (n = _idx - 1; n >= 0; n--)
	{
		error_putchar(buf[n]);
	}
}

/**
 * _int_len - Function calculates the length of an integer.
 * @integer: integer length to be counted.
 * Return: length of the integer.
 */

int _int_len(int integer)
{
	int gj_exact_len = 0;

	if (integer == 0)
	{
		return (1);
	}

	if (integer < 0)
	{
		gj_exact_len++;
		integer = -(integer);
	}

	while (integer > 0)
	{
		gj_exact_len++;
		integer /= 10;
	}

	return (gj_exact_len);
}
