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
void free_arr(char **strs)
{
	int i = 0;

	for (i = 0; strs[i] != NULL; i++)
		free(strs[i]);
	if (strs != NULL)
		free(strs);
}

char **separate(char *line)
{
	const char *limits = " \n\t";
	char **resultstr;
	char *token = NULL, *linecpy;
	int tokenamount = 0, i;

	if (line[0] == '\0')
		return(NULL);
	linecpy = strdup(line);

	tokenamount = check_tokens(line, limits, token, linecpy);
	if (tokenamount == -1)
		return(NULL);

	resultstr = malloc(sizeof(char *) * tokenamount + 1);
	check_arr(resultstr, linecpy);

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
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
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
