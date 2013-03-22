#include <stdio.h>


#define  STACK_SIZE  (10)
typedef int DataType;

typedef struct stack_node
{
	DataType data;
	struct stack_node* next;
}STACK_NODE, *ptr_stack_node;

typedef struct _stack_list
{
	ptr_stack_node head;
	DataType top;
}STACK_LIST;

void init_stack_list(STACK_LIST* s)
{
	s->head = NULL;
	s->top = 0;
}

int push(STACK_LIST* s, DataType e)
{
	ptr_stack_node new;

	if (s == NULL)
		return -1;

	new = (ptr_stack_node)malloc(sizeof(STACK_NODE));
	
	if (new == NULL)
		return -1;

	new->data = e;
	new->next = s->head;
	s->head = new;
	s->top++;

	return 0;
}

int pop(STACK_LIST* s, DataType* e)
{
	ptr_stack_node p;

	if(s == NULL || s->top == 0)
		return -1;
	
	p = s->head;
	*e = p->data;
	s->head = p->next;

	free(p);
	s->top--;

	return 0;
}


void print_stack(STACK_LIST* s)
{
	int i;
	ptr_stack_node p = s->head;
	
	if (p == NULL)
	{
		printf("empty stack!\n");
		return;
	}

	while(p)
	{
		printf("%d\n", p->data);

		p = p->next;
	}
}

int main()
{
	int i;
	STACK_LIST s;
	DataType e;

	init_stack_list(&s);

	for(i = 0; i < STACK_SIZE; i++)
	{
		push(&s, rand());
	}
	print_stack(&s);

	for (i = 0; i < STACK_SIZE/2; i++)
	{
		pop(&s, &e);
		printf("pop: %d\n", e);
	}
	
	printf(">>>>>>>>>>>>>After pop<<<<<<<<<<<<<\n");

	print_stack(&s);

	return 0;

}
