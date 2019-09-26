#include "monty.h"

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
	fd = fopen(argv[1], "rb");
	if (fd == NULL || ext != 0)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	interpretation(fd);

	fclose(fd);
return (0);
}

void interpretation(FILE *fd)
{
	int num_l = 0, i = 0;
	size_t line_size = 0;
        char *line, **arguments;/***valid_args;*/
        ssize_t line_n;

	while (line_n != EOF)
        {
                line_n = getline(&line, &line_size ,fd);
                /*if (line_n < 0)
                {
                        fprintf(stderr,"Error %d", num_l);
                        exit(EXIT_FAILURE);
                }*/
		num_l++;
		arguments = tokenize(line);	

		while (arguments[i] != NULL)
		{
			printf("%s ", arguments[i]);
			i++;
		}
	
		i = 0;

		while(arguments[i] != NULL)
                arguments[i] = NULL;
		arguments = NULL;
        }
}
