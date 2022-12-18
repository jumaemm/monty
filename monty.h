#ifndef _MONTY_H
#define _MONTY_H

#include <stdio.h>
#include <stdlib.h>
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
 * struct bus_s - structure to hold contents of a line in the main file
 * @arg: the arg being passed
 * @file: the file being executed
 * @content: contents of the line
 * @status: the status of the structure i.e. stack or queue
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int status;
	int lifi;
}  bus_t;
extern bus_t bus;
void _pall(stack_t **stack, unsigned int line_count);
void _pint(stack_t **stack, unsigned int line_count);
void _add(stack_t **stack, unsigned int line_count);
void _pop(stack_t **stack, unsigned int line_count);
void _swap(stack_t **stack, unsigned int line_count);
void _nop(stack_t **stack, unsigned int line_count);
void _push(stack_t **stack, unsigned int line_count);
void _div(stack_t **stack, unsigned int line_count);
void _mul(stack_t **stack, unsigned int line_count);
void _sub(stack_t **stack, unsigned int line_count);
void _mod(stack_t **stack, unsigned int line_count);
void _rotl(stack_t **stack, unsigned int line_count);
void _rotr(stack_t **stack, unsigned int line_count);
void _pchar(stack_t **stack, unsigned int line_count);
void _pstr(stack_t **stack, unsigned int line_count);
stack_t *add_node(stack_t **stack, const int n);
stack_t *queue_node(stack_t **stack, const int n);
size_t print_stack(const stack_t *stack);
void free_stack(stack_t *stack);
void opcode(stack_t **stack, char *str, unsigned int line_count, FILE *file);
int is_digit(char *string);
#endif
