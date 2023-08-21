#include "main.h"

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
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	if (format[0] == '\0')
		return (-1);
	while (format && format[i] != '\0')
	{
		temp = 0;
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
			{
				count += print_char('%');
				i++;
			}
			else
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
		}
		else
			count += print_char(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}

