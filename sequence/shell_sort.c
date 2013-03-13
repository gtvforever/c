#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE   (1024*1024)


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


static void shell_sort(unsigned int* data, int len)
{
	int i, j;
	int step;
	unsigned int temp;

	if (data == NULL || len <= 0)
		return;
	step = len;
	do
	{
		step = step/3 + 1;
		for (i = step; i < len; i++)
		{
			if (data[i] < data[i - step])
			{
				temp = data[i];

				for (j = i - step; j >= 0 && data[j] > temp; j -= step)
				{
					data[j + step] = data[j];	
					data[j] = temp;
				}	
			}

		}
	} while (step > 1);

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

	/* print_list(data, ARRAY_SIZE); */
    shell_sort(data, ARRAY_SIZE);
	printf("-------After Shell Sort--------\n");
	print_list(data, ARRAY_SIZE);

    free(data);

    return 0;
}
