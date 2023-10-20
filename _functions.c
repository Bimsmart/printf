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
	int i;
	
	if (str == NULL)
	{
		str = "(nil)";
		length = _strlen(str);
		for (i = 0; i < length; i++)
			handle_write(num,(str + i), 1);
	}
	handle_write(num, s, _strlen(s));
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
/**
 * print_int - print
 * @types: va_list
 * @num: integer
 */
void print_int(va_list types, int *num)
{
	int number = va_arg(types, int);
	int n, last = number % 10, digit, exp = 1;
	int i = 1;

	number = number / 10;
	n = number;
	if (last < 0)
	{
		handle_write(num, '-', 1);
		n = -n;
		number = -number;
		last = -last;
	}
	if (n > 0)
	{
		while (n / 10 != 0)
		{
			exp = exp * 10;
			n = n / 10;
		}
		n = number;
		while (exp > 0)
		{
			digit = n / exp;
			handle_write(num, digit + '0', 1);
			n = n - (digit * exp);
			exp = exp / 10;
		}
	}
	handle_write(num, last + '0', 1);
}
