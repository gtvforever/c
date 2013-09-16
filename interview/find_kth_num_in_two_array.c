#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define SIZE_A (11)
#define SIZE_B (10)
typedef unsigned int uint;

typedef enum 
{
	false,
	true,
}bool;


void merge_array(uint* data, uint* tmp, uint begin, uint mid, uint end)
{
	uint i = begin;
	uint j = mid + 1;
	uint k = 0;

	while(i <= mid && j <= end)
	{
		if(data[i] <= data[j])
			tmp[k++] = data[i++];
		else
			tmp[k++] = data[j++];
	}

	while(i <= mid)
		tmp[k++] = data[i++];

	while(j <= end)
		tmp[k++] = data[j++];

	for(i = 0; i < k; i++)
	{
		data[begin + i] = tmp[i];
	}

}

void merge_sort(uint* data, uint*tmp, uint begin, uint end)
{
	uint mid;
	if(begin < end)
	{
		mid = (begin + end)/2;
		merge_sort(data, tmp, begin, mid);
		merge_sort(data, tmp, mid + 1, end);
		merge_array(data, tmp, begin, mid, end);
	}
}

void plist(uint* data, uint len)
{
	uint i;

	for(i = 0; i < len; i++)
	{
		printf("%d\n", data[i]);
	}
}


bool find_kth_num(uint* array_1, int begin_1, int end_1, uint* array_2, int begin_2, int end_2, uint k)
{
	uint mid_1, mid_2, half_len;

	if(array_1 == NULL ||array_2 == NULL || begin_1 < 0 || begin_2 < 0 || k == 0)
		return -1;

	if(begin_1 > end_1)
		return array_2[begin_2 + k - 1];
	
	if(begin_2 > end_2)
		return array_1[begin_1 + k - 1];

	mid_1 = (begin_1 + end_1)/2;
	mid_2 = (begin_2 + end_2)/2;

	half_len = mid_1 - begin_1 + 1;
	half_len += mid_2 - begin_2 + 1;

	if(array_1[mid_1] < array_2[mid_2])
	{
		if(k < half_len)
		{
			return find_kth_num(array_1, begin_1, end_1, array_2, begin_2, mid_2 - 1, k);
		}
		else
		{
			return find_kth_num(array_1, mid_1 + 1, end_1, array_2, begin_2, end_2, k - (mid_1 - begin_1 + 1));
		}
	}
	else
	{
		if(k < half_len)
		{
			return find_kth_num(array_1, begin_1, mid_1 - 1, array_2, begin_2, end_2, k);
		}
		else
		{
			return find_kth_num(array_1, begin_1, end_1, array_2, mid_2 + 1, end_2, k - (mid_2 - begin_2 + 1));
		}
	}
}


int main()
{
	uint* array_1 = (uint*)malloc(sizeof(uint)*SIZE_A);
	uint* array_2 = (uint*)malloc(sizeof(uint)*SIZE_B);
	uint* tmp = (uint*)malloc(sizeof(uint)*(SIZE_A > SIZE_B?SIZE_A:SIZE_B));
	uint i;
	for (i = 0; i < SIZE_A; ++i)
	{
		array_1[i] = rand();
	}

	for(i = 0; i < SIZE_B; i++)
	{
		array_2[i] = rand();
	}

	printf(">>>>>>>>>after merge_sort<<<<<<<<<\n");
	merge_sort(array_1, tmp, 0, SIZE_A - 1);
	merge_sort(array_2, tmp, 0, SIZE_B - 1);
	plist(array_1, SIZE_A);
	printf(">>>>>>array_2 is\n");
	plist(array_2,SIZE_B);

	i = find_kth_num(array_1, 0, SIZE_A - 1, array_2, 0, SIZE_B - 1, 4);
	printf("4th num is %d\n", i);
	return 0;
}