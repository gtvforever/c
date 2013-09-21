#include <stdio.h>
#include <stdlib.h>
#include <string.h>


unsigned long fibonacci(unsigned int i)
{
	if(i < 2)
		return i;

	return fibonacci(i - 1) + fibonacci(i - 2);
}

unsigned long fibonacci_2(unsigned int n)
{
	unsigned long fib_cur = 0;
	unsigned long fib_next = 1;
	unsigned long fib_sum = 0;
	unsigned int i;
	if(n < 2)
		return n;

	for(i = 2; i <= n; i++)
	{
		fib_sum = fib_cur + fib_next;

		fib_cur = fib_next;
		fib_next = fib_sum;
	}
	return fib_sum;
}


int main()
{
	unsigned int a = 100;

	// printf("%lu\n", fibonacci(a));
	printf("%lu\n", fibonacci_2(a));
}