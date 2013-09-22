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


bool delete_node(List* head, List* to_be_deleted)
{
    List* tmp;

    if(head == NULL ||to_be_deleted == NULL)
        return false;
    
    if(to_be_deleted->next == NULL)
    {
        while(head->next != NULL)
        {
            tmp = head;
            head = head->next;
        }
        tmp->next = NULL;
        free(head);
    }
    else
    {
        tmp = to_be_deleted->next;
        to_be_deleted->key = tmp->key;
        to_be_deleted->next = tmp->next;
        free(tmp);
    }

    return true;
}

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


int main()
{
    List* head = NULL;
    unsigned int i;
    unsigned int tmp;
    List* to_be_deleted = NULL;

    for(i = 0; i < LIST_SIZE; ++i)
    {
        tmp = rand();
        printf("%d\n",tmp);
        add_node_2_list(&head, tmp);

        if(i == 0)
            to_be_deleted = head;
    }
    printf(">>>>>>>>>print list\n");
    plist(head);

    printf(">>>>>>>>>After delete first node\n");
    delete_node(head, to_be_deleted);
    plist(head);
    return 0;
}
