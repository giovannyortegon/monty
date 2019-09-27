#include "monty.h"

/**
 * push - entry list
 * @head: list
 * @line_number: value
 */

void push(stack_t **head, unsigned int line_number)
{
	(void) line_number;
	struct_t.new = (stack_t *) malloc(sizeof(stack_t));

	if (struct_t.new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		free_close(struct_t, head);
		exit(EXIT_FAILURE);
	}

	struct_t.new->n = number_t.number;

	if ((*head) == NULL)
	{
		struct_t.new->prev = struct_t.new->next = NULL;
		(*head) = struct_t.new;
	}
	else
	{
		struct_t.new->next = (*head);
		struct_t.new->prev = NULL;
		(*head) = struct_t.new;
	}
}
