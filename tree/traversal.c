#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_SIZE (20)
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

void init_stack(STACK* s)
{
	s->top = -1;
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


int main()
{
	int i;
	int value;
	int data[11] = {6,4,8,2,5,7,9,10,1,3,0};
	BST_TREE root = NULL;
	BST_TREE lca;
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
	
	return 0;
}
