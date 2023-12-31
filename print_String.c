#include "main.h"

/**
 * print_String - print a string with it non_printable char
 * @str: string to be printed
 * Return: return the numbers of bytes written
*/

int print_String(char *str)
{
	int count;
	int ind;
	char c;
	char *temp;

	count = 0;
	ind = 0;
	temp = (str == NULL) ? "(null)" : str;
	while (temp[ind] != '\0')
	{
		c = temp[ind++];
		if ((c > 0 && c < 32) || c >= 127)
		{
			print_string("\\x");
			if (c < 16)
				count += print_number(0, 10, 0);
			count += print_number(c, 16, 1) + 2;
		}
		else
			count += print_char(c);
	}
	return (count);
}
