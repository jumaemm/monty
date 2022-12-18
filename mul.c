#include "monty.h"

/**
 * _mul - multiplies the head by the next
 * @stack: pointer to stack
 * @line_count: line counter
 *
 * Return: void
 */
void _mul(stack_t **stack, unsigned int line_count)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_count);
		exit(EXIT_FAILURE);
		return;
	}

	result = ((*stack)->next->n) * ((*stack)->n);
	_pop(stack, line_count);
	(*stack)->n = result;
}
