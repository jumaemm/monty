#include "monty.h"

/**
 * opcode - execute the instruction from the data structure
 * @stack: pointer to stack
 * @str: string argument
 * @line_count: line counter
 * @file: open file
 * Return: Always 0
 */
void opcode(stack_t **stack, char *str, unsigned int line_count, FILE *file)
{
	int i = 0;

	instruction_t op[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"add", _add},
		{"swap", _swap},
		{"nop", _nop},
		{"rotr", _rotr},
		{"sub", _sub},
		{"mul", _mul},
		{"mod", _mod},
		{"rotl", _rotl},
		{"pstr", _pstr},
		{"pchar", _pchar},
		{"div", _div},
		{NULL, NULL}
	};

	bus.status = 1;

	if (!strcmp(str, "stack"))
	{
		bus.lifi = 1;
		return;
	}
	if (!strcmp(str, "queue"))
	{
		bus.lifi = 0;
		return;
	}
	while (op[i].opcode)
	{
		if (strcmp(op[i].opcode, str) == 0)
		{
			op[i].f(stack, line_count);
			return;
		}
		i++;
	}
	if (op[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_count, str);
		fclose(file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
