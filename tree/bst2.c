#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
	false = 0,
	true,
}bool;

typedef struct _bst{
	struct _bst* left;
	struct _bst* right;
	int key;
}BST,*BST_TREE;


bool search_bst(BST_TREE root, BST_TREE parent, BST_TREE* last, int value)
{
	if(root == NULL)
	{
		*last = parent;
		return false;
	}
	else if(root->key < value)
	{
		return search_bst(root->right, root, last, value);
	}
	else if(root->key > value)
	{
		return search_bst(root->left, root, last, value);
	}
	else
	{
		*last = root;
		return true;
	}
}

bool add_node_to_bst(BST_TREE* root, int value)
{
	BST_TREE new;
	BST_TREE last;
	if(!search_bst(*root, NULL, &last, value))
	{

		new = (BST_TREE)malloc(sizeof(BST));

		new->left = NULL;
		new->right = NULL;
		new->key = value;

		if(last == NULL)
		{
			*root = new;
		}
		else
		{
			if(value < last->key)
			{
				last->left = new;
			}
			else
			{
				last->right = new;
			}

		}

		return true;
	}
	
	return false;
}

/***
Delete a node from the binary search tree, the most important note you 
need to consider is when the node you want to delets is the root node
**/
bool delete_node_from_bst(BST_TREE* root, int value)
{
	BST_TREE cur, last, replace;

	if(*root == NULL)
		return false;

	cur = *root;
	last =  cur;
	while(cur != NULL && cur->key != value)
	{
		last = cur;
		if(cur->key >value)
		{
			cur = cur->left;
		}
		else
		{
			cur = cur->right;
		}
	}

	if(cur == NULL)
		return false;

	if(cur->left == NULL && cur->right == NULL)
	{
		if(cur == *root)  //if the cur is the root node
		{
			*root = NULL;
		}
		else
		{
			if(last->left == cur)
			{
				last->left = NULL;
			}
			else
			{
				last->right = NULL;
			}
		}


	}
	else if(cur->left == NULL)
	{
		if(cur == *root)  //if cur is the root node
		{
			*root = cur->right;
		}
		else
		{
			if(cur == last->right)
			{

				last->right = cur->right;
			}
			else
			{
				last->left = cur->right;
			}
		}

	}
	else if(cur->right == NULL)
	{
		if(cur == *root)  //if cur is the root node
		{
			*root = cur->left;
		}
		else
		{
			if(cur == last->right)
			{

				last->right = cur->left;
			}
			else
			{
				last->left = cur->left;
			}
		}
		
	}
	else
	{
		replace = cur;
		cur = cur->left;
		last = cur;

		while(cur->right != NULL)
		{
			last = cur;
			cur = cur->right;
		}

		replace->key = cur->key;

		if(cur == replace)
		{
			replace->left = cur->left;
		}
		else
		{
			last->right = cur->left;
		}
	}

	free(cur);
	return true;


}


void in_order(BST_TREE root)
{
	if(root == NULL)
		return;
	in_order(root->left);
	printf("%d ", root->key);
	in_order(root->right);
}

int get_node_num(BST_TREE root)
{
	int left = 0, right = 0;
	if(root->left == NULL && root->right == NULL)
		return 1;
	if(root->left != NULL)
		left = get_node_num(root->left);

	if(root->right != NULL)
		right = get_node_num(root->right);
	return 1 + left + right;
}

//get max node of a binay search tree
BST_TREE get_max_node(BST_TREE root)
{
	BST_TREE n;
	if(root == NULL)
		return NULL;

	n = root;
	while(n->right != NULL)
	{
		n = n->right;
	}
	return n;
}

//get min node of a binary search tree
BST_TREE get_min_node(BST_TREE root)
{
	BST_TREE n;

	if(root == NULL)
		return NULL;

	n = root;

	while(n->left != NULL)
	{
		n = n->left;
	}

	return n;
}

//get the 2nd max node of a binary search tree
BST_TREE get_2nd_max_node(BST_TREE root)
{
	BST_TREE n;
	BST_TREE last;
	if(root == NULL ||(root->right == NULL && root->left == NULL))
		return NULL;

	n = root;

	while(n->right != NULL)
	{
		last = n;
		n = n->right;
	}
	
	if(n->left == NULL)
	{
		return last;
	}
	else
	{
		//find the left sub tree max node
		return get_max_node(n->left);
	}
}


