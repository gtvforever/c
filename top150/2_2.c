/*
top150 2.2

**/

typedef struct _node {

	struct _node * next;
	int data;
}Node;


Node* get_nth_node(Node* head, unsigned int k)
{
	Node* p, *q;
	
	if (head == NULL || k < 1)
		return NULL;

	p = q = head;
	while(p && k > 0)
	{
		p = p->next;
		k--;
	}

	if(p != NULL)
	{
		while(p)
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
