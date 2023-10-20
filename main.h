#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * struct fmt - Struct op
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	void (*fn)(va_list, int *);
}
/**
 * typedef struct fmt fmt_t - Struct op
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
void handle_print(const char *fmt, va_list list, int *num);
void handle_write(int *n, const char *str, int len);
void print_char(va_list types, int *num);
void print_string(va_list types, int *num);
void print_percent(int *num);
void print_int(va_list types, int *num);
int _strlenc(const char *str);
int _strlen(char *str);

#endif
