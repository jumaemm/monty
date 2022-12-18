#include "monty.h"

/**
 * add_node - add node to top of stack
 * @stack: pointer to stack
 * @n: value of node
 * Return: created node; Null otherwise
 */
stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: memory allocation failed\n");
		free(new_node);
		return (NULL);
	}
	new_node->n = n;
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
	return (new_node);
}
/**
 * print_stack - print all the contents of a stack
 * @stack: pointer to stack head
 * Return: number of elements in the stack
 */
size_t print_stack(const stack_t *stack)
{
	size_t count = 0;

	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
		count++;
	}
	return (count);
}

/**
 * free_stack - free memory allocated to stack
 * @stack: pointer to stack head
 * Return: Always 0
 */
void free_stack(stack_t *stack)
{
	stack_t *current_node = stack;
	stack_t *next_node;

	if (stack)
	{
		next_node = stack->next;
		while (current_node)
		{
			free(current_node);
			current_node = next_node;
			if (next_node)
				next_node = next_node->next;
		}
	}
}
