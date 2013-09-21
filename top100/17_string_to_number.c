#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int myatoi(char* str)
{
	int ret;
	int negative = 0;
	char* start;
	int num = 0;

	if(*str == '-' || ( *str >= '0' && *str <= '9'))
	{
		start = str;
		
		if(*start == '-')
		{
			negative = 1;
			start++;
		}

		
		while(*start >= '0' && *start <= '9')
		{
			if(num == INT_MAX/10)
			{
				if(negative == 1 && *start == '9')
				{
					printf("negative overflow\n");
					return 0;
				}
				
				if (negative == 0 &&*start >= '8')
				{
					printf("positive overflow\n");
					return 0;
				}

			}

			num *= 10;
			num += *start - '0';
			start++;
		}

		if(negative == 1)
		{
			num = 0 - num;
		}
	
		return num;
	}
	else
	{
		return 0;
	}
}

int main()
{
	char* str = "-2147483649";
	int n = myatoi(str);
	
	printf("str is %d\n", n);
	
	return 0;
}
