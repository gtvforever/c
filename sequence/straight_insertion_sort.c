#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE   (10)


void print_list(unsigned int * data, unsigned int len)
{
    unsigned int i;
	if (data == NULL || len == 0)
        return;
	
	for (i = 0; i < len; i++)
    {
        printf("%d\n", data[i]);
    }

    return;
}


static void straight_insertion_sort(unsigned int* data, int len)
{
	int i, j;
	unsigned int temp;

	if (len <= 0)
		return;

	for(i = 1; i <= len - 1; i++)
	{
		
		if (data[i] < data[i - 1])
		{
			temp = data[i];

			for (j = i - 1; data[j] > temp; j--)
			{
				data[j + 1] = data[j];	
			}	
			data[j + 1] = temp;
		}
	}

	return;
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

	print_list(data, ARRAY_SIZE);
    straight_insertion_sort(data, ARRAY_SIZE);
	printf("-------After Straight Insertion Sort--------\n");
	print_list(data, ARRAY_SIZE);

    free(data);

    return 0;
}
