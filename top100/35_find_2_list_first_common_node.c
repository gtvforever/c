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


void connect_2_list(List* head_1, List* head_2, unsigned int pos)
{
    List* to_be_inserted;
    unsigned int i = 0;

    while(i < pos)
    {
        head_1 = head_1->next;
        i++;
    }
    to_be_inserted = head_1;

    while(head_2->next != NULL)
    {
        head_2 = head_2->next;
    }

    head_2->next = to_be_inserted;
}


bool find_connect_node(List* head_1, List* head_2, int* out)
{
    unsigned int len_1 = 0;
    unsigned int len_2 = 0;
    unsigned int delta;
    List* p = head_1;
    List* q = head_2;

    if(p == NULL || q == NULL)
        return false;

    while(p != NULL)
    {
        p = p->next;
        len_1++;
    }
    
    while(q != NULL)
    {
        q = q->next;
        len_2++;
    }

    p = head_1;
    q = head_2;
    if(len_1 >= len_2)
    {
        delta = len_1 -len_2;
        while(delta-- > 0)
        {
            p = p->next;
        }
    }
    else
    {
        delta = len_2 -len_1;
        while(delta-- > 0)
        {
            q = q->next;
        }
    }
    while( p != q)
    {
        p = p->next;
        q = q->next;
    }
    *out = p->key;
    return true;
}
int main()
{
    List* head_1 = NULL;
    List* head_2 = NULL;
    unsigned int i;
    unsigned int tmp;
    int out;

    for(i = 0; i < LIST_SIZE; ++i)
    {
        tmp = rand();
        add_node_2_list(&head_1, tmp);
    }
    for(i = 0; i < LIST_SIZE/2; ++i)
    {

        tmp = random();
        add_node_2_list(&head_2, tmp);
    }
    printf(">>>>>>>>>print list 1\n");
    plist(head_1);
    printf(">>>>>>>>>print list 2\n");
    plist(head_2);
    connect_2_list(head_1, head_2, 5);
    printf(">>>>>>>>>print list 1\n");
    plist(head_1);
    printf(">>>>>>>>>print list 2\n");
    plist(head_2);
    find_connect_node(head_1, head_2, &out);
    printf(">>>>>>>>>>>>connect node value is %d\n", out);
    return 0;
}
