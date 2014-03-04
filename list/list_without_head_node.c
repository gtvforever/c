//
//  list_without_head_node.c
//  xcodestudy
//
//  Created by guoming on 13-3-2.
//  Copyright (c) 2013年 guoming. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
typedef unsigned int ListType;

typedef struct ListNode
{
    ListType data;
    struct ListNode* next;
}NODE;

//Get list length
static unsigned int get_list_length(struct ListNode* head)
{
    unsigned int length = 0;
    struct ListNode* p = head;
    
    while (p != NULL) {
        length++;
        p = p->next;
    }

    return length;
}

static void add_node_to_head(struct ListNode** head, ListType value)
{
    struct ListNode* p = *head;
    struct ListNode* new_node;

    new_node  = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->data = value;
    
    if (p == NULL) {
        /* printf("head is null\n"); */
        new_node->next = NULL;
    }
    else
    {
        new_node->next = p;
    }
    *head = new_node;
    
    return;
}

static void add_node_to_tail(struct ListNode** head, ListType value)
{
    struct ListNode* p = *head;
    struct ListNode* new_node;
    
    new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (new_node == NULL)
    {
        printf("malloc failed\n");
    }
    new_node->data = value;
    new_node->next = NULL;
    
    if (p == NULL) {
        *head = new_node;
    }
    else
    {
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = new_node;
    }
    
    return;
}


static void reverse_list_recursive_2(NODE* head, NODE** new_head)
{

	if(head == NULL)
	{
		return;
	}

	if(head->next == NULL)
	{
		*new_head = head;
		return;
	}

	reverse_list_recursive_2(head->next, new_head);

	head->next->next = head;
	head->next = NULL;

}


static struct ListNode* reverse_list_recursive(struct ListNode* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    else
    {
        struct ListNode* r;
        r = reverse_list_recursive(head->next);
        head->next->next = head;
        head->next = NULL;
        return r;
    }
}


static int reverse_list(struct ListNode** head)
{
    struct ListNode* p = *head;
    struct ListNode* q;
    struct ListNode* r;
    
    if (p == NULL || p->next == NULL)
    {
        return -1;
    }
    
    q = p->next;
    p->next = NULL;
    while (q) {
        r = q->next;
        
        q->next = p;
        
        p = q;
        
        q = r;
    }
    
    *head = p;
    
    return 0;
}


static NODE* reverse_list_non_recursive(NODE* head)
{
	NODE* last;
	NODE* cur;
	NODE* tmp;
	
	if(head == NULL)
    {
		return NULL;
    }
	
	if(head->next == NULL)
    {
		return head;
    }

	last = head;
	
	cur = head->next;
	
	last->next = NULL;

	while(cur != NULL)
	{
		tmp = cur->next;
		cur->next = last;
		last = cur;
		cur = tmp;
	}

	return last;
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
    
    if (head == NULL) {
        return -1;
    }
    
    fast = head;
    slow = head;
    
    while(fast != NULL && fast->next != NULL)
    {
    	fast = fast->next->next;
    	slow = slow->next;

    	if(fast == slow)
    		return 0;
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
	unsigned int len_1, len_2, i;
	int offset;
	if (head_1 == NULL || head_2 == NULL)
	{
		return 0;
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


static void connect_2_list(struct ListNode* head_1, struct ListNode* head_2)
{
    unsigned int len_1 = 0;
    unsigned int len_2 = 0;
    unsigned int len;
    struct ListNode* p;
    struct ListNode* q;
    
    for (p = head_1; p != NULL; len_1++) {
        p = p->next;
    }
    
    for (p = head_2; p != NULL; len_2++) {
        p = p->next;
    }
    
    if (len_1 >= len_2) {
        p = head_2;
        q = head_1;
        len = len_2;

    } else {
        p = head_1;
        q = head_2;
        len = len_1;
    }
    
    while (p->next) {
        p = p->next;
    }
    while (len--) {
        q = q->next;
    }

    p->next = q;
    return;
}



static NODE* list_merge_1(NODE* head_1, NODE* head_2)
{
	NODE* p1 = head_1;
	NODE* p2 = head_2;
	NODE* cur;
	NODE* head;

	if (p1 == NULL )
	{
		return p2;
	}
	
	if (p2 == NULL)
	{
		return p1;
	}

	if(p1->data <= p2->data)
	{
		head = p1;
		p1 = p1->next;
	}
	else
	{
		head = p2;
		p2 = p2->next;
	}

	cur = head;
	
	while(p1 != NULL && p2 != NULL)
	{
		if (p1->data < p2->data)
		{
			cur->next = p1;
			cur = p1;
			p1 = p1->next;
		}
		else
		{
			cur->next = p2;
			cur = p2;
			p2 = p2->next;
		}
	}

	if (p1 != NULL)
	{
		cur->next = p1;
	}

	if (p2 != NULL)
	{
		cur->next = p2;
	}

	return head;
}


static NODE* list_merge(NODE* p1, NODE* p2)
{
    NODE* ret;

    if (p1 == NULL)
    {
        return p2;
    }

    if (p2 == NULL)
    {
        return p1;
    }

    if (p1->data < p2->data)
    {
        ret = p1;
        ret->next = list_merge(p1->next, p2);
    }
    else
    {
        ret = p2;
        ret->next = list_merge(p1, p2->next);
    }

    return ret;

}


static NODE* get_kth_node(NODE* head, unsigned int k)
{
    NODE* p, *q;
    if (head == NULL || k < 1)
    {
    	return NULL;
    }

    p = q = head;

    while(p && k > 0)
    {
    	p = p->next;
    	k--;
    }

    if(p != NULL)
    {
        while(p != NULL)
        {
            p = p->next;
            q = q->next;
        }
        return q;
    }
    else
    {
        return NULL;
    }

}

int main()
{
    int i;
    struct ListNode* head = NULL;
    struct ListNode* head_1, *head_2, *head_3;
    for (i = 0; i < 8; i++) {
      add_node_to_tail(&head, i);
  }
  print_list(head);
  reverse_print_list(head);
  set_list_into_circle(head, 4);
  i = list_have_circle(head);
  printf("i result is %d\n", i);
 /*    i = get_circlr_length(head);                */
 /* //   print_list(head);                         */
 /*    printf("get_circlr_length is %d\n", i);     */
 /*    i = get_pre_circle_length(head);            */
 /*    printf("get_pre_circle_length is %d\n", i); */
 /*    del_list(&head);                            */
 /*    print_list(head);                           */

	/* int data[10] = {1,2,3,4,5,6,7,8,9,10};     */
	/* for (i = 0,head_1 = NULL; i < 10; i+=2) {  */
	/*     add_node_to_tail(&head_1, data[i]);    */
	/* }                                          */

	/* print_list(head_1);                        */
	/*                                            */
	/* for (i = 1, head_2 = NULL; i < 10; i+=2) { */
	/*     add_node_to_tail(&head_2, data[i]);    */
	/* }                                          */
	/* print_list(head_2);                        */
	/*                                            */
	/* head_3 = list_merge_1(head_1, head_2);     */
	/* print_list(head_3);                        */
    /* connect_2_list(head_1, head_2); */
    /* printf("meet pos is %d\n",get_2_list_meet_pos(head_1, head_2)); */
}