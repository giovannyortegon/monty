#include "monty.h"

/**
 * push - entry list
 * @head: list
 * @line_number: value
 */

void push(stack_t **head, unsigned int line_number)
{
	free_t struct_t;

	(void) line_number;

	struct_t.new = (stack_t *) malloc(sizeof(stack_t));
	if (struct_t.new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		free_close(struct_t, *head);
		exit(EXIT_FAILURE);
	}

	struct_t.new->n = n;

	if ((*head) == NULL)
	{
		struct_t.new->prev = struct_t.new->next = NULL;
		(*head) = struct_t.new;
	}
	else
	{
		struct_t.new->next = (*head);
		struct_t.new->prev = NULL;
		(*head)->prev = struct_t.new; /*esto no estaba*/
		(*head) = struct_t.new;
	}
}
