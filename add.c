#include "monty.h"

/**
 * _add - add top two nodes in a stack
 * @stack: pointer to stack head
 * @line_count: count of lines
 * Return: Always 0
 */
void _add(stack_t **stack, unsigned int line_count)
{
	stack_t *current_node = *stack;
	int len = 0, sum;

	while (current_node)
	{
		current_node = current_node->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_count);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	current_node = *stack;
	sum = current_node->n + current_node->next->n;
	current_node->next->n = sum;
	*stack = current_node->next;
	free(current_node);
}
