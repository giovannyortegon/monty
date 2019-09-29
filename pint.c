#include "monty.h"

/**
 * pint - entry list and print top of the list
 * @head: list current
 * @line_number: value
 */
void pint(stack_t **head, unsigned int line_number)
{
	free_t struct_t;
	stack_t *curr = (*head);
	(void) line_number;

	if (curr == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_close(struct_t, *head);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", curr->n);
}
