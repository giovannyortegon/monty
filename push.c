#include "monty.h"

/**
 * push - entry list
 * @head: list
 * @num: value
 * Return: list modified
 */
stack_t *push(stack_t **head,  int num)
{
	stack_t *new;

	new = (stack_t *) malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new->n = num;

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
	return (*head);
}
