#include "monty.h"

/**
 *
 *
*/

int main(int argc, char *argv[])
{
	FILE *fd;
	int ext;

	ext = extend(argv[1]);
		
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	if (fd == NULL || ext != 0)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	interpretation(fd);

return (0);
}

/**
 *
 *
*/

void interpretation(FILE *fd)
{
	int line_number = 0, j = 0;
	size_t line_size = 0;
        char *line, **arguments, **valid_args;
        ssize_t line_n;

	line_n = getline(&line, &line_size ,fd);

	while (line_n >= 0)
        {
		line_number++;

		arguments = tokenize(line);

		valid_args = valid_arguments(arguments, line_number);

		while (valid_args[j] != NULL)
                {
                        printf("%s ", valid_args[j]);
                        j++;
                }
                        printf("\n");
		
                line_n = getline(&line, &line_size ,fd);
		j = 0;
        }
		free(line);
		line = NULL;
fclose(fd);
}
