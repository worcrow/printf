#include "main.h"

/**
 * print_char - print a charactere
 * @c: charactere to be printed
 * Return: numbers of bytes printed
*/

int print_char(int c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - print a string
 * @s: string to be printed
 * Return: numbers of bytes printed
*/

int print_string(char *s)
{
	int count;

	count = 0;
	while (s[count] != '\0')
	{
		count += print_char(s[count]);
	}
	return (count);
}

/**
 * print_number - print a number based on their base
 * @number: number to be printed
 * @base: base to be printed in it
 * Return: numbers of bytes printed
*/

int print_number(long number, int base)
{
	char *symbol = "0123456789abcdef";
	int count;

	if (number < 0)
	{
		print_char('-');
		return (print_number(-number, base) + 1);
	}
	else if (number < base)
		return (print_char(symbol[number]));

	count = print_number(number / base, base);
	return (print_char(symbol[number % base]) + count);
}

