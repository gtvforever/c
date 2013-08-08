/*
 TOP150 1_2
 Write code to reverse a C style sting
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>


void revers_c_style_string(char* str)
{
    unsigned int i,mid;
    unsigned int str_len;
    char temp;
    
    if(str == NULL)
        return;

    str_len = strlen(str) + 1; //we need to count null;
    mid = str_len/2;
    
    if(str_len%2 == 1)
    {
        for(i = 0; i < mid; i++)
        {
            temp = str[i];
            str[i] = str[str_len - 1 - i];
            str[str_len - 1 - i]  = temp;
        }
    }
    else
    {
        for(i = 0; i < mid; i++)
        {
            temp = str[i];
            str[i] = str[str_len - 2 - i];
            str[str_len - 2 - i]  = temp;
        }
    }

}

int main()
{
    char test[7] = "abcdef";

    revers_c_style_string(test);

}
