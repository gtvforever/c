#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE   (1024*102)


void print_list(unsigned int * data, unsigned int len)
{
	unsigned int i;
	if (data == NULL || len == 0)
		return;

	for (i = 0; i < len; i++)
	{
		printf("%d\n", data[i]);
	}

	return;
}


static void simple_selection_sort(unsigned int* data, int len)
{
	int i, j;
	unsigned int temp;
	unsigned int min;

	if (len <= 0)
		return;

	for(i = 0; i < len - 1; i++)
	{
		min = i;

		for (j = i + 1 ; j < len; j++)
		{
			if (data[j] < data[min])
			{
				min = j;
			}
		}
		if (i != min)
		{
			temp = data[min];
			data[min] = data[i];
			data[i] = temp;
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
	simple_selection_sort(data, ARRAY_SIZE);
	printf("-------After Simple Selection Sort--------\n");
	/* print_list(data, ARRAY_SIZE); */

	free(data);

	return 0;
}
