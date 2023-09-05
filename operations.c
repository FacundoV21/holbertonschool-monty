#include "monty.h"
/**
 * _push - adds a node to the stack
 *
 * @head: top of the stack
 * @line_number: line number
 */
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
	if (isdigit(n) != 0)
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
/**
 * _pall - print all the stack
 *
 * @head: top of the stack
 * @line_number: line number
 */
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
/**
 * _notfound - exits when a function not found
 *
 * @stack: top of the stack
 * @line_number: line number
 */
void _notfound(stack_t **stack, unsigned int line_number)
{

	(void)stack;
	fprintf(stderr, "L%i: unknown instruction %s\n", line_number, g.arr[0]);
	exit(EXIT_FAILURE);
}
/**
 * _pint - print te top of the stack
 *
 * @head: top of the stack
 * @line_number: line number
 */
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
/**
 * _pop - pops a node from a stack
 *
 * @head: head of the stack
 * @line_number: line number
 */
void _pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%i: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = *head;
		*head = temp->prev;
		free(temp);
		temp = *head;
		temp->next = NULL;
	}

}
