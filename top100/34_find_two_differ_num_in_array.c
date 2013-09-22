#include <stdio.h>
#include <stdlib.h>

typedef enum 
{
	false,
	true,
}bool;



bool is_bit_set(unsigned int num, unsigned int i)
{
	num = num>>i;

	return num&1;
}


bool find_two_differ_num(unsigned int* data, unsigned int len, unsigned int* out_1, unsigned int* out_2)
{
	unsigned int i,j,k;
	unsigned int xor_value = 0;
	unsigned int first_1_bit_pos = 0;

	if(data == NULL || len < 3 || out_1 == NULL || out_2 == NULL)
		return false;

	for(i = 0; i < len; ++i)
	{
		xor_value ^= data[i];
	}

	while(xor_value != 0)
	{
		xor_value = xor_value>>1;
		first_1_bit_pos++;
	}

	j = 0;
	k = 0;

	for(i = 0; i < len; i++)
	{
		if(is_bit_set(data[i], first_1_bit_pos - 1))
		{
			j ^= data[i];
		}
		else
		{

			k ^= data[i];
		}

	}

	*out_1 = j;
	*out_2 = k;
	return true;
}


int main()
{
	unsigned int data[10] = {1,1,3,1,1,1,1,4,1,1};
	unsigned int out_1 = 0;
	unsigned int out_2 = 0;

	if(find_two_differ_num(data, sizeof(data)/sizeof(data[0]), &out_1, &out_2))
		printf("out_1 %d out_2 %d\n", out_1, out_2);
}