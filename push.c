#include "monty.h"

/**
 * push - entry list
 * @head: list
 * @line_number: value
 */

void push(stack_t **head, unsigned int line_number)
{
	/*stack_t *new;*/

	(void) line_number;
	/*new = (stack_t *) malloc(sizeof(stack_t));*/
	struct_t.new = (stack_t *) malloc(sizeof(stack_t));

	/*if (new == NULL)*/
	if (struct_t.new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		free_close(struct_t, head); 
		exit(EXIT_FAILURE);
	}

	/*new->n = number_t.number;*/
	struct_t.new->n = number_t.number;

	if ((*head) == NULL)
	{
		/*new->prev = new->next = NULL;*/
		struct_t.new->prev = struct_t.new->next = NULL;
		/*(*head) = new;*/
		(*head) = struct_t.new;
	}
	else
	{
		/*new->next = (*head);*/
		struct_t.new->next = (*head);
		/*new->prev = NULL;*/
		struct_t.new->prev = NULL;
		/*(*head) = new;*/
		(*head) = struct_t.new;
	}
}
