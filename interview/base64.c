#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const char base[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";


static char find_pos(const char c)
{
	char* p = strchr(base, c);
	return (char)(p - base);
}


int base64_encode(const char* in, char** out)
{
	char* convert = NULL;
	char* initial_pos;
	unsigned int pos;
	unsigned int in_len;
	unsigned int out_len;
	unsigned int tmp;
	unsigned int equal_len;
	if(in == NULL)
		return -1;

	in_len = strlen(in);
	equal_len = in_len%3;

	out_len = in_len*4/3;

	out_len += equal_len == 0?0:3;
	out_len++; //reserver for '\0'

	
	convert = (char*)malloc(sizeof(char)*(out_len));
	memset(convert, 0, out_len);

	initial_pos = convert;
	pos = 0;
	in_len -= equal_len;

	if(equal_len != 0)
		equal_len = 3 - equal_len;

	while(pos < in_len)
	{
		tmp = in[pos]>>2;
		*convert++ = base[tmp];

		tmp = (in[pos++]&0x03)<<4;
		tmp |= in[pos]>>4;
		*convert++ = base[tmp];

		tmp = (in[pos++]&0x0f)<<2;
		tmp |= in[pos]>>6;
		*convert++ = base[tmp];

		tmp = in[pos++]&0x3f;
		*convert++ = base[tmp];
	}

	if(equal_len == 1)
	{
		tmp = in[pos]>>2;
		*convert++ = base[tmp];

		tmp = (in[pos++]&0x03)<<4;
		tmp |= in[pos]>>4;
		*convert++ = base[tmp];

		tmp = (in[pos++]&0x0f)<<2;
		*convert++ = base[tmp];
		*convert++ = '=';

	}
	
	if(equal_len == 2)
	{
		tmp = in[pos]>>2;
		*convert++ = base[tmp];

		tmp = (in[pos++]&0x03)<<4;
		*convert++ = base[tmp];

		*convert++ = '=';
		*convert++ = '=';


	}

	*convert = '\0';
	*out = initial_pos;

	return convert - initial_pos;

}



int base64_decode(const char* in,  char** out)
{
	char* convert;
	char* initial_pos;
	char p1 = 0;
	char p2 = 0;
	char p3 = 0;
	char p4 = 0;
	unsigned int out_len;
	unsigned int in_len;
	unsigned int equal_num = 0;
	unsigned int pos = 0;
	if(in == NULL)
		return -1;

	in_len = strlen(in);
	out_len = (in_len*3)/4 + 1;

	if(in[in_len - 1] == '=')
		equal_num = 1;

	if(in[in_len - 2] == '=')
		equal_num = 2;

	if(equal_num != 0)
		in_len -= 4;   //we process the front part withou '=' firstly

	convert = (char*)malloc(sizeof(char)*out_len);
	memset(convert, 0, out_len);
	initial_pos = convert;
	while(pos < in_len)
	{
		p1 = find_pos(in[pos++]);
		p2 = find_pos(in[pos++]);
		p3 = find_pos(in[pos++]);
		p4 = find_pos(in[pos++]);
		
		*convert++ = (p1<<2)|(p2>>4);
		*convert++ = (p2<<4)|(p3>>2);
		*convert++ = (p3<<6)|p4;
	}

	if(equal_num == 1)
	{
		p1 = find_pos(in[pos++]);
		p2 = find_pos(in[pos++]);
		p3 = find_pos(in[pos++]);

		*convert++ = (p1<<2)|(p2>>4);
		*convert++ = (p2<<4)|(p3>>2);

	}

	if(equal_num == 2)
	{
		p1 = find_pos(in[pos++]);
		p2 = find_pos(in[pos++]);

		*convert++ = (p1<<2)|(p2>>4);

	}

	*convert = '\0';
	*out = initial_pos;
	return convert - initial_pos;
}



int main()
{
	char* out;
	 char* out_decode;
	char* test = "abcdefgh12";
	unsigned int len;
	unsigned int i;
	printf(">>>>>>start base64 test<<<<<<\n");
	printf(">>>test string is %s<<<<\n\n", test);

	printf(">>>>>>base 64 encode\n");
	len = base64_encode(test, &out);
	printf("test strig have been encoded as:\n");
	for(i = 0; i < len; i++)
		printf("%c", out[i]);

	printf("\n\n");

	len = base64_decode(out, &out_decode);


	printf(">>>>>>>base64 decode\n");
	printf("origin string is %s\n", out_decode);

	return 0;
}