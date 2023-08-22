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
	char *temp;
	char c;
	int ind;

	if (s == NULL)
		temp = "(null)";
	else
		temp = s;
	count = 0;
	ind = 0;
	while (temp[ind] != '\0')
	{
		c = temp[ind];
		if ((c > 0 && c < 32) || c >= 127)
		{
			print_char('\\');
			print_char('x');
			print_number(c, 16, 1) + 2;
			count++;
		}
		else
			count += print_char(c);
		ind++;
	}
	return (count);
}

/**
 * print_number - print a number based on their base
 * @number: number to be printed
 * @base: base to be printed in it
 * Return: numbers of bytes printed
*/

int print_number(long number, int base, int is_upper)
{
	char *symbol;
	int count;

	if (is_upper)
		symbol ="0123456789ABCDEF";
	else
		symbol = "0123456789abcdef";
	if (number < 0)
	{
		print_char('-');
		return (print_number(-number, base, is_upper) + 1);
	}
	else if (number < base)
		return (print_char(symbol[number]));

	count = print_number(number / base, base, is_upper);
	return (print_char(symbol[number % base]) + count);
}

