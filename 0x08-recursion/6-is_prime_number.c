#include "main.h"

int actual_prime(int c, int i);

/**
 * is_prime_number - says if an integer is a prime number or not
 * @c: number to evaluate
 *
 * Return: 1 if c is a prime number, 0 if not
 */
int is_prime_number(int c)
{
	if (c <= 1)
		return (0);
	return (actual_prime(c, c - 1));
}

/**
 * actual_prime - calculates if a number is prime recursively
 * @c: number to evaluate
 * @j: iterator
 *
 * Return: 1 if c is prime, 0 if not
 */
int actual_prime(int c, int j)
{
	if (j == 1)
		return (1);
	if (c % j == 0 && j > 0)
		return (0);
	return (actual_prime(c, j - 1));
}
