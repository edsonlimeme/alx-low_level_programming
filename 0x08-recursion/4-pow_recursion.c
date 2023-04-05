#include "main.h"

/**
 * _pow_recursion - returns the value of a raised to the power of p
 * @a: value to raise
 * @p: power
 *
 * Return: result of the power
 */
int _pow_recursion(int a, int p)
{
	if (p < 0)
		return (-1);
	if (p == 0)
		return (1);
	return (a * _pow_recursion(a, p - 1));
}
