#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX (10)
typedef enum 
{
	false,
	true,
}bool;


typedef struct _list
{
	struct _list* next;
	unsigned int key;
}List;


typedef struct mystack
{
	List* cur;
}STACK;



void init_stack(STACK* s)
{
	s->cur = NULL;
}



bool stack_push(STACK* s, unsigned int value)
{
	if(s == NULL)
		return false;
	List* node = (List*)malloc(sizeof(List));

	node->key = value;
	node->next = s->cur;

	s->cur = node;
	return true;
}


bool stack_pop(STACK * s, unsigned int* out)
{
	List* current;
	if(s == NULL || s->cur == NULL)
		return false;

	*out = s->cur->key;
	current = s->cur;
	s->cur = current->next;
	free(current);
	return true;
}


bool stack_top(STACK* s, unsigned int* out)
{
	if(s == NULL)
		return false;

	*out = s->cur->key;
	return true;
}


bool stack_is_empty(STACK* s)
{
	if(s == NULL)
		return false;

	return s->cur == NULL? true:false;
}


int main()
{
	STACK s;
	unsigned int i;
	unsigned int tmp;
	init_stack(&s);

	for(i = 0; i < MAX; i++)
	{
		tmp = rand();
		printf("%d\n", tmp);
		stack_push(&s, tmp);
		stack_top(&s, &tmp);
	}
	printf(">>>>>>start to pop\n");
	while(!stack_is_empty(&s))
	{
		stack_pop(&s, &tmp);
		printf("%d\n", tmp);
	}
}
