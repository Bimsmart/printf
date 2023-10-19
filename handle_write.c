#include "main.h"

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
