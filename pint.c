#include "monty.h"

/**
 * pint - entry list and print top of the list
 * @head: list current
 */
void pint(stack_t **head, int line_number)
{
	stack_t *curr = (*head);
	(void) line_number;

	printf("%d\n", head->n);
}
