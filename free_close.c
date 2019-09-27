#include "monty.h"

/**
 * free_close - entry point
 * @struct_t: entry list
 * @head: entry list
*/
void free_close(free_t struct_t, stack_t **head)
{
	free(struct_t.arguments);
	free_dlistint(head);
	free(struct_t.line);
	struct_t.line = NULL;
	fclose(struct_t.fd);
}
