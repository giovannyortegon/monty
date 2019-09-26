#include "monty.h"
/**
 * pall - entry list
 * @head: list to print
 * @line_number: line number
 */
void pall(stack_t **head, unsigned int line_number)
{
	(void) line_number;
	stack_t *curr = (*head);

	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}
