#include "monty.h"

/**
 * _pall - print an entire stack
 * @stack: stack arg
 * @line_count: count of lines
 * Return: Always 0
 */
void _pall(stack_t **stack, unsigned int line_count)
{
	stack_t *temp;
	(void)line_count;

	temp = *stack;
	if (temp == NULL)
	{
		return;
	}
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}

}
