#include "monty.h"

/**
 * main - entry main
 * @argc: number arguments
 * @argv: number arguments
 * Return: Always 0 (Success)
*/

int main(int argc, char *argv[])
{
	int ext;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	ext = extend(argv[1]);

	struct_t.fd = fopen(argv[1], "r");
	if (struct_t.fd == NULL || ext != 0)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	interpretation(struct_t.fd);

	return (0);
}

/**
 * interpretation - entry point
 * @fd: file description
*/
void interpretation(FILE *fd)
{
	int line_number = 0;
	size_t line_size = 0;
	char **valid_arguments;
	ssize_t line_n;
	stack_t *head = NULL;

	line_n = getline(&struct_t.line, &line_size, fd);
	while (line_n >= 0)
	{
		line_number++;
		struct_t.arguments = tokenize(struct_t.line, &head);
		if (struct_t.arguments[0] == NULL)
		{
			free(struct_t.arguments);
			line_n = getline(&struct_t.line, &line_size, fd);
			continue;
		}

		valid_arguments = valid_args(struct_t.arguments, line_number, &head);
		if (valid_arguments[1] != NULL)
		{
			number_t.number = atoi(valid_arguments[1]);
			if ((number_t.number == 0) && (strcmp(valid_arguments[1], "0") != 0))
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				free_close(struct_t, &head);
				exit(EXIT_FAILURE);
			}
		}
		else
		number_t.number = 0;

		_exec(valid_arguments[0], &head, line_number);
		free(struct_t.arguments);
		line_n = getline(&struct_t.line, &line_size, fd);
	}
	free_dlistint(&head);
	free(struct_t.line);
	struct_t.line = NULL;
	fclose(fd);
}
