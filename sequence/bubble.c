#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE   (10000)


void print_list(unsigned int * data, unsigned int len)
{
    if (data == NULL || len == 0)
        return;

    while(len-- > 0)
    {
        printf("%d\n", data[len]);
    }

    return;
}

static void bubble_sort(unsigned int *data, unsigned int len)
{
    unsigned int i,j;
    unsigned int temp;
    for (i = 0; i < len; i++)
    {
        for (j = 0; j < len - i - 1; j++)
        {
            if (data[j] < data[j + 1])
            {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] =temp;
            }
        }
    }
}


int main()
{
    unsigned int* data = (unsigned int*)malloc(sizeof(unsigned int)*ARRAY_SIZE);
    unsigned int i;
    if(data == NULL)
    {
        printf("malloc failed\n");
        return 0;
    }

    for (i = 0; i < ARRAY_SIZE ; i++)
    {
        data[i] = rand();
    }

    /* print_list(data, ARRAY_SIZE); */
    bubble_sort(data, ARRAY_SIZE);
    printf("-------After Bubble Sort--------\n");
    /* print_list(data, ARRAY_SIZE); */
    free(data);

    return 0
}
