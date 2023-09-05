#include "monty.h"
/**
 * _swap - print te top of the stack
 *
 * @head: top of the stack
 * @line_number: line number
 */
void _swap(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	temp = *head;
	if (*head == NULL || temp->prev == NULL)
	{
		fprintf(stderr, "L%i: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = temp->prev;
		if (temp->prev != NULL)
		{
			(temp->next)->prev = temp->prev;
			(temp->prev)->next = temp->next;
			temp->prev = temp->next;
		}
		else
		{
			(temp->next)->prev = NULL;
			temp->prev = temp->next;
		}
		(temp->next)->next = temp;
		temp->next = NULL;
		*head = temp;
	}
}
/**
 * _add - adds the two top nodes of the stack
 *
 * @head: top of the stack
 * @line_number: line number
 */
void _add(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	int sum = 0;

	temp = *head;
	if (*head == NULL || temp->prev == NULL)
	{
		fprintf(stderr, "L%i: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		sum += temp->n;
		temp = temp->prev;
		sum += temp->n;
		temp->n = sum;
		*head = temp;
		free(temp->next);
		temp->next = NULL;
	}

}
/**
 * _nop - does nothing
 *
 * @head: top of the stack
 * @line_number: line number
 */
void _nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}
