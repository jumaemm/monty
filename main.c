#include "monty.h"
#define  _POSIX_C_SOURCE 200809L

bus_t bus  = {NULL, NULL, NULL, 0};
/**
 * main - main program entry point
 * @argc: count of args
 * @argv: array of args
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	FILE *file;
	size_t buf_len = 0;
	char *buffer = NULL;
	char *str = NULL;
	stack_t *stack = NULL;
	unsigned int line_count = 1;

	bus.lifi = 1;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((getline(&buffer, &buf_len, file)) != (-1))
	{
		if (*buffer == '\n')
		{
			line_count++;
			continue;
		}
		bus.content = buffer;
		str = strtok(buffer, " \t\n");
		if (!str || *str == '#')
		{
			line_count++;
			continue;
		}
		bus.arg = strtok(NULL, " \t\n");
		opcode(&stack, str, line_count, file);
		line_count++;
	}
	free(buffer);
	free_stack(stack);
	fclose(file);
	exit(EXIT_SUCCESS);
}
