#include "main.h"
#include <string.h>
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
	int num = 0;

	va_list(printme);
	if (format == NULL)
		return (0);
	va_start(printme, format);
	while (*format)
	{
		int num = 0;

		if (format != "%")
		{
			write(1, format, 1);
			format++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				num++;
			}
			if (*format == 'c')
			{
				char c = va_arg(printme, int);

				write(1, &c, 1);
				num++;
			}
			if (*format == 's')
			{
				char *s = va_arg(printme, char *);

				write(1, s, strlen(s));
				num += strlen(s);
			}
		}
		format++;
	}
	va_end(printme);
	return (num);
}}
