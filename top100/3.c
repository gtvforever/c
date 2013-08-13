#include <stdio.h>
#include <stdlib.h>

int find_max_sum(int* data, unsigned int len)
{
	int last_sum = 0;
	int current_sum = 0;
	unsigned int i;

	for(i = 0; i < len; i++)
	{
		current_sum += data[i];
		if(current_sum < 0)
			current_sum = 0;

		if(current_sum > last_sum)
			last_sum = current_sum;
	}
	
	if(last_sum <= 0)
	{
		last_sum = data[0];

		for(i = 1; i <len; i++)
		{
			if(data[i] > last_sum)
				last_sum = data[i];
		}
	}
	return last_sum;
}


int main()
{
	/* int data[8] ={1,-2,3,10,-4,7,2,-5}; */
	int data[8] ={-1,-2,-3,-10,-4,-7,-2,-5};

	int sum;
	
	sum = find_max_sum(data, 8);

	printf("sum is %d\n", sum);
}
