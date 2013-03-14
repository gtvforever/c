#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE  (1024*10)

void print_list(unsigned int* data, unsigned int len)
{
	int i = 0;

	for(i = 0; i < len ; i++)
	{
		printf("%d\n", data[i]);
	}
}

static void swap(unsigned int *data,  int low,  int high)
{
	unsigned int temp = data[low];
	data[low] = data[high];
	data[high] = temp;
	return;	
}

static unsigned int get_pivot(unsigned int* data,  int low,  int high)
{
	unsigned int key = data[low];
	while (low < high)
	{
		while(low < high && data[high] >= key)
			high--;
		swap(data,low,high);

		while(low < high && data[low] < key)
			low++;
		swap(data, low, high);

	}

	return low;
}

static void quick_sort(unsigned int* data,  int low,  int high)
{
	unsigned int key;
	if (low < high)
	{
		key = get_pivot(data, low, high);
		quick_sort(data, low, key - 1);
		quick_sort(data, key + 1, high);
	}
}

int main()
{
	unsigned int i;
	unsigned int * data = (unsigned int*)malloc(sizeof(unsigned int)*ARRAY_SIZE);
	if(data == NULL)
		return -1;

	for (i = 0; i < ARRAY_SIZE; i++)
	{
		data[i] = rand();
	}

	/* print_list(data, ARRAY_SIZE); */
	quick_sort(data,0, ARRAY_SIZE - 1);
	printf("----------After quick sort-----------\n");
	/* print_list(data, ARRAY_SIZE); */
	return 0;
}
