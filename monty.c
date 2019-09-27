#include "monty.h"

/**
 *
 *
*/

int main(int argc, char *argv[])
{
	/*FILE *fd;*/
	int ext;

	ext = extend(argv[1]);
		
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/*fd = fopen(argv[1], "r");*/
	struct_t.fd = fopen(argv[1], "r");
	/*if (fd == NULL || ext != 0)*/
	if (struct_t.fd == NULL || ext != 0)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/*interpretation(fd);*/
	interpretation(struct_t.fd);

return (0);
}

/**
 *
 *
*/

void interpretation(FILE *fd)
{
	int line_number = 0, i;
	size_t line_size = 0;
	/*char *line, **arguments;*/
	char **valid_args;
	ssize_t line_n;
	stack_t *head = NULL;

	/*line_n = getline(&line, &line_size ,fd);*/
	line_n = getline(&struct_t.line, &line_size , fd);

	while (line_n >= 0)
	{
		line_number++;
		
		/*arguments = tokenize(line);*/
		struct_t.arguments = tokenize(struct_t.line);

		/*valid_args = valid_arguments(arguments, line_number);*/
		valid_args = valid_arguments(struct_t.arguments, line_number);

		if (valid_args[1] != NULL)
		number_t.number = atoi(valid_args[1]);

		else
		number_t.number = 0;

		_exec(valid_args[0], &head, line_number);

		for (i = 0; struct_t.arguments[i] != NULL; i++)
		free(struct_t.arguments[i]);

		/*free(arguments);*/
		free(struct_t.arguments);

		/*line_n = getline(&line, &line_size ,fd);*/
		line_n = getline(&struct_t.line, &line_size , fd);
	}
	free_dlistint(&head);
	/*free(line);*/
	free(struct_t.line);
	/*line = NULL;*/
	struct_t.line = NULL;
	/*fclose(fd);*/
	fclose(fd);
}
