#include "monty.h"

/**
 * check_args - checks for the correct amount of arguments
 *
 * @arguments: arguments to check
 */
void check_args(int arguments)
{
	if (arguments != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * check_open - checks if the fopen function worked
 *
 * @argumento: argument to check
 */
void check_open(char **argumento)
{
	if (g.fd_open == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argumento[1]);
		exit(EXIT_FAILURE);
	}
}
/**
 * check_tokens - checks the token amount
 *
 * @line: line to check
 * @limits: limits to use in the strtok
 * @token: token
 * @linecpy: copy of the line
 * Return: int
 */
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
	return (tokenamount);
}

/**
 * check_arr - checks if an array was created correctly
 *
 * @resultstr: the array to check
 * @linecpy: copy of the line created previously to free it
 */
void check_arr(char **resultstr, char *linecpy)
{
	if (resultstr == NULL)
	{
		free(linecpy);
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
}
