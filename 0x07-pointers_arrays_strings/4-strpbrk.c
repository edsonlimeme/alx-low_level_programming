#include "main.h"
/**
 * _strpbrk - Entry point
 * @s: input
 * @accept: input
 * Return: Always 0 (Success)
 */
char *_strpbrk(char *u, char *accept)
{
		int j;

		while (*u)
		{
			for (j = 0; accept[j]; j++)
			{
			if (*u == accept[j])
			return (u);
			}
		u++;
		}

	return ('\0');
}
