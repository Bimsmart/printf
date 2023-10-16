#include "main.h"

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
	while (format[num])
	{
		num++;
	}

	va_end(printme);
}
