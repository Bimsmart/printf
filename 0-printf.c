#include "main.h"
#include <stdarg.h>

/**
 * _printf - prints value to the standard output
 * @format: string value
 * @...: other argumets
 *
 * Return: integer
 */
int _printf(const char *format, ...)
{
	int num;
	va_list(printme);

	if (format == NULL)
		return (0);
	va_start(printme, format);
	num = 0;
	while (*format)
	{
		if (num != "%")
		{
			write(1, format, 1);
			format++;
		}
		else
		{
			format++;
		}}
		num++;
	}

	va_end(printme);
}
