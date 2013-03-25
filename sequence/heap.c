#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE   (1024*1024)


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

void swap(unsigned int* data, int src, int dst)
{
	unsigned int temp = data[src];

	data[src] = data[dst];
	data[dst] = temp;

	return;

}
void heap_adjust(unsigned int* data, int start, int length)
{
	int i;
	unsigned int temp = data[start];


	for (i = start*2; i <= length; i *= 2)
	{
		if (i < length && data[i] < data[i + 1])
			i++;
		
		if (temp >= data[i])
			break;

		data[start] = data[i];
		start = i;
	}	
	
	data[start] = temp;
}

int heap_sort(unsigned int* data, int length)
{
	int i;

	for(i = length/2; i > 0; i--)
	{
		heap_adjust(data, i, length);
	}
	
	for (i = length; i > 1; i--)
	{	
		swap(data, 1, i);	
		heap_adjust(data, 1, i - 1);
	}

}
int main()
{
	unsigned int* data = (unsigned int*)malloc(sizeof(unsigned int)*(ARRAY_SIZE + 1));
	unsigned int i;
	if(data == NULL)
	{
		printf("malloc failed\n");
		return 0;
	}

	for (i = 1; i < ARRAY_SIZE + 1; i++)
	{
		data[i] = rand();
	}

	/* print_list(data + 1, ARRAY_SIZE); */
	heap_sort(data, ARRAY_SIZE);
	printf("-------After Heap Sort--------\n");
	/* print_list(data + 1, ARRAY_SIZE); */

	free(data);

	return 0;
}
