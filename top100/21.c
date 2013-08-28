#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void string_reverse(char* s, int begin, int end)
{
	int len = end - begin;
	int i;
	char tmp;

	for(i = 0; i <= len/2; i++)
	{
		tmp = s[begin + len - i];
		s[begin + len - i] = s[begin + i];
		s[begin + i] = tmp;
	}
}


void left_rotate_string(char* str, int length, int pos)
{
	int len = length;
	
	string_reverse(str, 0, len - 1);
	
	string_reverse(str, 0, len - 1 - pos);

	string_reverse(str, len - pos, len - 1);

}

int main()
{
	char test[10] = "abcdef";

	left_rotate_string(test, strlen(test), 2);

	printf("%s\n", test);
}
