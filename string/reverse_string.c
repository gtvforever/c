#include <string.h>

static char name[] = "cisco is an great company!";


void reverse_stringerse_string(char* p)
{
	int len;
	int i;
	char* blank_pos;
	char* rev_str_1 = NULL;
	char* rev_str_2 = NULL;

	char* init_pos_1 = NULL;
	char* init_pos_2 = NULL;
	int offset = 0;

	if(NULL == p)
		return NULL;

	len = strlen(p);
	rev_str_1 = (char*)malloc(len*sizeof(char) + 1);
	rev_str_2 = (char*)malloc(len*sizeof(char) + 1);
	init_pos_1 = rev_str_1;
	init_pos_2 = rev_str_2;

	if(rev_str_1 == NULL || rev_str_2 == NULL)
		return NULL;

	for(i = 0 ; i < len; i++)
	{
		rev_str_1[i] = name[len - i - 1];
	}
	rev_str_1[len] = '\0';

	printf("rev_str_1 is>>> %s\n", rev_str_1);

	while(1)
	{
		blank_pos = strchr(init_pos_1 , ' ');

		if(blank_pos == NULL)
		{
			break;
		}
		offset = blank_pos - init_pos_1;

		for (i = 0; i < offset; i++)
		{
			init_pos_2[i] = init_pos_1[offset - i - 1];
		}
		init_pos_2[offset] = ' ';
		init_pos_1 += offset + 1;
		init_pos_2 += offset + 1;
	}

	offset = strlen(init_pos_1);
	for (i = 0 ; i < offset; i++)
	{
		init_pos_2[i] = init_pos_1[offset - i - 1];
	}

	printf("rev_str_2 is>>> %s\r\n", rev_str_2 );

	free(rev_str_1);
	free(rev_str_2);
}



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
int main()
{
	char str[10] = "abcdefgh";
	unsigned int i;
	/* for(i = 0; i < 10; i++) */
	/* { */
		/* printf("%x\n", str[i]); */
	/* } */
	myrevert(str);
	/* for(i = 0; i < 10; i++) */
	/* { */
		/* printf("%x\n", str[i]); */
	/* } */
	printf("%s\n", str);
}
