#include "monty.h"

global_t g;
/**
 * main - is the main flow of the program, wich calls all aother functions
 * @argc: argument count
 * @argv: argument vector
 * Return: int
 */
int main(int argc, char *argv[])
{
	char *line = NULL;

	g.head = NULL;

	ssize_t fd_read = 0;
	size_t in_size = 0;
	unsigned int line_number = 1;

	check_args(argc);
	g.fd_open = fopen(argv[1], "r");
	check_open(argv);

	while (1)
	{
		fd_read = getline(&line, &in_size, g.fd_open);
		if (fd_read == -1)
			break;
		if (fd_read == 0)
			continue;
		g.arr = separate(line);
		if (g.arr == NULL)
		{
			line_number++;
			continue;
		}
		get_code(g.arr[0])(&g.head, line_number);
		free_arr(g.arr);
		line_number++;
	}
	free(line);
	fclose(g.fd_open);
	free_stack();
}
