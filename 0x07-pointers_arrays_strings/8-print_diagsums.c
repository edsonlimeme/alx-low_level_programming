#include "main.h"
#include <stdio.h>
/**
 * print_diagsums - Entry point
 * @a: input
 * @size: input
 * Return: Always 0 (Success)
 */
void print_diagsums(int *a, int size)
{
	int sum5, sum8, q;

	sum5 = 0;
	sum8 = 0;

	for (q = 0; q < size; q++)
	{
		sum5 = sum5 + a[q * size + q];
	}

	for (q = size - 1; q >= 0; q--)
	{
		sum8 += a[q * size + (size - q - 1)];
	}

	printf("%d, %d\n", sum5, sum8);
}
