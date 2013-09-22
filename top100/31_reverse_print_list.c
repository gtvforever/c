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


void reverse_print_list_in_recursive(List* head)
{
    if(head == NULL)
        return;

    reverse_print_list_in_recursive(head->next);
    printf("%d\n", head->key);
    return;
}


int main()
{
    List* head = NULL;
    unsigned int i;
    unsigned int tmp;

    for(i = 0; i < LIST_SIZE; ++i)
    {
        tmp = rand();
        printf("%d\n",tmp);
        add_node_2_list(&head, tmp);

    }
    printf(">>>>>>>>>print list\n");
    plist(head);

    printf(">>>>>>>>>print list in recursive\n");
    reverse_print_list_in_recursive(head);

    return 0;
}
