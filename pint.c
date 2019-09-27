#include "monty.h"

/**
 * pint - entry list and print top of the list
 * @head: list current
 * @line_number: value
 */
void pint(stack_t **head, unsigned int line_number)
{
	stack_t *curr = (*head);
	(void) line_number;

	printf("%d\n", curr->n);
}
