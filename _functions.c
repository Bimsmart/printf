#include "main.h"

/**
 * print_char - print character
 * @types: va_list
 * @num: integer
 */
void print_char(va_list types, int *num)
{
	char c = va_arg(types, int);

	handle_write(num, &c, 1);
}
/**
 * print_string - print string
 * @types: va_list
 * @num: integer
 */
void print_string(va_list types, int *num)
{
	char *s = va_arg(types, char *);

	handle_write(num, s, strlen(s));
}
/**
 * print_percent - print percentage
 * @num: integer
 */
void print_percent(int *num)
{
	char *c = '%';

	handle_write(num, &c, 1);
}
