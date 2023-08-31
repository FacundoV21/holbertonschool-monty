#include "monty.h"

void check_args(int arguments)
{
	if (arguments != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}
void check_open(char **argumento)
{
	if (g.fd_open == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argumento[1]);
		exit(EXIT_FAILURE);
	}
}
int check_tokens(char *line, const char *limits, char *token, char *linecpy)
{
	int tokenamount = 0;
	token = strtok(line, limits);
	while (token != NULL)
	{
		tokenamount++;
		token = strtok(NULL, limits);
	}

	if (tokenamount == 0)
	{
		free(linecpy);
		return (-1);
	}
	return(tokenamount);
}
void check_arr(char **resultstr, char *linecpy)
{
	if (resultstr == NULL)
	{
		free(linecpy);
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
}