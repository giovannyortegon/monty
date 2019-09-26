#include "monty.h"
/**
 * split_into_arguments - function to splite the line indexed
 * by the user into tokens that will be the commands to read
 * @line: Pointer that will hold the line indexed by user
 * Return: Pointer to an array of pointers that will hold
 * each command
*/
char **tokenize(char *line)
{
	int i, commands_size = 32;
	char **commands, *tok = NULL;

	commands = malloc(commands_size * sizeof(char *));
	if (commands == NULL)
	{
		perror("hsh: failed to allocate memory\n");
		return (NULL);
	}
	tok = strtok(line, " /\n");
	if (tok == NULL)
	{
		free(commands);
		return (NULL);
	}
	else
	{
		i = 0;
		while (tok != NULL)
		{
			commands[i] = tok;
			tok = strtok(NULL, " /\n");
			i++;

			if (i >= commands_size)
			{
				commands_size += 1024;
				commands = _realloc(commands, commands_size,
										commands_size * sizeof(char *));
				if (commands == NULL)
				{
					perror("hsh: failed to realloc commands\n");
					return (0);
				}
			}
		}
		commands[i] = NULL;
	}
return (commands);
}
