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

BOOL removefrombst(BST_TREE* root, int data)
{
	BST_TREE last, p, q, r, s, t;

	if(*root == NULL)
	{
		/* *last = parent; */
		return FALSE;
	}
	p = *root;
	while(p != NULL && p->key != data)
	{
		q = p;
		if (p->key > data)
		{
			p = p->lchild;
		}
		else
		{
			p = p->rchild;
		}
	}

	if(p == NULL)  //We don't found a node which key equal to data;
		return FALSE;

	if(p->lchild == NULL && p->rchild == NULL)  //leaf node;
	{
		if(p == *root)
		{
			*root = NULL;
		}
		else if(q->lchild == p)
		{
			q->lchild = NULL;
		}
		else
		{
			q->rchild = NULL;
		}
		free(p);

	}
	else if (p->lchild == NULL || p->rchild == NULL)
	{
		if(p == *root && p->lchild == NULL)
		{
			*root = p->rchild;
		}
		else if (p == *root && p->rchild == NULL)
		{
			*root = p->lchild;
		}
		else if (q->lchild == p && p->lchild == NULL)
		{
			q->lchild = p->rchild;
		}
		else if (q->lchild == p && p->rchild == NULL)
		{
			q->lchild = p->lchild;
		}	
		else if(q->rchild == p && p->lchild == NULL)
		{
			q->rchild = p->rchild;
		}
		else
		{
			q->rchild = p->lchild;
		}

		free(p);
	}
	else
	{
		r = p->lchild;
		s = r;

		while(r->rchild != NULL)
		{
			s = r;
			r = r->rchild;
		}

		p->key = r->key;
		
		if(s == p->lchild)
		{
			p->lchild = r->lchild;
		}
		else
		{
			s->rchild = r->lchild;
		}
		free(r);
	}

	return TRUE;
}

BOOL get_max_node_key(BST_TREE root, int* buf)
{
	BST_TREE p;
	if(root == NULL || buf == NULL)
		return FALSE;

	while(p->rchild != NULL)
	{
		p = p->rchild;
	}
	
	*buf = p->key;
	
	return TRUE;
}

BOOL get_min_node_key(BST_TREE root, int* buf)
{
	BST_TREE p;
	if(root == NULL || buf == NULL)
		return FALSE;

	while(p->lchild != NULL)
	{
		p = p->lchild;
	}
	
	*buf = p->key;
	
	return TRUE;
}


BOOL get_second_max_node(BST_TREE root, BST_TREE* sec_node)
{
	BST_TREE p, q, s;
	
	if(root == NULL || (root->lchild == NULL && root->rchild == NULL))
		return FALSE;

	p = root;
	q = p;
	while(p->rchild != NULL)
	{
		q = p;
		p = p->rchild;
	}
	if(p->lchild == NULL)
	{
		*sec_node = q;
	}
	else
	{
		s = p->lchild;
		while(s->rchild)
		{
			s = s->rchild;
		}
		*sec_node = s;
	}
	
	return TRUE;
}


BOOL get_second_min_node(BST_TREE root, BST_TREE* sec_node)
{
	BST_TREE p, q, s;
	if(root == NULL || (root->lchild == NULL && root->rchild == NULL))
		return FALSE;

	p = root;
	q = p;

	while(p->lchild != NULL)
	{
		q = p;
		p = p->lchild;
	}
	if(p->rchild == NULL)
	{
		*sec_node = q;
	}
	else
	{
		s = s->rchild;

		while(s->lchild)
		{
			s = s->lchild;
		}
		*sec_node = s;
	}
	return TRUE;
}

BOOL get_min_node(BST_TREE root, BST_TREE* min_node)
{
	BST_TREE p;
	if(root == NULL)
		return FALSE;

	while(p->lchild != NULL)
	{
		p = p->lchild;
	}

	*min_node = p;

	return TRUE;
}

int count = 0;
int found_k_node(BST_TREE root, int k, int* out)
{
	if(root == NULL || k < 1)
		return 0;

	found_k_node(root->rchild, k, out);
	
	count++;
	
	if(count == k)
	{
		*out = root->key;
		return 0;
	}
	found_k_node(root->lchild, k, out);

	if (count < k)
		return -1;
	else
		return 0;
}


BST_TREE pre = NULL;
BST_TREE head;

void convert(BST_TREE p)
{
	p->lchild = pre;

	if(p->lchild == NULL)
	{
		head = p;
	}
	else
	{
		pre->rchild = p;
	}
	pre = p;
}

/*********************************
  Convert a bst to double-linked list
*********************************/
void in_order(BST_TREE root)
{
	if(root == NULL)
		return;

	in_order(root->lchild);

	convert(root);
	
	in_order(root->rchild);
}


int main()
{
	int i;
	int value;
	int data[10] = {6,4,8,2,5,7,9,10,1,3};
	BOOL status;
	BST_TREE root = NULL;

	for (i = 0; i < sizeof(data)/sizeof(data[0]); i++)
	{
		status = addtobst(&root, data[i]);
	}
	/* found_k_node(root, 8, &value); */
	/* tree_to_double_list(root); */
	in_order(root);
	printf("%d\n", head->key);

	return 0;
}
