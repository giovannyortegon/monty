#include "monty.h"

/**
 *
 *
*/

void free_close(free_t struct_t, stack_t **head)
{
	free(struct_t.arguments);
	free_dlistint(head);
	free(struct_t.line);
	struct_t.line = NULL;
	fclose(struct_t.fd);
}	
