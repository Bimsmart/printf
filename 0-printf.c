#include "main.h"
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
/**
 * handle_write - this function hadles write
 * @n: a pointer to no of characters
 * @str: a pointer to a string
 * @len: length of string
 * returns: void
 */
void handle_write(int *n, char *str, int len)
{
	write(1, str, len);
	*n += len;
}
/**
 * _printf - prints value to the standard output
 * @format: string value
 * @...: other argumets
 *
 * Return: integer
 */
int _printf(const char *format, ...)
{
	int num = 0, len, number;
	char buffer[1024];

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
				handle_write(&num, format, 1);
			if (*format == 'c')
			{
				char c = va_arg(printme, int);

				handle_write(&num, &c, 1);
			}
			if (*format == 's')
			{
				char *s = va_arg(printme, char *);

				handle_write(1, s, strlen(s));
			}
			if (*format == 'i' || *format == 'd')
			number = va_arg(printme, int);
			len = sprint(buffer, "%d", num);
			fwrite(buffer, 1, len, stdout);
		}
	}
	va_end(printme);
	return (num);
}
