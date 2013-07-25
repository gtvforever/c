#include <stdio.h>
#include <assert.h>

//http://leetcode.com/2011/08/reverse-bits.html
unsigned int reverse_bit(unsigned int a)
{
	assert(sizeof(a) == 4);
	a = ((a & 0x55555555)<<1 | (a & 0xAAAAAAAA)>>1);
	a = ((a & 0x33333333)<<2 | (a & 0xCCCCCCCC)>>2);
	a = ((a & 0x0F0F0F0F)<<4 | (a & 0xF0F0F0F0)>>4);
	a = ((a & 0x00FF00FF)<<8 | (a & 0xFF00FF00)>>8);
	a = ((a & 0x0000FFFF)<<16| (a & 0XFFFF0000)>>16); 
	
	return a;
}

int main()
{
	unsigned int a;
	printf("Start reverse a unsigned int bits\n");
	printf("Please input a positive number\n");
	scanf("%d", &a);
	printf("Input number is %d, binary is %x\n", a, a);
	a = reverse_bit(a);
	
	printf("After reverse bit, input number is %x\n", a);
	return 0;

}
