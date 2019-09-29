#include "monty.h"
/**
 * tokenize - function to splite the line indexed
 * by the user into tokens that will be the commands to read
 * @line: Pointer that will hold the line indexed by user
 * @head: double pointer holding top of stack d_linked
 * Return: Pointer to an array of pointers that will hold
 * each command
*/
char **tokenize(char *line, stack_t *head)
{
	int i = 0, commands_size = 32;
	char **commands, *tok = NULL;
	free_t struct_t;

	commands = malloc(commands_size * sizeof(char *));
	if (commands == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		free_close(struct_t, head);
		exit(EXIT_FAILURE);
	}
	tok = strtok(line, " /\n");
	while (tok != NULL)
	{
		commands[i] = tok;

		if (i == 1)
		{
			i++;
			break;
		}

		tok = strtok(NULL, " /\n");
		i++;

		if (i >= commands_size)
		{
			commands_size += 1024;
			commands = _realloc(commands, commands_size,
								commands_size * sizeof(char *));
			if (commands == NULL)
			{
				fprintf(stderr, "Error: malloc failed");
				free_close(struct_t, head);
				exit(EXIT_FAILURE);
			}
		}
	}
	commands[i] = NULL;
return (commands);
}
