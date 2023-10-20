#include "main.h"

/**
 * _strlen - return length
 * @str: string 
 *
 * Return: length
 */
int _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}
/**
 * _strlen - return length of a constant
 * @str: string constant
 *
 * Return: length
 */
int _strlenc(const char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}
