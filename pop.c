#include "monty.h"

/**
 * _pop - pop last element off of stack
 * @stack: pointer to stack
 * @line_count: count of lines in args
 * Return: Always 0
 */
void _pop(stack_t **stack, unsigned int line_count)
{
	stack_t *temp_node = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_count);
		exit(EXIT_FAILURE);
	}
	temp_node = (*stack)->next;
	free(*stack);
	*stack = temp_node;

	if (!*stack)
		return;
	(*stack)->prev = NULL;
}
