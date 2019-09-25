#include "monty.h"

int main(int argc, char *argv[])
{
	FILE *fd;
	int num_l = 0;
	size_t line_size = 0;
	char *line;
	ssize_t line_n;
	int ext;

	ext = extend(argv[1]);
		
	if (argc != 2)
	{
		write(STDERR_FILENO, "USAGE: monty file\n",19);
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "rb");
	if (fd == NULL || ext != 0)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (line_n != -1)
	{
		line_n = getline(&line, &line_size ,fd);
		if (line_n < 0)
		{
			fprintf(stderr,"Error %d", num_l);
			exit(EXIT_FAILURE);
		}
		fprintf(stdout,"%d %s" , num_l + 1, line);
		num_l++;
	}

	printf("\n%d\n", num_l);
	fclose(fd);
}
