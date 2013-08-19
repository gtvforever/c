/*
Count the number of words in a string, where a word is defined to be
a contiguous sequence of non-space characters.

eg, “Hello, my name is John.” -> 5
http://leetcode.com/2010/02/c-code-to-count-number-of-words-in.html
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum _status
{
	false,
	true,
}bool;


unsigned int get_word_num(char* str)
{
	unsigned int count = 0;
	char* p = str;
	bool enter_word = false;
	bool leave_word = false;
	
	if(p == NULL)
		return 0;

	while(*p != '\0')
	{	
		if(enter_word == true && leave_word == true)
		{
			enter_word = false;
			leave_word = false;
			count++;
		}

		while(isalpha(*p))
		{
			if(enter_word == false)
				enter_word = true;
			p++;
		}
		leave_word = true;
		p++;
	}
	
	if(enter_word == true && leave_word == true)
		count++;

	return count;
}

int main()
{
	char str[256] = " Live a better DAY !";
	printf("string have %d words\n", get_word_num(str));
}
