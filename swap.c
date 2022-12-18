#include "monty.h"

/**
 * _swap - swap the top two elements of the stack
 * @stack: pointer t the stack
 * @line_count: count of the line
 * Return: Always 0
 */
void _swap(stack_t **stack, unsigned int line_count)
{
	stack_t *current_node;
	int temp, len = 0;

	current_node = *stack;
	while (current_node)
	{
		current_node = current_node->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_count);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	current_node = *stack;
	temp = current_node->n;
	current_node->n = current_node->next->n;
	current_node->next->n = temp;
}
