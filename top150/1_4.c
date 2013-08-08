/******************************************************************
 * 1.4 write a method to replace all spaces in a string with "%20"
 * ***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* replacestr(const char* p)
{
    unsigned int space_count = 0;
    unsigned int new_len = strlen(p);
    unsigned int i, j;
    char* str;
    const char* init_p = p;

    if (p == NULL)
        return NULL;

    while(*p != '\0')
    {
        if(*p == ' ')
            space_count++;
        p++;
    }

    new_len += space_count*2;

    str = (char*)malloc(sizeof(char)*(new_len + 1));
    if(str == NULL)
        return NULL;
    
    memset(str, 0, new_len + 1);

    p = init_p;
    for(i = 0, j = 0; j < new_len; i++)
    {
        if(p[i] != ' ')
        {
            str[j] = p[i];
            j++;
        }
        else
        {
            str[j] = '%';
            str[j + 1] = '2';
            str[j + 2] = '0';
            j += 3;
        }
    }

    return str;
}


int main()
{
    char* str;

    str = replacestr("all i need is a chance");
    printf("%s \n", str);
}

