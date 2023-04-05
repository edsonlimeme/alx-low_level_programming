#include "main.h"
/**
 * _print_rev_recursion - Prints a string in reverse.
 * @f: The string to be printed.
 */
void _print_rev_recursion(char *f)
{
	if (*f)
	{
		_print_rev_recursion(f + 1);
		_putchar(*f);
	}
}
