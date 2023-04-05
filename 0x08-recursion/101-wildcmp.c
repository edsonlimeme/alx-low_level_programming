#include "main.h"

/**
 * wildcmp - Compare strings
 * @s85: pointer to string params
 * @s95: pointer to string params
 * Return: 0
 */

int wildcmp(char *s1, char *s2)
{
	if (*s85 == '\0')
	{
		if (*s95 != '\0' && *s95 == '*')
		{
			return (wildcmp(s85, s95 + 1));
		}
		return (*s95 == '\0');
	}

	if (*s95 == '*')
	{
		return (wildcmp(s85 + 1, s95) || wildcmp(s85, s95 + 1));
	}
	else if (*s85 == *s95)
	{
		return (wildcmp(s85 + 1, s95 + 1));
	}
	return (0);
}
 * @f: number to calculate the sqaure root of
 * @g: iterator
 *
 * Return: the resulting square root
 */
int actual_sqrt_recursion(int n, int b)
{
	if (g * g > f)
		return (-1);
	if (g * g == f)
		return (g);
	return (actual_sqrt_recursion(f, g + 1));
}
