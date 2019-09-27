#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @head: pointer holding head pointer
*/

void swap(stack_t **head, unsigned int line_number)
{
	int stacklen;
	stack_t *temp1;
	stack_t *temp2 = *head; 	

	if (stack_len(*head) < 2)
	{
		fprintf(stderr, "L%d: Can´t swap, stack too shoort\n", line_number);
		exit(EXIT_FAILURE);
	}
	
	stacklen = stack_len(*head);

	if (stacklen == 2)
	{
		(*head)->next->next = *head;
		(*head)->prev = (*head)->next;
		(*head)->next->prev = NULL;
		*head = (*head)->next;
		temp2->next = NULL;	
	}	

	else
	{
		temp1 = (*head)->next;
        	while (temp2->next != NULL)
        	temp2 = temp2->next;
		(*head)->next->next->prev = *head;
		(*head)->next->next = *head;
		(*head)->next = temp2;
		(*head)->prev = NULL;
		*head = temp1;
	}
}		
