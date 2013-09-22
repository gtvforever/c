#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned int get_1_number_of_integer(int n)
{
	unsigned int i = 0;
	{
		while(n != 0)
		{
			n = n&(n - 1);
			i++;
		}
	}
	return i;
}


int main()
{
	int n = -1;

	printf("%x have %d bit 1\n", n, get_1_number_of_integer(n));
}