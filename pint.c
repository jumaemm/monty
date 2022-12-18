#include "monty.h"

/**
 * _pint - print value at top of stack
 * @stack: pointer to stack
 * @line_count: count of the lines
 * Return: Always 0
 */
void _pint(stack_t **stack, unsigned int line_count)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_count);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
