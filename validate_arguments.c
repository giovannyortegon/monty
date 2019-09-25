#include "monty.h"
/**
 * valid_arguments - function to validate arguments passed
 * @arguments: doble pointer holding the arguments
 * @line_number: line number
 * Return: Adrress of an array holding the valid arguments
*/
char **valid_arguments(char **arguments, int line_number)
{
	int len = 0;
	int i = 0;
	char *valid_arguments[] = {"push", "pop", "pall", NULL};

	while (arguments[i] != NULL)
	{
		len++;
	}

	if (len <= 1)
	{
		perror("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	while (valid_arguments[i] != NULL)
	{
		if (arguments[0] == valid_arguments[i])
		return (arguments);

		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s",
	 line_number, arguments[0]);
	exit(EXIT_FAILURE);
}
