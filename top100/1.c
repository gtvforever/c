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


BST_TREE head = NULL;
BST_TREE pre = NULL;

void bst_to_double_linked_list(BST_TREE root)
{
	if(root == NULL)
		return;
	bst_to_double_linked_list(root->lchild);
	root->lchild = pre;
	if(root->lchild == NULL)
	{
		head = root;
	}
	else
	{
		pre->rchild = root;
	}
	pre = root;
	bst_to_double_linked_list(root->rchild);
}

void bst_to_double_linked_list_1(BST_TREE root, BST_TREE * pre, BST_TREE* head)
{
	if(root == NULL)
	{
		return;
	}
	bst_to_double_linked_list_1(root->lchild, pre, head);
	root->lchild = *pre;
	if(*pre == NULL)
	{
		*head= root;
	}
	else
	{
		(*pre)->rchild = root;
	}
	*pre = root;
	bst_to_double_linked_list_1(root->rchild, pre, head);
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
	BST_TREE list;
	BST_TREE pre = NULL;
	BST_TREE head = NULL;
	for (i = 0; i < sizeof(data)/sizeof(data[0]); i++)
	{
		addtobst(&root, data[i]);
	}
	/* bst_to_double_linked_list(root); */
	bst_to_double_linked_list_1(root, &pre, &head);
	list = head;
	while(list != NULL)
	{
		printf("%d\n", list->key);
		list = list->rchild;
	}
	return 0;
}
