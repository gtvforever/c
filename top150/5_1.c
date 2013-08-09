/* TOP150 5.1
You are given two 32-bit numbers, N and M, and two bit positions, i and j Write a 
method to set all bits between i and j in N equal to M (e g , M becomes a substring of 
N located at i and starting at j) 
EXAMPLE:
Input: N = 10000000000, M = 10101, i = 2, j = 6
Output: N = 10001010100
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int merge_number(int m, int n, int start, int end)
{
    int i,j = 0;
    int len;
    int mcopy = m;
    int ncopy = n;
    if (start > end)
        return -1;

    len = end - start + 1;
    for(i = 0 ; i < len; i++)
    {
        ncopy = ncopy>>1;
        mcopy = mcopy>>1;
    }
    if(ncopy != 0)
        return -2;

    if(mcopy == 0)
        return -3;

    j = 1<<end;
    j = ~j;
    j |= 1<<start;
    m &= j;
    j = n<<start;
    m |= j;

    return m;

}

int main()
{
    int r;

    r = merge_number(128, 21, 2, 6);
    printf("r is %d\n", r);
}
