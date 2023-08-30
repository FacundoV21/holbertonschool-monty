#include "monty.h"

global_t g;
/**
 * main - 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char *argv[])
{
	FILE *fd_open;
	char *line = NULL;
	ssize_t fd_read = 0;
	size_t in_size = 0;
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
		fd_read = getline(&line, &in_size, fd_open);
		if (fd_read == -1)
			break;
		g.arr = separate(line);
		get_code(g.arr[0])(&g.head, line_number);
		line_number++;
		free_arr(g.arr);
	}
	free(line);
	fclose(fd_open);
	free_stack();
}
