#include "monty.h"
/**
 * _strcmp - recive two strings
 * @s1: string to compare
 * @s2: compare string
 * Return: bigger ASCII
 */
int _strcmp(char *s1, char *s2)
{
	int i, res;

	res = 0;

	for (i = 0; s1[i] != '\0' && res == 0; i++)
	res = s1[i] - s2[i];
	return (res);
}