//get the 2nd min node of a binary search tree
BST_TREE get_2nd_min_node(BST_TREE root)
{
	BST_TREE cur,last;
	if(root == NULL ||(root->left == NULL && root->right == NULL))
		return NULL;

	cur = root;

	while(cur->left != NULL)
	{
		last = cur;
		cur = cur->left;
	}

	if(cur->right == NULL)
	{
		return last;
	}
	else
	{
		return get_min_node(root->right);
	}
}

int get_tree_depth(BST_TREE root)
{
	int left_depth, right_depth;

	if(root == NULL)
		return 0;
	
	left_depth = get_tree_depth(root->left);
	right_depth = get_tree_depth(root->right);

	return left_depth > right_depth? 1+left_depth:1+right_depth;
}

/*
get least common ancestor node from a bst
*/
BST_TREE get_lca_node(BST_TREE root, int key1,int key2)
{
	if(root == NULL)
		return NULL;

	if(root->key < key1 && root->key < key2)
	{
		return	get_lca_node(root->right, key1, key2);
	}
	else if(root->key > key1 && root->key > key2)
	{
		return get_lca_node(root->left, key1, key2);
	}
	else if(root->key == key1 || root->key == key2)
	{
		return NULL;
	}
	else
	{
		return root;
	}

}


int get_leaf_node_num(BST_TREE root)
{
	if(root == NULL)
		return 0;
	if(root->left == NULL || root->right == NULL)
		return 1;
	
	return get_leaf_node_num(root->left) + get_leaf_node_num(root->right);
}
BST_TREE pre = NULL;
BST_TREE head;
void bst_to_double_list(BST_TREE root)
{
	if(root == NULL)
	{
		return;
	}
	
	bst_to_double_list(root->left);
	if(pre == NULL)
	{
		root->left = pre;
		head = root;
	}
	else
	{
		pre->right = root;
	}
	pre = root;
	bst_to_double_list(root->right);
	return;
}

bool is_bst_tree(BST_TREE root, int min, int max)
{
	if(root == NULL)
		return true;
	if(root->key < max && root->key > min)
	{
		return is_bst_tree(root->left, min, root->key)&& is_bst_tree(root->right,root->key, max);
	}
	return false;
}

void my_mirror_bst_tree(BST_TREE root)
{
	BST_TREE tmp;
	if(root == NULL || (root->left == NULL && root->right == NULL))
		return;
	
	tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	if(root->left != NULL)
		my_mirror_bst_tree(root->left);
	
	if(root->right != NULL)
		my_mirror_bst_tree(root->right);
	
}


unsigned int get_max_distance(BST_TREE root)
{
	unsigned int left, right;
	if(root == NULL)
		return 0;
	
	left = get_tree_depth(root->left);
	right = get_tree_depth(root->right);

	return left + right + 1;
}


int main()
{
	int data[12] = {6,2,8,1,4,7,9,0,3,5,11,10};
	int i;
	BST_TREE root = NULL;
	BST_TREE t;
	printf("BST create/search/delete demo\n");
	for(i = 0; i < sizeof(data)/sizeof(data[0]); i++)
	{
		add_node_to_bst(&root, data[i]);
	}
	printf("in order:\n ");
	in_order(root);
	printf("\n");

	delete_node_from_bst(&root, 5);
	printf("in order:\n ");
	in_order(root);
	printf("\n");
	printf("root left is %d\n", root->right->right->key);

	my_mirror_bst_tree(root);
	printf("in order:\n ");
	in_order(root);
	printf("\n");
	
	t = get_max_node(root);
	printf("the max node key is %d\n", t->key);
	t = get_min_node(root);
	printf("the min node key is %d\n", t->key);

	t = get_2nd_max_node(root);
	printf("the 2nd max node key is %d\n", t->key);

	t = get_2nd_min_node(root);
	printf("the 2nd min node key is %d\n", t->key);

	printf("tree depth is %d\n", get_tree_depth(root));
	
	printf("max length is %d\n", get_max_distance(root));
	printf("tree node number is %d\n", get_node_num(root));

	printf("leaf node num is %d\n", get_leaf_node_num(root));
	t = get_lca_node(root, 0,3);
	if(t != NULL)
		printf("lca node of 7, 11 is %d\n", t->key);
	else
		printf("No lca node found\n");

	bst_to_double_list(root);
	printf("%d %d %d\n",root->key, root->left->key, root->right->key);
	/* while(head != NULL)           */
	/* {                             */
	/*     printf("%d ", head->key); */
	/*     head = head->right;       */
	/* }                             */
	/* printf("\n");                 */
	printf("root is a bst tree? %s\n", is_bst_tree(root, -100, 200)?"true":"false");
	return 0;
}
