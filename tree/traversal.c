#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_SIZE (20)

typedef unsigned int ListType;
typedef struct ListNode
{
    ListType data;
    struct ListNode* next;
}NODE, *LIST;

typedef struct _bstnode {
	int key;
	struct _bstnode * lchild, *rchild;
}BST_NODE, *BST_TREE;

typedef enum {
	FALSE,
	TRUE,
}BOOL;

typedef struct _stack
{
	BST_TREE data[MAX_SIZE];
	int top;
}STACK;

typedef struct _queue
{
	BST_TREE data[MAX_SIZE];
	int front, rear;
}QUEUE;

void init_stack(STACK* s)
{
	s->top = -1;
}


void init_queue(QUEUE* q)
{
	q->front = q->rear = 0;
}

BOOL enqueue(QUEUE* q, BST_TREE node)
{
	if(q == NULL || (q->rear + 1)%MAX_SIZE == q->front)
	{
		return FALSE;
	}

	q->data[q->rear] = node;
	
	q->rear = (q->rear + 1)%MAX_SIZE;
	
	return TRUE;
}

BOOL dequeue(QUEUE* q, BST_TREE*out)
{
	if(q == NULL|| q->front == q->rear)
	{
		return FALSE;
	}

	*out = q->data[q->front];
	q->front = (q->front + 1)%MAX_SIZE;

	return TRUE;
}

int get_queue_lenght(QUEUE* q)
{
	if(q == NULL)
		return 0;

	return (q->rear - q->front + MAX_SIZE)%MAX_SIZE;
}
BOOL mypush(STACK* s, BST_TREE value)
{
	if(s == NULL || s->top == MAX_SIZE - 1)
		return FALSE;

	s->data[++s->top] = value;
	return TRUE;
}

BOOL mypop(STACK* s, BST_TREE* out)
{
	if(s == NULL || out == NULL)
		return FALSE;
	if(s->top == -1)
		return FALSE;

	*out = s->data[s->top--];

	return TRUE;
}

BST_TREE mytop(STACK* s)
{
	if(s == NULL || s->top == -1)
		return NULL;

	return s->data[s->top];
}
BOOL isempty(STACK* s)
{
	if(s == NULL)
		return FALSE;

	return s->top == -1?FALSE:TRUE;
}


