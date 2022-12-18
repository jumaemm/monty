#include "monty.h"


/**
 * _div - divides the head value by the next
 * @stack: pointer to stack
 * @line_count: line counter
 *
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_count)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_count);
		exit(EXIT_FAILURE);
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_count);
		exit(EXIT_FAILURE);
		;
		return;
	}

	result = ((*stack)->next->n) / ((*stack)->n);
	_pop(stack, line_count);
	(*stack)->n = result;
}
