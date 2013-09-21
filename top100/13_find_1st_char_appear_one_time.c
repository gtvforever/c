#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char get_first_single_char(char* str)
{
	unsigned int flag[256] = {0};
	unsigned int i;	
	char* key = str;
	char tmp;
	while(*str != '\0')
	{
		tmp = *str;
		flag[(unsigned int)tmp] += 1;
		str++;
	}

	while(*key != '\0')
	{
		if(flag[*key] == 1)
			return *key;
		key++;
	}
	return 0;
}

int main()
{
	char test[16] ="bbdcd";

	char result;

	result = get_first_single_char(test);
	printf("%c\n", result);

	return 0;
}
