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
    struct ListNode* new;
    
    new = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (new == NULL) {
        printf("malloc failed\n");
    }
    new->data = value;
    new->next = NULL;
    
    if (p == NULL) {
        *head = new;
        return;
    }
    else
    {
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = new;
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

static void set_list_into_circle(struct ListNode* head, unsigned int count)
{
    
    struct ListNode* start;
    struct ListNode* end;
    if (head == NULL || head->next == NULL) {
        return;
    }
    
    start = head;
    count -= 1; //because we count postion from 1 instead of zero
    while (start != NULL && count > 0) {
        count--;
        start = start->next;
    }
    if (start != NULL && count == 0) {
        end = start;
        
        while(end->next != NULL) {
            end = end->next;
        }
        end->next = start;
    }
    else
    {
        printf("Invalid input parameter\n");
    }
    return;
}


static int list_have_circle(struct ListNode* head)
{
    struct ListNode* fast, *slow;
    
    if (head == NULL || head->next == NULL) {
        return -1;
    }
    
    fast = head->next->next;
    slow = head;
    
    while (slow != fast) {
        fast = fast->next;
        if (fast->next) {
            fast = fast->next;
        }
        else
        {
            return 0;
        }
        slow = slow->next;
    }
    
    return 1;
}



//get inner circle length
static unsigned int get_circlr_length(struct ListNode* head)
{
    struct ListNode* fast, *slow;
    unsigned int len;
    if (head == NULL || head->next == NULL) {
        return 0;
    }
    
    
    for (fast = slow = head; fast != NULL; fast = fast->next, slow = slow->next) {
        fast = fast->next;
        if (fast == NULL || fast == slow) {
            break;
        }
    }
    if (fast == NULL) {
        return 0;
    }
    
    for (len = 1, fast = fast->next; fast != slow; len++) {
        fast = fast->next;
    }
    
    return len;
}


static unsigned int get_pre_circle_length(struct ListNode* head)
{
    struct ListNode *p, *q;
    unsigned int circle_len;
    unsigned int pre_circle_len;
    circle_len = get_circlr_length(head);
    
    if (circle_len == 0) {
        return 0;
    }
    
    for (p = head; circle_len > 0; circle_len--) {
        p = p->next;
    }
    
    
    for (pre_circle_len = 0, q = head; p != q; pre_circle_len++) {
        p = p->next;
        q = q->next;
    }
    
    return pre_circle_len;
}

static void del_list(struct ListNode** head)
{
    struct ListNode * p = *head;
    struct ListNode * q;
    struct ListNode * r;
    unsigned int pre_circle_length;
    unsigned int circle_length;
    unsigned int loop = 0;
    if (p == NULL) {
        return;
    }
    
    if (list_have_circle(*head) == 1) {
        pre_circle_length = get_pre_circle_length(*head);
        circle_length = get_circlr_length(*head);
        loop = pre_circle_length;
        q = p;
        while (loop > 0) {
            q = q->next;
            loop--;
        }
 
        for (; circle_length > 0; circle_length--) {
            r = q->next;
            free(q);
            q = r;
        }
        
        q = p;
        for (; pre_circle_length > 0; pre_circle_length--) {
            r = q->next;
            free(q);
            q = r;
        }
    }
    else
    {
        while (p != NULL) {
            q = p->next;
            free(p);
            p = q;
        }
 
    }
    *head = NULL;
}

static int check_two_list_connect(struct ListNode* head_1, struct ListNode* head_2)
{
	struct ListNode* head_1_end, * head_2_end;

	if (head_1 == NULL || head_2 == NULL)
		return 0;

	while(head_1 != NULL)
	{
		head_1_end = head_1;
		head_1 = head_1->next;
	}

	while(head_2 != NULL)
	{
		head_2_end = head_2;
		head_2 = head_2->next;
	}
	
	if (head_1 == head_2) {
	
		return 1;
	
	} else {
	
		return 0;
	}

}

static unsigned int get_2_list_meet_pos(struct ListNode* head_1, struct ListNode* head_2)
{
	struct ListNode*p, *q;
	unsigned int pos = 0;
	unsigned int len_1, len_2, offset,i;

	if (head_1 == NULL || head_2 == NULL)
	{
		return;
	}
	len_1 = 0;
	len_2 = 0;
	
	p = head_1;
	q = head_2;
	while(p != NULL)
	{
		len_1++;
		p = p->next;
	}

	while(q != NULL)
	{
		len_2++;
		q = q->next;
	}
	
	offset = len_1 - len_2;
	
	if (offset >= 0)
	{
		p = head_1;
		q = head_2;
	}
	else
	{
		p = head_2;
		q = head_1;
	}

	for (i = 0 ; i < offset; i++)
	{
		p = p->next;
	}

	while ( p != q )
	{
		p = p->next;
		q = q->next;
		i++;
	}

	return i;


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
    i = list_have_circle(head);
    printf("i result is %d\n", i);
    set_list_into_circle(head, 4);
    i = get_circlr_length(head);
    printf("get_circlr_length is %d\n", i);
    i = get_pre_circle_length(head);
    printf("get_pre_circle_length is %d\n", i);
    del_list(&head);
    print_list(head);
}
