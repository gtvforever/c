#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE (10)
typedef enum 
{
	false,
	true,
}bool;


void myswap(unsigned int* data, unsigned int i, unsigned int j)
{
	unsigned int tmp = data[i];

	data[i] = data[j];
	data[j] = tmp;

}
unsigned int get_pivot(unsigned int* data,  int begin,  int end)
{
	unsigned int i = begin;
	unsigned int j = end;
	unsigned int tmp;
	unsigned int key = data[begin];

	while(i < j)
	{
		while(i < j && data[j] > key)
			j--;
		myswap(data, i, j);

		while(i < j && data[i] <= key)
			i++;
		myswap(data, i, j);
	}
	return i;
}


//i means how many numbers are less than data[i]
unsigned int get_pivot_2(unsigned int* data, unsigned int begin, unsigned int end)
{

	int i = begin - 1;
	int j;
	for(j = begin; j < end; ++j)
	{
		if(data[j] < data[end])
		{
			myswap(data, ++i, j);
		}
	}
	myswap(data, ++i, end);

	return i;

}


void quick_sort(unsigned int* data,  int begin,  int end)
{
	unsigned int pivot;
	if(begin < end)
	{
		pivot = get_pivot_2(data, begin, end);
		quick_sort(data, begin, pivot - 1);
		quick_sort(data, pivot + 1, end);
	}
}


int find_kth_num(unsigned int* data, unsigned int begin, unsigned int end, unsigned int k)
{
	unsigned int pos;
	if(data == NULL || begin > end || k > end)
	{
		return -1;
	}
	
	pos = get_pivot_2(data, begin, end);
	
	if(pos == k)
	{
		return pos;
	}
	else if(pos < k)
	{
		return find_kth_num(data, pos , end, k - pos);
	}
	else
	{
		return find_kth_num(data, begin, pos - 1, k);
	}
}


void plist(unsigned int * data, unsigned int len)
{
	unsigned int i;

	for(i = 0; i < len; i++)
		printf("%d\n", data[i]);
}


int main()
{
	unsigned int i;
	unsigned int * data;
	unsigned int k = 3;
	data = (unsigned int*)malloc(sizeof(unsigned int)*SIZE);

	for(i = 0; i < SIZE; i++)
	{
		data[i] = rand();
	}
	plist(data, SIZE);
	// quick_sort(back, 0, SIZE - 1);
	// printf(">>>>After sort, the kth one is\n");
	i = find_kth_num(data, 0, SIZE - 1, k);
	printf(">>>>>>find the %dth num is: %d\n", k, data[i]);
	plist(data, SIZE);
	free(data);

	return 0;

}