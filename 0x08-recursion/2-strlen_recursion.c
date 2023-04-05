#include "main.h"
/**
 * _strlen_recursion - Returns the length of a string.
 * @l: The string to be measured.
 *
 * Return: The length of the string.
 */
int _strlen_recursion(char *l)
{
	int longit = 0;

	if (*l)
	{
		longit++;
		longit += _strlen_recursion(l + 1);
	}

	return (longit);
}
