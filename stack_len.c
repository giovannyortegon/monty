#include "monty.h"

/**
 * stack_len - function to get the len of the stack
 * @head: pointer holding head of the list
 * Return: len of the list
*/

int stack_len(stack_t *head)
{
	int len = 0;
	stack_t *temp = head;

	while (temp->next != NULL)
	{
		len++;
		temp = temp->next;
	}
	len++;

return (len);
}
