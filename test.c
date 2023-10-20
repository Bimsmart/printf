// Online C compiler to run C program online
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	void (*fn)(va_list, int *);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

/**
 * handle_write - this function hadles write
 * @n: a pointer to no of characters
 * @str: a pointer to a string
 * @len: length of string
 * returns: void
 */
void handle_write(int *n, const char *str, int len)
{
    *n += len;
	write(1, str, len);
}

void print_char(va_list types, int *num)
{
	char c = va_arg(types, int);

	handle_write(num, &c, 1);
}

void print_string(va_list types, int *num)
{
    char *s = va_arg(types, char *);

	handle_write(num, s, strlen(s));
}
void print_percent(int *num)
{
    char c = '%';
	handle_write(num, &c, 1);
}
void write_num(int ind, char buffer[], int length, char extra_c, int *num)
{
	int i= 1;


	if (extra_c != 0)
		length++;
	
	if (extra_c)
		buffer[--ind] = extra_c;
	write(1, &buffer[ind], length);
	num += length;
}

void write_number(int is_negative, int ind, char buffer[], int *num)
{
	int length = 1024 - ind - 1;
	char extra_ch;

	if (is_negative)
		extra_ch = '-';


	write_num(ind, buffer, length, extra_ch, num);
}

void print_int(va_list types, int *_num)
{
//     char buffer[1024];
//     int i = 1024 - 2;
// 	int is_negative = 0;
// 	long int n = va_arg(types, long int);
// 	unsigned long int num;
	
// 	if (n == 0)
// 		buffer[i--] = '0';

// 	buffer[1024 - 1] = '\0';
// 	num = (unsigned long int)n;
	
// 	if (n < 0)
// 	{
// 		num = (unsigned long int)((-1) * n);
// 		is_negative = 1;
// 	}
// 	while (num > 0)
// 	{
// 		buffer[i--] = (num % 10) + '0';
// 		num /= 10;
// 	}

// 	i++;
// 	write_number(is_negative, i, buffer, _num);
    char buffer[1024];
    int number, len;
    
    number = va_arg(types, int);
    len = sprintf(buffer, "%d", number);
    fwrite(buffer, 1, len, stdout);
    *_num += len;
    
}

void handle_print(const char *fmt, va_list list, int *num)
{
    int i;
    fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent}, {'d', print_int}, {'i', print_int},  {'\0', NULL}
    };
    for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (*fmt == fmt_types[i].fmt)
			fmt_types[i].fn(list, num);
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
			handle_print(format, printme, &num);
			if (*format == '\0')
				break;
// 			if (*format == '%')
// 				handle_write(&num, format, 1);
// 			if (*format == 'c')
// 			{
// 				char c = va_arg(printme, int);

// 				handle_write(&num, &c, 1);
// 			}
// 			if (*format == 's')
// 			{
// 				char *s = va_arg(printme, char *);

// 				handle_write(1, s, strlen(s));
// 			}
// 			if (*format == 'i' || *format == 'd')
// 			number = va_arg(printme, int);
// 			len = sprint(buffer, "%d", num);
// 			fwrite(buffer, 1, len, stdout);
		}
	}
	va_end(printme);
	return (num);
}
int main()
{
    _printf("Hello %c %s %% %d world", 'f', "Fan", 6);
}
