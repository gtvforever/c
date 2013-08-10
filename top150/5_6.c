/*
TOP150 5.6  
Write a program to swap odd and even bits in an integer with as few functions as possible
**/
#include <stdio.h>
#include <stdlib.h>


int swap_odd_even(int value)
{
	return (((value&0xAAAAAAAA)>>1)|((value&0x555555)<<1));
}

int main()
{
	int i = 0xaaaaaaaa;

	int s = swap_odd_even(i);

	printf("%x\n", s);

	return 0;
}
