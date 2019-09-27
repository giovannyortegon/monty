#include "monty.h"

/**
 *
 *
*/

void free_close(free_t struct_t, stack_t **head)
{
	int i = 0;
	free_dlistint(head);
	free(struct_t.line);
	struct_t.line = NULL;
	
	while (struct_t.arguments[i] != NULL)
	{
		free(struct_t.arguments[i]);
		i++;
	}

	free(struct_t.arguments);
	fclose(struct_t.fd);
}	
