#include "monty.h"
/**
 * pop - entry list
 * @head: list to reduce
 */
void pop(stack_t **head)
{
	stack_t *curr;

	curr = *head;

	if ((*head)->next == NULL)
	{
		*head = NULL;
		free(curr);
	}
	else
	{
		*head = curr->next;
		curr->next->prev = NULL;
		curr->next = NULL;
		free(curr);
	}
}
