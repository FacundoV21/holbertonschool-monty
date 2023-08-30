#ifndef MONTY
#define MONTY

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern char **arr;
extern stack_t *head;

void _pall(stack_t **head, unsigned int line_number);
void _push(stack_t **stack, unsigned int line_number);
void (*get_code(char *code))(stack_t **stack, unsigned int line_number);
char **separate(char *line);
void free_arr(char **arr);
void _notfound(stack_t **stack, unsigned int line_number);

#endif
