/*
 Implement a algorithm to delete the a node in the middle of a 
 single linked list, given only access to that node.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
    struct _node * next;
    int data;
}Node;


void delete_node(Node* p)
{
    p->data = p->next->data;
    p->next = p->next->next;

    free(p->next);
}
