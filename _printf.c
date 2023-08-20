#include "printf_header.h"

/**
 * _printf - mimic printf function
 * @format: string to be printd
 * @...: variadic function
 * Return: numbers of bytes printd
*/

int _printf(const char *format, ...)
{
	va_list ap;
	int i;
	int count;
	int temp;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format && format[i] != '\0')
	{
		temp = 0;
		if (format[i] == '%')
		{
			temp = print_format(ap, format[i + 1]);
			if (temp == -1)
				count += print_char(format[i]);
			else
			{
				count += temp;
				i++;
			}
		}
		else
			count += print_char(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}

