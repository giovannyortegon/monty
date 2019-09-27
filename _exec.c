#include "monty.h"

/**
 * _exec - entry instruction
 * @str: instruction
 * @line_number: number line
 */

void _exec(char *str, stack_t **head, unsigned int line_number)
{
	int i, cmp;

	instruction_t inst[] = {
			{"push", &push},
			{"pall", &pall},
			{"pint", &pint},
			{"swap", &swap},
			{"nop", &nop},
			{NULL, NULL}
		};

	for (i = 0; inst[i].opcode != NULL; i++)
	{
		cmp = _strcmp(str, inst[i].opcode);
		if (cmp == 0)
		{
			inst[i].f(head, line_number);
		}
	}
}
