#include "monty.h"

/**
 * extend - review of extend of file
 * @str: file name
 * Return: 0 or 1
 */
int extend(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if ((int) str[i] == 46 && (int)str[i + 1] == 109)
			return (0);
	}
	return (-1);
}
