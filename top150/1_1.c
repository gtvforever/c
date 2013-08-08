/* **********************************************
Top150-1.1
Implement an algorithm to determine if a string 
has all unique characters.What if yu can not use
addtional data structures?
***********************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int check_unique_string(const char* str)
{
    unsigned int i;
    unsigned int len;
    unsigned int flag[128] = {0};
    unsigned int ascii_value;
    if (str == NULL)
        return -1;
    
    len = strlen(str);

    for(i = 0 ; i < len; i++)
    {
        ascii_value = (unsigned int)str[i];
        if (flag[ascii_value] != 0)
        {
            /* printf("%c %d\n",str[i], ascii_value); */
            return 1;
        }
        else
            flag[ascii_value] = 1;
    }

    return 0;
}


int main()
{
    char* test_string = "i have a dream";
    int ret;

    ret = check_unique_string(test_string);

    printf("ret = %d\n", ret);
}
