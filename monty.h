#ifndef MONTY
#define MONTY

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

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

/**
 * struct global_s - struct of useful stuff
 * @arr: the argments of the input
 * @head: top of the stack
 * @fd_open: file descriptor for fopen
 *
 * Description: global struct
 * for stack, queues, LIFO, FIFO
 */
typedef struct global_s
{
	char **arr;
	stack_t *head;
	FILE *fd_open;
} global_t;

extern global_t g;

void _pall(stack_t **head, unsigned int line_number);
void _push(stack_t **stack, unsigned int line_number);
void (*get_code(char *code))(stack_t **stack, unsigned int line_number);
char **separate(char *line);
void free_arr(char **strs);
void _notfound(stack_t **stack, unsigned int line_number);
void free_stack(void);
void _pint(stack_t **head, unsigned int line_number);
void check_args(int arguments);
void check_open(char **argumento);
int check_tokens(char *line, const char *limits, char *token, char *linecpy);
void check_arr(char **resultstr, char *linecpy);
void _pop(stack_t **head, unsigned int line_number);
void _swap(stack_t **head, unsigned int line_number);
void _add(stack_t **head, unsigned int line_number);
void _nop(stack_t **head, unsigned int line_number);

#endif
