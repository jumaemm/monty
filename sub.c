#include "monty.h"

/**
 * _sub -  substracts the first two nodes of the stack
 * @stack: pointer to stack
 * @line_count: line counter
 *
 * Return: void
 */
void _sub(stack_t **stack, unsigned int line_count)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_count);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next->n) - ((*stack)->n);
	_pop(stack, line_count);
	(*stack)->n = result;
}
