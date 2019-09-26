#include "monty.h"

/**
 * push - entry list
 * @head: list
 * @num: value
 * Return: list modified
 */
void push(stack_t **head, int line_number)
{
	stack_t *new;

	int number = 0;

	(void) line_number;
	new = (stack_t *) malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new->n = number;

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
