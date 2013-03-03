#include <stdio.h>
#include <assert.h>
#define ARRAY_NUMBER   (10)

struct single_list
{
    unsigned int data;
    struct single_list* next;
};

static struct single_list *  list_init_head_node()
{
    struct single_list * p;
    
    p = (struct single_list*)malloc(sizeof(struct single_list));
    
    if (p == NULL) {
        return NULL;
    }
    p->next = NULL;
    return p;
}

static int add_node(struct single_list* head, unsigned int value)
{
    struct single_list* p = head;
    
    while (p->next) {
        p = p->next;
    }
 
    p->next =  (struct single_list*)malloc(sizeof(struct single_list));
    assert(p->next != NULL);
    
    p->next->data = value;
    p->next->next = NULL;
    
    return 0;
}

static void add_node_to_head(struct single_list* head, int value)
{
    struct single_list* p = (struct single_list*)malloc(sizeof(struct single_list));
    
    assert(p != NULL);
    
    p->data = value;
    p->next = head->next;
    head->next = p;
    
}
static int del_node(struct single_list* head, unsigned int value)
{
    struct single_list* p = head->next;
    struct single_list* prev = head;
    while (p) {
        if (p->data == value) {
            prev->next = p->next;
            free(p);
            return 0; //if the programme don't return here, the programe will keep delete the specific value in the list.
        }
        else
        {
            prev = p;
            p = p->next;
        }
    }
    printf("del %d failed!\n",value);
    return -1;
}

static unsigned int get_list_length(struct single_list* head)
{
    unsigned int length = 0;
    struct single_list* p = head->next;
    
    while (p) {
        length++;
        p = p->next;
    }
    
    return length;
}
static void travelsal_list(struct single_list* head)
{
    struct single_list* p = head->next;
    
    if (p == NULL) {
        printf("this is a empty list\n");
        
        return;
    }
    
    while (p) {
        printf("value is %d\n", p->data);
        
        p = p->next;
    }
    return;
}


static void reverse_list(struct single_list* head)
{
    struct single_list* p = head->next;
    struct single_list* q;
    struct single_list* r;


    if (NULL == p || NULL == p->next){
        return;
    }
    
    q = p->next;
    p->next = NULL;
    
    while (q) {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
   
    head->next = p;
    
    return;
}

/* delete the whole list */
static void delete_list(struct single_list* head)
{
	struct single_list* p = head->next;
	struct single_list* q;
	if (p == NULL) {
		return;
	}

	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	
	return;
}

static struct single_list* get_node_addr(struct single_list* head, int value)
{
     struct single_list* p ;
     p = head->next;

     while(p)
     {
         if(p->data != value)
            p = p->next;
         else
            return p;
     }
     return NULL;
}


static void connect_node(struct single_list*head, int value)
{
    struct single_list* p, *q, *r;

	if(head->next == NULL || head->next->next == NULL) {
		return;
	}

    p = get_node_addr(head, value);

	if (p == NULL) {
		return;
	}

    q = head->next;
	/* r = q;  this is useless assignment, because we checked the list number in line 2*/
    while(q->next)
    {
        r = q;
        q = q->next;
    }

    r->next = p;
}


static int  check_list_loop(struct single_list* head)
{
    struct single_list* p,*q;
    
    p = head->next;
    q = head->next->next;
    
    if (head->next == NULL || head->next->next == NULL) {
        return -1;
    }
    
    while( p != q)
    {
        p = p->next;
        if(q->next)
            q = q->next->next;
        else
        {
            return 0;
        }
    }
    return 1; // p == q
}


void list_demo()
{
    struct single_list* head;
    unsigned int loop;
    head = list_init_head_node();
    
    printf("head is %p\r\n", head);
    
    travelsal_list(head);
    
    for (loop = 0; loop < 10; loop++) {
        add_node(head, loop);
    }
    printf("list lenght is %d\n", get_list_length(head));
    travelsal_list(head);
    reverse_list(head);
    travelsal_list(head);
//    del_node(head, 15);
//    travelsal_list(head);
//    printf("list lenght is %d\n", get_list_length(head));
}
