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


void reverse_list_in_recursive(List* head, List** new_head)
{
    if(head == NULL || head->next == NULL)
    {
        *new_head = head;
        return;
    }

    reverse_list_in_recursive(head->next, new_head);
    head->next->next = head;
    head->next = NULL;
    return;
}

List* reverse_list_no_recursive(List* head)
{
    List* pre;
    List* cur;
    List* n;
    if(head == NULL||head->next == NULL)
        return head;

    pre = NULL;
    cur = head;
    while(cur != NULL)
    {
        n = cur->next;
        cur->next = pre;
        pre = cur;
        cur = n;
    }

    return pre;
}
int main()
{
    List* head = NULL;
    List* new_head;
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
    printf(">>>>>>>>>reverse list in no recursive\n");
    new_head = reverse_list_no_recursive(head);
    plist(new_head);
    printf(">>>>>>>>>reverse list in recursive\n");
    reverse_list_in_recursive(new_head, &new_head);

    plist(new_head);
    return 0;
}
