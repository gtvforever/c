#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char* my_memcpy(char* dst, const char* src,  unsigned int len)
{
	char* addr = dst;
	unsigned int i;
	if( dst == NULL || src == NULL || len == 0)
		return NULL;

	if ( dst <= src || (src + len) <= dst)
	{
		printf("16\n");
		for (i = 0; i < len; i++)
		{
			dst[i] = src[i];
		}
	}
	else  //overlap case
	{
		while(len)
		{
			dst[len - 1] = src[len - 1]; //reverse copy;
			len--;
		}
	}

	return addr;
}


char* my_strcpy_1(char* dst, const char* src)
{
	char* addr;

	if(dst == NULL || src == NULL)
		return NULL;

	addr = my_memcpy(dst, src, strlen(src)); //or addr = my_memcpy(dst, src, strlen(src) + 1);
	addr[strlen(src)] = '\0';

	return addr;
}

void my_strcpy_2(char* dst, const char* src)
{
	char* addr = dst;

	if (dst == NULL || src == NULL)
		return NULL;

	while((*dst++ = *src++) != '\0');

	return addr;
}

int my_strlen_1(const char* str)
{
	int len = 0;
	
	if(str == NULL)
		return 0;

	while(*str++ != '\0')
		len++;

	return len;
}

int my_strlen_2(const char* str)
{
	if (str == NULL || *str == '\0')
	{
		return 0;
	}
	else
	{
		return my_strlen_2(str + 1) + 1;
	}
}
int main()
{
	unsigned int i;
	char* p = (char*)malloc(sizeof(char)*32);
	/* memset(p, 0, 32); */

	for(i = 0; i < 26; i++)
	{
		p[i] = 97 + i;
		printf("%c", p[i]);
	}
	printf("\n");
	my_memcpy(p + 4, p, 5);
	for(i = 0; i < 26; i++)
	{
		printf("%c", p[i]);
	}
	printf("\n");

	p[10] = '\0';
	printf("%s\n", p);
	printf("len is %d\n", my_strlen_2(p));
	free(p);

	return 0;
}
