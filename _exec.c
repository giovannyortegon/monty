#include "monty.h"


void _exec(char *str, int line_number)
{
	int i, cmp;
//	char *num = NULL;

	stack_t *head = NULL;

	instruction_t inst[]={
			{"push", NULL},
			{"pall", NULL},
			{NULL, NULL}
		};

	for (i = 0; inst[i].opcode != NULL; i++)
	{
		cmp = _strcmp(str,inst[i].opcode);
		if (cmp == 0)
		{
			inst[i].f(&head, line_number);	
		}	
	}
	return (line_number);
}
