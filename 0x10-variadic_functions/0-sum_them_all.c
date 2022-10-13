#include "variadic_functions.h"
#include <stdarg.h>
/**
* sum_them_all - function
* @n: number of arguments
* @...: unknown arguments
*
* Description: function to return a sum of all of its parameters
* Return: sum integer
*/
int sum_them_all(const unsigned int n, ...)
{
	va_list args;
	unsigned int i, sum = 0;

	va_start(args, n);
	if (n == 0)
		return (0);

	for (i = 0; i < n; i++)
	{
		sum += va_arg(args, const unsigned int);
	}
	va_end(args);

	return (sum);
}
