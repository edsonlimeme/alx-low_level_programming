#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: unsigned long int to convert
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1;
	int bits = sizeof(unsigned long int) * 8;
	int i;

	mask <<= bits - 1;

	for (i = 0; i < bits; i++)
	{
		if ((n & mask) == 0)
			_putchar('0');
		else
			_putchar('1');

		mask >>= 1;
	}
}
