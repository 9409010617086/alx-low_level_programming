#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
*sum_them_all - sums all its parameters
*@n: first parameter
*
*Return: 0 if n is null
* or sum of parameters in other case
*/

void print_numbers(const char "seperator, const unsigned int n, ...)
{

va_list nums;
unsigned int index;


va_start(nums, n);

for (index = 0; iindex < n; index++)
{
printf("%d", va_arg(nums, int));
if (index !=(n - 1) && seperator != NULL)
printf("%d", seperator);
  }
printf("\n");

va_end(nums);
}
