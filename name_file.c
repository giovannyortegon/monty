#include "monty.h"
#include <stdio.h>
#include <string.h>

char *file_name(char *str);

int main(int argc, char **argv)
{
	char *file;

	if (argc != 2)
		fprintf(stderr,"Error.");

	printf("%s\n", argv[0]);	
	printf("%s\n", argv[1]);

	file = file_name(argv[1]);
	return (0);
}
char *file_name(char *str)
{
	char **file, punto = 0;
	int i = 0;

	file = tokenize_line(str);

	while (file[i] != NULL)
	{
		if(file[i + 1] == NULL)
		{
			printf("%s\n", file[i]);
			return(file[i]);
		}
		i++;
	}
}
