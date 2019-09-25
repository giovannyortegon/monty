#include "monty.h"
/**
 * tokenize_line - Function to tokenize a line
 * @line: pointer holding line characters
 * Return: address to an array of pointers holding argumentswq
*/
char **tokenize_line(char *line)
{
	int i = 0, line_size = 32;
	char **arguments, *tok = NULL;

	arguments = malloc(command_size * sizeof(char *));
	if (arguments == NULL)
	{
		perror("Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	tok = strtok(line, "  \/");

	while (tok != NULL)
	{
		arguments[i] = tok;
		tok = strtok(NULL, " ");
		i++;

		if (i >= line_size)
		{
			line_size += 32;
			arguments = _realloc(arguments, 32, line_size * sizeof(char *));
			if (arguments == NULL)
			{
				perror("Error: malloc failed");
				exit(EXIT_FAILURE);
			}
		}
	}

	arguments[i] = NULL;

return (arguments);
}
