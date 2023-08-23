#include "main.h"

/**
 * print_format - print the argument based on their specifiers
 * @ap: argument to be printed
 * @specifiers: format specifiers like %d,%s,..
 * Return: numbers of bytes printed
*/

int print_format(va_list ap, char specifiers)
{
	int count = 0;

	switch (specifiers)
	{
		case 'c':
			count += print_char((char) va_arg(ap, int));
			break;
		case 's':
			count += print_string(va_arg(ap, char *));
			break;
		case 'i':
		case 'd':
			count += print_number(va_arg(ap, int), 10, 0);
			break;
		case 'o':
			count += print_number((unsigned int) va_arg(ap, int), 8, 0);
			break;
		case 'x':
			count += print_number((unsigned int) va_arg(ap, int), 16, 0);
			break;
		case 'b':
			count += print_number((unsigned int) va_arg(ap, int), 2, 0);
			break;
		case 'u':
			count += print_number((unsigned int) va_arg(ap, int), 10, 0);
			break;
		case 'X':
			count += print_number((unsigned int) va_arg(ap, int), 16, 1);
			break;
		case 'S':
			count += print_String(va_arg(ap, char *));
			break;
		default:
			return (-1);
	}
	return (count);
}
