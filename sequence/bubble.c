#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE   (1024*10)


void print_list(unsigned int * data, unsigned int len)
{
	unsigned int i;
	if (data == NULL || len == 0)
		return;

	/* while(len-- > 0) */
	for (i = 0; i < len; i++)
	{
		printf("%d\n", data[i]);
	}

	return;
}

static void bubble_sort_increase_optimize(unsigned int * data, int len)
{
	int i, j;
	unsigned int temp;
	unsigned int flag = 1;

	for(i = 0; i < len - 1 && flag; i++)
	{
		flag = 0;
		for (j = len - 1; j >= i ; j--)
		{
			if (data[j] < data[j - 1])
			{
				temp = data[j - 1];
				data[j - 1] = data[j];
				data[j] = temp;

				flag = 1;
			}
		}
	}

	return;
}

static void bubble_sort_increase(unsigned int* data, int len)
{
	int i, j;
	unsigned int temp;

	for(i = 0; i < len - 1; i++)
	{
		for (j = len - 1; j >= i; j--)
		{
			if (data[j] < data[j - 1])
			{
				temp = data[j - 1];
				data[j - 1] = data[j];
				data[j] = temp;
			}
		}
	}

	return;
}


static void bubble_sort(unsigned int *data, int len)
{
	int i,j;
	unsigned int temp;
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len - i - 1; j++)
		{
			if (data[j] < data[j + 1]) //if condition is data[j] > data[j + 1], it will reverse the result
			{
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] =temp;
			}
		}
	}

	return;
}


int main()
{
	unsigned int* data = (unsigned int*)malloc(sizeof(unsigned int)*ARRAY_SIZE);
	unsigned int i;
	if(data == NULL)
	{
		printf("malloc failed\n");
		return 0;
	}

	for (i = 0; i < ARRAY_SIZE ; i++)
	{
		data[i] = rand();
	}

	/* print_list(data, ARRAY_SIZE); */
	bubble_sort_increase_optimize(data, ARRAY_SIZE);
	printf("-------After Bubble Sort--------\n");
	/* print_list(data, ARRAY_SIZE); */

	free(data);

	return 0;
}
