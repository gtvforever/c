/* *********************************************
TOP150 5.5
Write a function to determine the number of bits
required to convert integer A to integer B
Input:31,14,Output:2
***********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int diff_bit_num(int a, int b)
{
    unsigned int count = 0;
    unsigned int xor;
    
    xor = a^b;

    while(xor)
    {
        if(xor&1)
            count++;

        xor = xor>>1;
    }

    return count;
}


int main()
{
    unsigned int r;

    r = diff_bit_num(0, 23);

    printf("diff bit num is: %d\n", r);

    return 0;
}
