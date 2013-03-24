#include <stdio.h>
#include <stdlib.h>


#define MAX   (50)
typedef enum _status
{
	false,
	true
}STATUS;

STATUS binary_search(int* data, int key, unsigned int* pos)
{
	int low,mid,high;
	unsigned int count = 0;
	low = 0;
	high = MAX;

	while(low < high)
	{
		mid = (high + low)/2;
		count++;
		if (data[mid] < key)
		{
			low = mid + 1;	
		}
		else if (data[mid] > key)
		{
			high = mid + 1;
		}
		else
		{
			*pos = count;
			return true;
		}

	}

	return false;
}


static void shell_sort(int* data, unsigned int len)
{
	unsigned int key = len;
	int i,j,temp;
	while(key > 1)
	{
		key  = key/3 + 1;

		for (i = key ; i < len; i++)
		{
			if (data[i] < data[i - key])
			{
				temp = data[i];
				for (j = i - key; j >= 0 && data[j] > temp; j -= key)
				{
					data[j + key] = data[j];
				}

				data[j + key] = temp;
			}

		}

	}

}

int main()
{
	unsigned int i, pos;
	int * data, input;
	STATUS ret;
	data = (int*)malloc(sizeof(int)*MAX);

	if (NULL == data)
	{
		printf("malloc failed\n");
		return -1;
	}

	for (i = 0 ; i < MAX; i++)
	{
		data[i] = rand();
		/* printf("data[%d] = %d\n", i, data[i]); */
	}
	shell_sort(data, MAX);
	printf(">>>>>>After shell sort\n");
	for (i = 0; i < MAX; i++)
	{
		printf("data[%d] = %d\n", i, data[i]);
	}
	printf("please input a key: ");
	scanf("%d", &input);

	printf("You input value is %d\n", input);
	ret = binary_search(data, input, &pos);
	if (ret == true)
	{
		printf(">>>>>>>>After %d  times search, we got it!<<<<<<<<<<\n", pos);
	}
	else
	{
		printf(">>>>>>>>Search failed!<<<<<<<<<<\n");
	}
}
