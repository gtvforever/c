#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE (9)
typedef enum 
{
	false,
	true,
}bool;


#define IS_ODD(N)  (N%2 == 1? true:false)
#define IS_EVEN(N) (N%2 == 0? true:false)

void plist(unsigned int * data, unsigned int len)
{
	unsigned int i;

	for(i = 0; i < len; i++)
	{
		printf("%d\n", data[i]);
	}
}


void myswap(unsigned int* data, unsigned int i, unsigned int j)
{
	unsigned int tmp;

	tmp = data[i];
	data[i] = data[j];
	data[j] = tmp;
}


void swap_odd_even(unsigned int* data, unsigned int len)
{
	unsigned int begin = 0;
	unsigned int end = len - 1;

	while(begin < end)
	{
		while(begin < end && IS_EVEN(data[end]))
			end--;
		myswap(data, begin, end);

		while(begin < end && IS_ODD(data[begin]))
			begin++;
		myswap(data, begin, end);

	}
}


int main()
{
	unsigned int data[SIZE] = {1,4,2,3,5,11,6,22,8};

	swap_odd_even(data, SIZE);

	plist(data,SIZE);

}