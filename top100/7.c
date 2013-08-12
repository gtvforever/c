#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverse_string(char* str)
{
    unsigned int len, i, j;
    char* ret = str;
    char* p;
    char temp;
    //step 0 reverse string
    len = strlen(str);

    for(i = 0; i < len/2; i++)
    {
        temp = str[len - 1 - i];
        str[len - 1 - i] = str[i];
        str[i] = temp;
    }
    //step 1 reverse word
    while(len > 0)
    {
        p = strchr(str, ' ');
        if(p != NULL)
        {
            j = p - str;
            len -= j + 1;

        }
        else
        {
            j = len;
            len -= j;
        }
        for(i = 0; i < j/2; i++)
        {
            temp = str[j - 1 -i];
            str[j - 1 - i] = str[i];
            str[i] = temp;
        }

        if(p != NULL)
        {
            str += j + 1;
        }
    }

    return ret;
}


int main()
{
    char str[32] = "what a wondeful day!";
    char* rev;
    
    rev = reverse_string(str);
    printf("%s\n", rev);
}
