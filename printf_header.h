#ifndef HEAD_H
#define HEAD_H
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
	int print_char(int c);
	int print_string(char *s);
	int print_number(long number, int base);
	int print_format(va_list ap, char specifiers);
	int _printf(const char *format, ...);
#endif
