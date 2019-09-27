#include "monty.h"

/**
 * add - entry list
 * @head: list old
 * @line_number: list to reduce
 */
void add(stack_t **head, unsigned int line_number)
{
	(void) line_number;
	if ((*head)->next == NULL)
	{
		fprintf(stderr, "L %d: can't add", line_number);
	}
	else
	{
		(*head)->next->n += (*head)->n;
		pop(head, line_number);
	}
}
