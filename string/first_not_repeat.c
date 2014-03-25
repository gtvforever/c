#include <string.h>
#include <stdio.h>

static int first_not_repeat_char(const char* str)
{
	int table[256] = {0};
	unsigned int i;
	unsigned int key;

	if(str == NULL)
		return -1;

	for(i = 0; i < strlen(str); i++)
	{
		key = str[i];
		table[key] += 1;

	}

	i = -1;  //default return value, -1 means we didn't find a char which appear only one time.
    
	for (i = 0; i < 256; i++)
	{
		if(table[i] == 1)
			break;
	}
 
	return i;	
}


int main()
{
	int value = -1;

	char* str = "aabcbdef";

	value = first_not_repeat_char(str);
	if (value != -1)
		printf("value is %c\n", value);
	else
		printf("No single char found\n");

	return 0;
}

