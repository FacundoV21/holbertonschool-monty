#include "monty.h"

void free_stack(void)
{
	stack_t *temp = g.head;
	while (g.head != NULL)
	{
		temp = g.head;
		g.head = temp->prev;
		free(temp);
	}
}
void free_arr(char **arr)
{
	int i = 0;

	for (i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);
}

char **separate(char *line)
{
	const char *limits = " \n\t";
	char **resultstr;
	char *token, *linecpy;
	int tokenamount = 0, i;

	linecpy = strdup(line);

	token = strtok(line, limits);
	while (token != NULL)
	{
		tokenamount++;
		token = strtok(NULL, limits);
	}
	tokenamount++;

	if (tokenamount == 0)
	{
		free(linecpy);
		return (NULL);
	}

	resultstr = malloc(sizeof(char *) * tokenamount);
	if (resultstr == NULL)
	{
		free(linecpy);
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	token = strtok(linecpy, limits);
	for (i = 0; token ; i++)
	{
		resultstr[i] = malloc(sizeof(char) * (strlen(token) + 1));
		if (resultstr[i] == NULL)
		{
			free(linecpy);
			free_arr(resultstr);
			fprintf(stderr, "Error: malloc failed");
			exit(EXIT_FAILURE);
		}
		strcpy(resultstr[i], token);
		token = strtok(NULL, limits);
	}

	resultstr[i] = NULL;
	free(linecpy);
	return (resultstr);
}

void (*get_code(char *code))(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t opt[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"else", _notfound}
	};

	while (strcmp(opt[i].opcode, code) != 0 &&
			strcmp(opt[i].opcode, "else") != 0)
		i++;
	if (opt[i].opcode != NULL)
		return (opt[i].f);

	fprintf(stderr, "USAGE: unknown command");
	exit(EXIT_FAILURE);
}
