#include "monty.h"

/**
 * _pstr - prints the contents of a stack_t stack as a string
 * @stack: pointer to stack
 * @line_count: line counter for error messages
 *
 * Return: nothing
 */
void _pstr(stack_t **stack, unsigned int line_count)
{

	stack_t *current = *stack;

	(void) line_count;
	while (current)
	{
		if (current->n <= 0 || current->n > 127)
			break;
		putchar((char) current->n);
		current = current->next;
	}
	putchar('\n');
}
