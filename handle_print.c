#include "main.h"

/**
 * handle_print - handle printing
 * @fmt: pointer to character
 * @list: variadic list
 * @num: pointer to num
 *
 */
void handle_print(const char *fmt, va_list list, int *num)
{
	int i;
	fmt_t fmt_types[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (*fmt == fmt_types[i].fmt)
			fmt_types[i].fn(list, num);
}
