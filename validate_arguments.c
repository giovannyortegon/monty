#include "monty.h"
/**
 * valid_args - function to validate arguments passed
 * @args: doble pointer holding the arguments
 * @head: double pointer holding the stack
 * @line_number: line number
 * Return: Adrress of an array holding the valid arguments
*/
char **valid_args(char **args, int line_number, stack_t *head)
{
	int len = 0;
	int i = 0, valid_arguments_counter = 0;
	char *valid_arguments[] = {"push", "pop", "add",
					"swap", "pint", "pall", "nop"};
	free_t struct_t;

	while (args[i] != NULL)
	{
		len++;
		i++;
	}

	i = 0;
	valid_arguments_counter = sizeof(valid_arguments) / sizeof(char *);
	while (i < valid_arguments_counter)
	{
		if (_strcmp(args[0], valid_arguments[i]) == 0)
		{
			if ((i == 0) && (len == 1))
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				free_close(struct_t, head);
				exit(EXIT_FAILURE);
			}

			else
			return (args);
		}

			i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s \n", line_number, args[0]);
	free_close(struct_t, head);
	exit(EXIT_FAILURE);
}
