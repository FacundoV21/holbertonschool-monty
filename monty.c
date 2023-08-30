#include "monty.h"

stack_t *head = NULL;
char **arr = NULL;

int main(int argc, char *argv[])
{
	FILE *fd_open;
	char *line;
	ssize_t fd_read;
	size_t in_size;
	unsigned int line_number = 1;
	int i = 0;

	if (argc < 2)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}

	fd_open = fopen(argv[1], "r");

	if (fd_open == NULL)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		printf("inicio/reinicio\n");
		fd_read = getline(&line, &in_size, fd_open);
		if (fd_read == -1)
			break;
		printf("despues de getline\n");
		arr = separate(line);
		printf("despues de token\n");
		get_code(arr[0])(&head, line_number);
		printf("despues de func\n");
		printf("antes de imprimir\n");

		for (i = 0; arr[i] != NULL; i++)
			printf("%s\n", arr[i]);

		printf("despues de imprimir\n");

		line_number++;
		printf("antes de liberar\n");
		free_arr(arr);
		printf("despues de liberar\n");
	}
	free(line);
	fclose(fd_open);
	
}
