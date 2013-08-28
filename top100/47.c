#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int calc_max_repeat_number(int * a, int len)
{
	int pre;
	int i;
	int count = 1;
	
	pre = a[0];
	
	for(i = 1; i < len; i++)
	{
		if(count == 0)
		{
			pre = a[i];
			count = 1;
		}
		else if(a[i] == pre)
		{
			count++;
		}
		else
		{
			count--;
		}
	}

	return pre;
}

int main()
{
	int data[10] = {1,4,3,4,4,6,4,4,5,3};

	int i;

	i = calc_max_repeat_number(data, 10);

	printf("%d\n", i);

	return 0;
}
