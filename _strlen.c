#include "monty.h"
/**
 * _strlen - count length  of a string
 * @s: string to count
 * Return: number of characters
 */
size_t _strlen(const char *s)
{
	size_t i = 0;

	while (s[i])
		i++;
	return (i);
}
