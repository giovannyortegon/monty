#include "monty.h"
/**
 * valid_arguments - function to validate arguments passed
 * @arguments: doble pointer holding the arguments
 * @line_number: line number
 * Return: Adrress of an array holding the valid arguments
*/
char **valid_arguments(char **arguments, int line_number)
{
	/*int len = 0;*/
	int i = 0, valid_arguments_counter = 0;
	char *valid_arguments[] = {"push", "pop", "pall"};

	/*while (arguments[i] != NULL)
	len++;

	if (len <= 1)
	{
		perror("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}*/
	valid_arguments_counter = sizeof(valid_arguments) / sizeof(char *); /*Por que toca asi y no se puede poniendole un null al final del arreglo?*/

	while (i < valid_arguments_counter)
	{
		if (strcmp(arguments[0], valid_arguments[i]) == 0)
		return (arguments);
		
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s \n", line_number, arguments[0]);
	exit(EXIT_FAILURE); 
}
