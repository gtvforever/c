#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_pos(int* data, unsigned int len, unsigned int value)
{
	unsigned int start, end;
	unsigned int mid;

	printf("Searching index of value %d\n", value);
	if(data == NULL || len < 1)
		return -1;
	start = 0;
	end = len - 1;

	while(start < end)
	{
		mid = (end + start)/2;
		
		if(data[mid] == value)
		{
			return mid;
		}
		else if(data[mid] <= value && value <= data[end])
		{
			start = mid;
		}
		else if(data[start] <= value && value <= data[mid])
		{
			end = mid;
		}
		else if(data[start]<= value && value > data[mid])
		{
			end = mid;
		}
		else if(data[start] > value && value <= data[mid])
		{
			end = mid;
		}
		else if(data[mid] <= value && value > data[end])
		{
			start = mid;
		}
		else if(data[mid] > value && value < data[end])
		{
			start = end;
		}
	}
	
	printf("Search failed\n");

	return -1;

}
int get_min_num_pos(int* data, unsigned int len, unsigned int value)
{
	unsigned int start, end;
	unsigned int mid;

	if(data == NULL || len < 1)
	{
		return -1;
	}

	start = 0;
	end = len - 1;

	while(start < end)
	{
		mid = (end + start)/2;
		if(data[start] < data[mid] && data[mid] > data[end])
		{
			start = mid + 1;
		}
		else if(data[start] > data[mid] && data[mid] < data[end])
		{
			end = mid;
		}
		else
		{
			return start;;
		}
	}
}

int main()
{
	int data[14] = {15,16,19,20,25,1,3,4,5,6,7,10,14};
	/* int data[14] = {15,16,1,2,3,4,5,6,7,8,9,10,11,12}; */
	/* int data[6] = {7,8,9,1,2,3}; */
	unsigned int pos;

	pos = get_pos(data, sizeof(data)/sizeof(data[0]), 5);

	printf("data[%d] = %d\n", pos, data[pos]);
}
