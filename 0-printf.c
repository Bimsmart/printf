#include "main.h"
#include <unistd.h>
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
		return (-1);
	va_start(printme, format);
	for (; *format; format++)
	{
		if (*format != '%')
		{
			handle_write(&num, format, 1);
		} else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
				handle_write(&num,format, 1);
			handle_print(format, printme, &num);
		}
	}
	va_end(printme);
	return (num);
}
