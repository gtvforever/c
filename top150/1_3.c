/*
TOP150 1.3
Designe an algorithm and write code to remove the duplicate characters in a string
withou using any additional buffer.
* */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* remove_duplicate_char(char* str)
{
	char flag[256] = {0};
	char temp;
	int len,i,j;

	if(str == NULL)
		return NULL;
	
	len = strlen(str);
	if (len == 1)
		return str;
	flag[(int)str[0]] = 1;
	j = 1;
	for(i = 1; i < len; i++)
	{
		if(flag[(int)str[i]] == 0)
		{
			flag[(int)str[i]] = 1;
			str[j++] = str[i];
		}
	}
	str[j] = '\0';
	return str;
}

int main()
{
	char test[10] = "abccedff";
	char* unique;

	unique = remove_duplicate_char(test);

	printf("%s\n", test);

	return 0;	
}
