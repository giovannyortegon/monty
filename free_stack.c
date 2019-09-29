#include "monty.h"

/**
 * free_dlistint - function to free a double linked list
 * @head: Pointer head of the list
 * Return: nothing
*/

void free_dlistint(stack_t *head)
{
	stack_t *temp = NULL;

	while (head != NULL)
	{
		temp = head;

		while (temp->next != NULL) /*me voy siempre hasta el ultimo nodo*/
		temp = temp->next;

		if (temp->prev == NULL) /*cuando la lista tiene solo 1 nodo*/
		{
			head = NULL;
			free(temp);
		}

		else
		{
			(temp->prev)->next = NULL;
			temp->prev = NULL;
			free(temp);
		}
	}
}
