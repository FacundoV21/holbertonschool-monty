#include "monty.h"

void _push(stack_t **head, unsigned int line_number)
{
	stack_t *new_element, *temp;
	int n;

	if (g.arr[1] == NULL)
	{
		fprintf(stderr, "L%i: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(g.arr[1]);
	if (isdigit(g.arr[1]) == 0)
	{
		fprintf(stderr, "L%i: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_element = malloc(sizeof(stack_t));
	if (new_element == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	new_element->n = n;
	new_element->next = NULL;
	if (*head == NULL)
	{
		*head = new_element;
		new_element->prev = NULL;
	}
	else
	{
		temp = *head;
		temp->next = new_element;
		*head = new_element;
		new_element->prev = temp;
	}
}

void _pall(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *head;
	while (temp != NULL)
	{
		printf("%i\n", temp->n);
		temp = temp->prev;
	}
}

void _notfound(stack_t **stack, unsigned int line_number)
{

	(void)stack;
	fprintf(stderr, "L%i: unknown instruction %s\n", line_number, g.arr[0]);
	exit(EXIT_FAILURE);
}

void _pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%i\n", g.head->n);
}
