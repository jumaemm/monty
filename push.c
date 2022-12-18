#include "monty.h"
/**
 * _push - pushes an item onto the stack
 * @stack: stack given as arg
 * @line_count: lines
 * Return: Always 0
 */
void _push(stack_t **stack, unsigned int line_count)
{
	char *n = bus.arg;

	if ((is_digit(n)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_count);
		exit(EXIT_FAILURE);
	}

	if (bus.lifi == 1)
	{
		if (!add_node(stack, atoi(n)))
		{
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (!queue_node(stack, atoi(n)))
		{
			exit(EXIT_FAILURE);
		}
	}
}
