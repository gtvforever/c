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
