#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _bstnode {
	int key;
	struct _bstnode * lchild, *rchild;
}BST_NODE, *BST_TREE;

typedef enum {
	FALSE,
	TRUE,
}BOOL;

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

typedef struct queue_node {

	struct queue_node* next;
	BST_TREE data;
}QUEUE_NODE;

typedef struct queue {
	QUEUE_NODE* front, *rear;
}QUEUE;

void init_queue(QUEUE* queue)
{
	queue->front = queue->rear = NULL;
}

void enqueue(QUEUE* queue, BST_TREE value)
{
	QUEUE_NODE* new = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE));
	
	new->next = NULL;
	new->data = value;

	if(queue->front == NULL)
	{
		queue->front = queue->rear = new;
	}
	else
	{
		queue->rear->next = new;
		queue->rear = new;
	}
}


BOOL dequeue(QUEUE* queue, int* out)
{
	QUEUE_NODE* tmp;
	if(queue->front == NULL)
		return FALSE;

	tmp = queue->front->next;
	*out = queue->front->data->key;
	if(queue->front == queue->rear)
		queue->rear = tmp;
	free(queue->front);
	queue->front = tmp;
}

BOOL isempty(QUEUE* queue)
{
	return queue->front == NULL? TRUE:FALSE;
}
QUEUE_NODE* get_front(QUEUE* queue)
{
	return queue->front;
}

QUEUE gqueue;
void level_order_bst(BST_TREE root)
{
	QUEUE_NODE * front_node;
	int out;
	if(root == NULL)
		return;
	enqueue(&gqueue, root);
	
	while(!isempty(&gqueue))
	{
		front_node = get_front(&gqueue);
		printf("%d\n", front_node->data->key);
		if(front_node->data->lchild != NULL)
			enqueue(&gqueue, front_node->data->lchild);
		if(front_node->data->rchild != NULL)
			enqueue(&gqueue, front_node->data->rchild);
		dequeue(&gqueue, &out);
	}
}

/*
       6
     4   8
   2  5 7 9
 1  3      10
 */
int main()
{
	int i;
	int value;
	int data[10] = {6,4,8,2,5,7,9,10,1,3};
	BST_TREE root = NULL;

	for (i = 0; i < sizeof(data)/sizeof(data[0]); i++)
	{
		addtobst(&root, data[i]);
	}
	level_order_bst(root);
	return 0;
}
