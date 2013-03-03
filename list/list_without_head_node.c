//
//  list_without_head_node.c
//  xcodestudy
//
//  Created by guoming on 13-3-2.
//  Copyright (c) 2013年 guoming. All rights reserved.
//

#include <stdio.h>

typedef unsigned int ListType;

struct ListNode
{
    ListType data;
    struct ListNode* next;
};

//Get list length
static unsigned int get_list_length(struct ListNode* head)
{
    unsigned int length = 0;
    struct ListNode* p = head;
    if (NULL == head) {
        return length;
    }
    
    while (p != NULL) {
        length++;
        p = p->next;
    }
    return length;
    
}

static void add_node_to_head(struct ListNode** head, ListType value)
{
    struct ListNode* p = *head;
    struct ListNode* q;
    struct ListNode* new;
 
    new  = (struct ListNode*)malloc(sizeof(struct ListNode));
    new->data = value;
    
    if (p == NULL) {
        printf("head is null\n");
        new->next = NULL;
        
        *head = new;
        
    }
    else
    {
        q = p->next;
        
        p->next = new;
        
        new->next = q;
    }

}

static void add_node_to_tail(struct ListNode** head, ListType value)
{
    struct ListNode* p = *head;
    struct ListNode* q;
    struct ListNode* new;
    
    new = (struct ListNode*)malloc(sizeof(struct ListNode));
    new->data = value;
    new->next = NULL;
    
    if (p == NULL) {
        *head = new;
        return;
    }
    else
    {
        while (p) {
            q = p;
            p = p->next;
        }
        q->next = new;
    }
    
    return;
}


static void reverse_list(struct ListNode* head)
{
    struct ListNode* p = head;
    struct ListNode* q;
    struct ListNode* r;
    
    if (p == NULL || p->next->next == NULL) {
        return;
    }
    
    q = p->next;
    
    while (q) {
        r = q->next;
        
        q->next = p;
        
        p = q;
        
        q = r;
    }
    
    head = p;
    
    return;
}

static struct ListNode* get_mid_node(struct ListNode* head)
{
    struct ListNode* fast, *slow;
    
    if (head == NULL || head->next == NULL) {
        return  NULL;
    }
    
    fast = head;
    slow = head;
    
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
        
        if (fast->next != NULL) {
            fast = fast->next;
        }
    }
    
    return slow;
}

static void print_list(struct ListNode* head)
{
    struct ListNode* p = head;
    
    if (head == NULL) {
        printf("list is empty!\n");
    }
    
    printf("print list in normal sequence.\n");
    while (p != NULL) {
        printf("%d\n", p->data);
        p = p->next;
    }
    
    
}

static void reverse_print_list(struct ListNode* head)
{
    if (head == NULL) {
        printf("print list in reverse sequence.\n");

        return;
    }
    
    reverse_print_list(head->next);

    printf("%d\n", head->data);
    
}

void list_without_head_node_demo()
{
    int i;
    struct ListNode* head = NULL;
    
    for (i = 0; i < 10; i++) {
        add_node_to_tail(&head, i);
    }
    print_list(head);
    reverse_print_list(head);
}