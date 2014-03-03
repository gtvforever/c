#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE   (1024*1024*10)


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

static void merge(unsigned int* src, unsigned int* temp, int s, int m, int n)
{
	int i = s;
	int j = m + 1;
	int k = 0;

	while(i <= m && j <= n)
	{
		if (src[i] <= src[j])
			temp[k++] = src[i++];
		else
			temp[k++] = src[j++];
	}

	while (i <= m)
		temp[k++] = src[i++];
	
	while(j <= n)
		temp[k++] = src[j++];

	for(i = 0; i < k; i++)
	{
		src[s + i] = temp[i];
	}
}


static void merge_sort(unsigned int* origin, unsigned int* temp, int begin, int end)
{
	int middle;
	if(begin < end)
	{
		middle = (begin + end)/2;
		merge_sort(origin, temp, begin, middle);
		merge_sort(origin, temp, middle + 1, end);
		merge(origin, temp, begin, middle, end);
	}
}


int main()
{
	unsigned int* data = (unsigned int*)malloc(sizeof(unsigned int)*ARRAY_SIZE);
	unsigned int* temp = (unsigned int*)malloc(sizeof(unsigned int)*ARRAY_SIZE);
	unsigned int i;
	if(data == NULL || temp == NULL)
	{
		printf("malloc failed\n");
		return -1;
	}

	for (i = 0; i < ARRAY_SIZE ; i++)
	{
		data[i] = rand();
	}

	/* print_list(data, ARRAY_SIZE); */
	merge_sort(data, temp, 0, ARRAY_SIZE - 1);
	printf("-------After Merge Sort--------\n");
	/* print_list(data, ARRAY_SIZE); */

	free(data);
	free(temp);
	return 0;
}
