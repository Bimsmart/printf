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
	int length;
	
	if (s == NULL)
	{
		s = "(nil)";
		length = _strlen(s);
		handle_write(num, s, length);
	}
	length = _strlen(s);
	handle_write(num, s, _strlen(s));
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
	char d;

	number = number / 10;
	n = number;
	if (last < 0)
	{
		char f = '-';

		handle_write(num, &f, 1);
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
			d = last + '0';
			handle_write(num, &d, 1);
			n = n - (digit * exp);
			exp = exp / 10;
		}
	}
	d = last + '0';
	handle_write(num, &d, 1);
}
