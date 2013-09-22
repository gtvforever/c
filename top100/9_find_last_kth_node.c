#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIST_SIZE   (10)
typedef struct _list
{
    struct _list * next;
    int key;
}List;


typedef enum
{
    false,
    true,
}bool;


bool add_node_2_list(List** phead, int data)
{
    List* head;
    List* new_node;
    if(phead == NULL)
        return false;
    
    head = *phead;
    new_node = (List*)malloc(sizeof(List));

    new_node->key = data;
    new_node->next = head;
    *phead = new_node;

    return true;
}


void plist(List* head)
{
    while(head != NULL)
    {
        printf("%d\n", head->key);
        head = head->next;
    }
}


unsigned int get_list_length(List* head)
{
    unsigned int len = 0;

    while(head != NULL)
    {
        ++len;
        head = head->next;
    }

    return len;
}


bool find_last_kth_node(List* head, unsigned int pos, int* out)
{
    List* slow;
    List* fast;
    unsigned int i;
    if(head == NULL || get_list_length(head) < pos || pos < 1)
        return false;

    fast = head;
    for(i = 0; i < pos - 1; ++i)
    {
        fast = fast->next;
    }
    slow = head;
    while(fast->next!= NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    
    *out = slow->key;
    return true;
}


int main()
{
    List* head = NULL;
    unsigned int i;
    unsigned int tmp;
    int out;

    for(i = 0; i < LIST_SIZE; ++i)
    {
        tmp = rand();
        printf("%d\n",tmp);
        add_node_2_list(&head, tmp);

    }
    printf(">>>>>>>>>print list\n");
    plist(head);

    if(find_last_kth_node(head, 3, &out))
        printf(">>>>>>>>>the 3rd node value is %d\n", out);

    return 0;
}
