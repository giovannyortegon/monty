#include "monty.h"

/**
 * push - entry list
 * @head: list
 * @line_number: value
 */

void push(stack_t **head, unsigned int line_number)
{
	stack_t *new;

	(void) line_number;
	new = (stack_t *) malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	new->n = number_t.number;

	if ((*head) == NULL)
	{
		new->prev = new->next = NULL;
		(*head) = new;
	}
	else
	{
		new->next = (*head);
		new->prev = NULL;
		(*head) = new;
	}
}
