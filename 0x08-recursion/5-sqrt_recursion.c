#include "main.h"

int actual_sqrt_recursion(int z, int b);

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @z: number to calculate the square root of
 *
 * Return: the resulting square root
 */
int _sqrt_recursion(int z)
{
	if (z < 0)
		return (-1);
	return (actual_sqrt_recursion(z, 0));
}

/**
 * actual_sqrt_recursion - recurses to find the natural
 * square root of a number
 * @z: number to calculate the sqaure root of
 * @b: iterator
 *
 * Return: the resulting square root
 */
int actual_sqrt_recursion(int n, int b)
{
	if (b * b > z)
		return (-1);
	if (b * b == z)
		return (b);
	return (actual_sqrt_recursion(z, b + 1));
}
