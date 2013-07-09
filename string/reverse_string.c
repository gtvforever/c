#include <string.h>
#include <stdio.h>
static char name[] = "cisco is an great company!";



void myrevert(char* src)
{
	unsigned int len;
	unsigned int i;
	char temp;

	len = strlen(src);

	len += 1;  //if you want to ignore '\0', you need to comment this line

	if(len == 2)
		return;
	
	for(i = 0; i < len/2; i++)
	{
		/* printf("%d = %d\n", i, len- 1 -i); */
		temp = src[i];
		src[i] = src[len - 1 - i];
		src[len -1 - i] = temp;
	}


}


void myrevert2(char* src)
{
	int end = strlen(src);

	int begin = 0;
	char temp;
	
	if(end == 1)
		return;

	while(begin < end)
	{
		temp = src[end];
		src[end] = src[begin];
		src[begin] = temp;
		end--;
		begin++;
	}

}
int main()
{
	char str[10] = "abcdefgh";
	unsigned int i;
	/* for(i = 0; i < 10; i++) */
	/* { */
		/* printf("%x\n", str[i]); */
	/* } */
	myrevert2(str);
	/* for(i = 0; i < 10; i++) */
	/* { */
		/* printf("%x\n", str[i]); */
	/* } */
	printf("%s\n", str);
}
