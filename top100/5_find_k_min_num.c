#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE  (10)
typedef enum
{
    false,
    true,
}bool;


void myswap(unsigned int* data, unsigned int i, unsigned int j)
{
    unsigned int tmp;
    tmp = data[i];

    data[i] = data[j];
    data[j] = tmp;
}


unsigned int get_pivot_2(unsigned int* data, unsigned int begin, unsigned int end)
{

    int i = begin - 1;
    int j;

    for(j = begin; j < end; ++j)
    {
        if(data[j] < data[end])
        {
            myswap(data, ++i, j);
        }
    }
    myswap(data, ++i, end);

    return i;

}


unsigned int get_pivot(unsigned int* data, unsigned int begin, unsigned int end)
{
    unsigned int tmp = data[begin];

    unsigned int i = begin;
    unsigned int j = end;
    while(i < j)
    {
        while(i < j && data[j] > tmp)
            j--;
        myswap(data, i, j);
        while(i < j && data[i] <= tmp)
            i++;
        myswap(data, i, j);
    }
    return i;
}


bool find_kth_num(unsigned int* data, unsigned int begin, unsigned int end, unsigned int k)
{
    unsigned int pivot = 0;

    if(begin > end)
    {
        /* printf("begin %d end %d\n", begin, end); */
        return false;
    }
    if(k > end - begin + 1)
    {
        /* printf("k > end - begin + 1\n"); */
        return false;
    }
    
    pivot = get_pivot(data, begin, end);
    if(pivot == k - 1)
        return true;
    else if(k - 1< pivot)
        return find_kth_num(data, begin, pivot-1, k);
    else
        return find_kth_num(data, begin + pivot + 1, end, k - pivot -1);
}


int main()
{
    unsigned int* data = (unsigned int*)malloc(sizeof(unsigned int)*SIZE);
    unsigned int i, tmp;
    unsigned int pivot;
    for(i = 0; i < SIZE; i++)
    {
        tmp = rand();
        printf("%d\n", tmp);
        data[i] = tmp;
    }
    pivot = find_kth_num(data, 0, SIZE -1, 5);
    printf(">>>>>>>>>>>>Find the minimal 5 numbers\n");
    for(i = 0; i < 5; i++)
        printf("%d\n", data[i]);
    return 0;
}
