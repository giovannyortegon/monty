#include "monty.h"

/**
 *
 *
*/

int main(int argc, char *argv[])
{
	int ext;

	ext = extend(argv[1]);
		
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

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
 *
 *
*/

void interpretation(FILE *fd)
{
	int line_number = 0;
	size_t line_size = 0;
	char **valid_args;
	ssize_t line_n;
	stack_t *head = NULL;

	line_n = getline(&struct_t.line, &line_size , fd);

	while (line_n >= 0)
	{
		line_number++;
		
		struct_t.arguments = tokenize(struct_t.line);

		valid_args = valid_arguments(struct_t.arguments, line_number);

		if (valid_args[1] != NULL)
		number_t.number = atoi(valid_args[1]);

		else
		number_t.number = 0;

		_exec(valid_args[0], &head, line_number);

		free(struct_t.arguments);

		line_n = getline(&struct_t.line, &line_size , fd);
	}
	free_dlistint(&head);
	free(struct_t.line);
	struct_t.line = NULL;
	fclose(fd);
}
