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
		if (*format != "%")
		{
			write(1, format, 1);
			num++;
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
				num++;
			}
			if (*format == 's')
			{
				int strlen = 0;
				char *str = va_arg(printme, char*);

				while (str[strlen] != '\0')
					strlen++;
				write(1, str, strlen);
				num += strlen;
			}
		}
	}
	va_end(printme);
	return (num);
}
