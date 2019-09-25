#include "monty.h"
/**
 * pall - entry list
 * @head: list to print
 */
void pall(stack_t *head)
{
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
