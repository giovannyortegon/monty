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
	int i = 0, valid_arguments_counter = 0;
	char *valid_arguments[] = {"push", "pop", "add", 
					"swap", "pint", "pall", "nop"};

	while (arguments[i] != NULL)
	{
		len++;
		i++;
	}

	i = 0;

	valid_arguments_counter = sizeof(valid_arguments) / sizeof(char *);

	while (i < valid_arguments_counter)
	{
		if (_strcmp(arguments[0], valid_arguments[i]) == 0)
		{
			if ((i = 0) && (len == 1))
			{
				fprintf(stderr, "L%d: usage: push integer", line_number);
				exit(EXIT_FAILURE);	
			}

			else
			return (arguments);
		}

			i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s \n", line_number, arguments[0]);
	exit(EXIT_FAILURE); 
}
