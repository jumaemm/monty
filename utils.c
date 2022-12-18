#include "monty.h"

/**
 * is_digit - check if arg is a digit
 * @string: string to check
 * Return: 0 or 1
 */
int is_digit(char *string)
{
	if (string == NULL || *string  == '\0')
		return (0);
	if (*string == '-')
		string++;
	while (*string)
	{
		if (isdigit(*string) == 0)
			return (0);
		string++;
	}
	return (1);
}
/**
 * isnumber - checks if a string is a number
 * @string: provided string
 *
 * Return: 1 otherwise 0
 */
int isnumber(char *string)
{
	int i;

	if (!string)
		return (0);

	for (i = 0; string[i]; i++)
		if (i < '0' || i > '9')
			return (0);

	return (1);
}
