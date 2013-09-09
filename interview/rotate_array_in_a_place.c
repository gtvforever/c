/*
Rotate a one-dimensional array of n elements to the right by k steps. 
For instance, with n=7 and k=3, the array {a, b, c, d, e, f, g} is rotated to {e, f, g, a, b, c, d}.

http://leetcode.com/2010/04/rotating-array-in-place.html
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum _status
{
	false,
	true,
}bool;

bool reverse_string(char* str, unsigned int begin, unsigned int end)
{
	unsigned int len;
	unsigned int i;
	char tmp;

	if(str == NULL || begin >= end)
		return false;

	len = end - begin + 1;
	for(i = 0; i < len/2; i++)
	{
		tmp = str[i + begin];
		str[begin + i] = str[begin + len - 1 - i];
		str[begin + len - 1 - i] = tmp;
	}
	
	return true;
}

bool reverse_int(int* str, unsigned int begin, unsigned int end)
{
	unsigned int len;
	unsigned int i;
	int tmp;

	if(str == NULL || begin >= end)
		return false;

	len = end - begin;
	for(i = 0; i <= len/2; i++)
	{
		tmp = str[i + begin];
		str[begin + i] = str[begin + len - i];
		str[begin + len - i] = tmp;
	}
	
	return true;
}

void rotate_array_left(int* data, int k, int len)
{
	if(data == NULL)
		return;
	reverse_int(data, 0, len - 1);
	reverse_int(data, 0, len - k - 1);
	reverse_int(data, len - k, len - 1);
}

void rotate_array_right(int* data, int k, int len)
{
	if(data == NULL)
		return;
	reverse_int(data, 0, len - 1);
	reverse_int(data, 0, k - 1);
	reverse_int(data, k, len - 1);
}
int main()
{
	unsigned int i;

	int num[10] = {1,2,3,4,5,6,7,8,9,10};
	
	rotate_array_right(num, 3, 10);
	
	for(i = 0; i < 10; i++)
	{
		printf("%d ", num[i]);
	}
	printf("\n");
}
