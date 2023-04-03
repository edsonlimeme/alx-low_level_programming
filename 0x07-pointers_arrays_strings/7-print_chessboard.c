#include "main.h"
/**
 * print_chessboard - Entry point
 * @a: array
 * Return: Always 0 (Success)
 */
void print_chessboard(char (*a)[8])
{
	int y;
	int h;

	for (y = 0; y < 8; y++)
	{
		for (h = 0; h < 8; h++)
			_putchar(a[y][h]);
		_putchar('\n');
	}
}
