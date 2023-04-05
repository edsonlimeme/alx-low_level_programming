#include "main.h"
/**
 * _puts_recursion - function like puts();
 * @s: input
 * Return: Always 0 (Success)
 */
void _puts_recursion(char *r)
{
	if (*r)
	{
		_putchar(*r);
		_puts_recursion(r + 1);
	}

	else
		_putchar('\n');
}