static void add_node_to_tail(LIST* head, ListType value)
{
    LIST p = *head;
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

BOOL search_bst(BST_TREE root,BST_TREE parent, int data, BST_TREE* last)
{
	if(root == NULL)
	{
		*last = parent;
		return FALSE;
	}
	else if (root->key < data)
	{
		search_bst(root->rchild, root, data, last);
	}
	else if (root->key > data)
	{
		search_bst(root->lchild, root, data, last);
	}
	else
	{
		*last = root;
		return TRUE;
	}
}

BOOL addtobst(BST_TREE *root, int data)
{
	BST_TREE last;
	BST_TREE node;
	if(search_bst(*root, NULL, data, &last) == FALSE)
	{
		node = (BST_TREE)malloc(sizeof(BST_NODE));
		node->key = data;
		node->lchild = node->rchild = NULL;

		if(last == NULL)
		{
			*root = node;
		}
		else if (data < last->key)
		{
			last->lchild = node;
		}
		else
		{
			last->rchild = node;
		}
		
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void pre_order_recursive(BST_TREE root)
{
	if(root == NULL)
		return;
	printf("%d ", root->key);
	pre_order_recursive(root->lchild);
	pre_order_recursive(root->rchild);
}


void in_order_recursive(BST_TREE root)
{
	if(root == NULL)
		return;
	in_order_recursive(root->lchild);
	printf("%d ", root->key);
	in_order_recursive(root->rchild);
}


void post_order_recursive(BST_TREE root)
{
	if(root == NULL)
		return;
	post_order_recursive(root->lchild);
	post_order_recursive(root->rchild);
	printf("%d ", root->key);
}


void pre_order_no_recursive(BST_TREE root)
{
	STACK st;
	STACK *s = &st;
	BST_TREE cur;
	BST_TREE out;

	init_stack(s);
	mypush(s, root);

	while(isempty(s))
	{
		while((cur = mytop(s)) != NULL)
		{
			printf("%d ", cur->key);
			mypush(s, cur->lchild);
		}
		mypop(s, &out);
		
		if(isempty(s))
		{
			cur = mytop(s);
			mypop(s, &out);
			mypush(s, cur->rchild);

		}
	}

}
void in_order_no_recursive(BST_TREE root)
{
	STACK s;
	STACK * p = &s;
	init_stack(p);
	mypush(p, root);
	BST_TREE n;
	BST_TREE tmp;
	while(isempty(&s))
	{
		while((n = mytop(p)))
		{
			mypush(p, n->lchild);
		}

		mypop(p, &tmp);

		if(isempty(p))
		{
			n = mytop(p);
			printf("%d ", n->key);
			mypop(p, &tmp);
			mypush(p, n->rchild);
		}
	}
}


void post_order_without_recursive(BST_TREE root)
{
	BST_TREE pre = NULL;
	BST_TREE cur, out;
	
	STACK st;
	STACK* s = &st;

	if(root == NULL)
		return;

	init_stack(s);
	mypush(s, root);

	while(isempty(s))
	{
		cur = mytop(s);

		if( (cur->lchild == NULL && cur->rchild == NULL)
		   ||(pre != NULL && (pre == cur->lchild|| pre == cur->rchild)))
		{
			printf("%d ", cur->key);
			mypop(s, &out);
			pre = cur;
		}
		else
		{
			if(cur->rchild != NULL)
				mypush(s, cur->rchild);

			if(cur->lchild != NULL)
				mypush(s, cur->lchild);
		}
	}
}


void post_order_without_recursive_2(BST_TREE root)
{
	STACK st;
	STACK* s = &st;
	BST_TREE cur, pre = NULL;
	BST_TREE tmp;

	if(root == NULL)
		return;

	init_stack(s);
	mypush(s, root);

	while(isempty(s))
	{
		cur = mytop(s);

		if(cur == NULL)
		{
			mypop(s, &tmp);
		}
		else if(cur->lchild == NULL && cur->rchild == NULL)
		{
			printf("%d ", cur->key);
			mypop(s, &tmp);
		}
		else if(pre == cur->rchild)
		{
			printf("%d ", cur->key);
			mypop(s, &tmp);
		}
		else if (pre == cur->lchild)
		{
			mypush(s, cur->rchild);
		}
		else
		{
			mypush(s, cur->lchild);
		}

		pre = cur;
	}
}


void level_order(BST_TREE root)
{
	QUEUE queue;
	QUEUE* q = &queue;
	BST_TREE front_node;
	if(root == NULL)
		return;
	
	init_queue(q);
	enqueue(q, root);

	while(dequeue(q, &front_node))
	{
		printf("%d ", front_node->key);
		if(front_node->lchild != NULL)
			enqueue(q, front_node->lchild);

		if(front_node->rchild != NULL)
			enqueue(q, front_node->rchild);
	}
}


void print_all_nodes(int* data, int len)
{
	int i;

	for(i = 0; i < len; i++)
		printf("%d ", data[i]);
}


void print_node_recursive(BST_TREE root, int* data, int len)
{
	if(root == NULL)
		return 0;

	data[len++] = root->key;
	if(root->lchild == NULL && root->rchild == NULL)
	{
		print_all_nodes(data, len);
		printf("\n");
	}	


	if(root->lchild != NULL)
	{
		print_node_recursive(root->lchild, data, len);
	}
	if(root->rchild != NULL)
	{
		print_node_recursive(root->rchild, data, len);
	}
}

int get_sum(int* data, int len)
{
	int i,sum = 0;
	for(i = 0; i < len; i++)
		sum += data[i];
	return sum;
}

void print_node_sum(BST_TREE root, int* data, int len, int sum)
{
	if(root == NULL)
		return;
	
	data[len++] = root->key;
	if(get_sum(data,len) == sum)
	{
		print_all_nodes(data, len);
		printf("\n");
		return;
	}
	if(root->lchild == NULL && root->rchild == NULL)
	{
		return;
	}	


	if(root->lchild != NULL)
	{
		print_node_sum(root->lchild, data, len,sum);
	}
	if(root->rchild != NULL)
	{
		print_node_sum(root->rchild, data, len,sum);
	}
}

void get_kth_level_node(BST_TREE root, int cur, int desire)
{
	if(root == NULL || cur > desire)
		return;

	if(cur == desire)
	{
		printf("%d ", root->key);
		return;
	}	

	if(root->lchild != NULL)
		get_kth_level_node(root->lchild, cur + 1, desire);
	
	if(root->rchild != NULL)
		get_kth_level_node(root->rchild, cur + 1, desire);
}

BST_TREE create_bst_from_array(int* data, int begin, int end)
{
	int mid;
	BST_TREE root;
	if(begin > end)
		return NULL;
	mid = begin + (end - begin)/2;
	
	root = (BST_TREE)malloc(sizeof(BST_NODE));
	root->key = data[mid];
	root->lchild = create_bst_from_array(data,begin, mid -1);
	root->rchild = create_bst_from_array(data, mid + 1, end);

	return root;
}


BST_TREE create_bst_from_list(LIST* list, int begin, int end)
{
    int mid;
    BST_TREE left;
    BST_TREE parent;
    if(begin > end)
        return NULL;
    mid = begin + (end - begin)/2;
    
    left = create_bst_from_list(list, begin, mid - 1);
    
    parent = (BST_TREE)malloc(sizeof(BST_NODE));
    parent->key = (*list)->data;
    
    *list = (*list)->next;
    
    parent->lchild = left;
    parent->rchild = create_bst_from_list(list, mid + 1, end);
    
    return parent;
}
int main()
{
	int i;
	int value;
	int data[11] = {6,4,8,2,5,7,9,10,1,3,0};
	int cdata[11] = {1,2,3,4,5,6,7,8,9,10,11};
	int path[20] = {0};
	BST_TREE root = NULL;
	BST_TREE lca;
	BST_TREE t;
	LIST list = NULL;
	for (i = 0; i < sizeof(data)/sizeof(data[0]); i++)
	{
		addtobst(&root, data[i]);
	}
	printf(">>>>>>pre order in recursive<<<<<<\n");
	pre_order_recursive(root);
	printf("\n");
	printf("***pre order without recursive***\n");
	pre_order_no_recursive(root);
	printf("\n");
	printf(">>>>>>in order in recursive<<<<<<<\n");
	in_order_recursive(root);
	printf("\n");
	printf("****in order without recursive****\n");
	in_order_no_recursive(root);
	printf("\n");
	printf(">>>>>>post order in recursive<<<<<\n");
	post_order_recursive(root);
	printf("\n");
	printf("****in order without recursive method 1****\n");
	post_order_without_recursive(root);
	printf("\n");
	printf("****in order without recursive method 2****\n");
	post_order_without_recursive_2(root);
	printf("\n");
	
	printf("level order\n");
	level_order(root);
	printf("\n");
	printf("path sum equal to 15\n");
	print_node_sum(root,path,0,15);
	printf("all path:\n");
	print_node_recursive(root, path, 0);

	printf("level 3 nodes is:\n");
	get_kth_level_node(root,0,2);
	printf("\n");

	t = create_bst_from_array(cdata,0,10);
	printf("new bst\n");
	in_order_recursive(t);
	printf("\n");
	
	printf("create bst from list\n");
    for (i = 0; i < 11; i++) {
        add_node_to_tail(&list, cdata[i]);
    }
	t = create_bst_from_list(&list, 0, 10);
    in_order_recursive(t);
	printf("\n");
	return 0;
}
