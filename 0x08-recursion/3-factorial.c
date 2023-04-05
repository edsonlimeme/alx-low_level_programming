#include "main.h"

/**
 * factorial - returns the factorial of a number
 * @e: number to return the factorial from
 *
 * Return: factorial of e
 */
int factorial(int e)
{
	if (e < 0)
		return (-1);
	if (e == 0)
		return (1);
	return (e * factorial(e - 1));
}
