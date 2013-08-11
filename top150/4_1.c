/*
TOP150 4.1
Implement a function to check if a tree is balanced.
*/
#define MAX(A,B) (((A) > (B))?(A):(B))
#define MIN(A,B) (((A) < (B))?(A):(B))
typedef struct _tree
{
	struct _tree * left, *right;
	int key;
}TREE;

int max_depth(TREE* root)
{
	if(root == NULL)
		return 0;

	return 1 + MAX(max_depth(root->left), max_depth(root->right));
}

int min_depth(TREE* root)
{

	if(root == NULL)
		return 0;

	return 1 + MIN(max_depth(root->left), max_depth(root->right));
}

bool is_balance(TREE* root)
{
	int dis;
	if(root == NULL)
		return true;
	
	dis = max_depth(root) - min(root);
	if (dis > 1)
		return false;

	return is_balance(root->left)&&is_balance(root->right);

	
}
