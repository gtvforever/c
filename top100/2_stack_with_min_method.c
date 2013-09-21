/****************************************************
*top 100 - No 2
*Design a stack with a min method in O(1) complexity
****************************************************/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE (10)
typedef enum 
{
	false,
	true,
}bool;


typedef struct _list
{
	struct _list * next;
	int key;
}List;

typedef struct stack_with_min_method
{
	List* cur;
	List* min;
}Stack;


void init_stack(Stack* s)
{
	s->cur = NULL;
	s->min = NULL;
}


bool stack_push(Stack* s, int data)
{
	List* node;
	List* min_node;
	if(s == NULL)
		return false;

	node = (List*)malloc(sizeof(List));
	node->key = data;

	if(s->cur == NULL)
	{
		min_node = (List*)malloc(sizeof(List));

		min_node->next = NULL;
		min_node->key  = data;

		node->next = NULL;
		s->cur = node;
		s->min = min_node;
	}
	else
	{
		node->next = s->cur;
		s->cur = node;

		if(data <= s->min->key)
		{		
			min_node = (List*)malloc(sizeof(List));

			min_node->next = s->min;
			min_node->key  = data;

			s->min = min_node;
		}
	}

	return true;
}


bool stack_pop(Stack* s, int* out)
{
	List* tmp;
	if(s == NULL)
		return false;

	if(s->cur == NULL)
		return false;

	*out = s->cur->key;
	if(s->cur->key == s->min->key)
	{
		tmp = s->min->next;
		free(s->min);
		s->min = tmp;
	}

	tmp = s->cur->next;
	free(s->cur);
	s->cur = tmp;

	if(s->cur == NULL)
		s->min = NULL;

	return true;
}


bool stack_top(Stack* s, int* out)
{

	if(s == NULL || s->cur == NULL)
		return false;

	*out = s->cur->key;
	return true;
}


bool get_min(Stack* s, int* out)
{
	if(s == NULL||s->min == NULL)
		return false;

	*out = s->min->key;

	return true;
}


bool stack_is_empty(Stack* s)
{
	if(s == NULL)
		return false;

	return s->cur == NULL?true:false;
}


int main()
{
	unsigned int i;
	int tmp;
	Stack s;
	int test_data[SIZE] = {7,8,6,10,5,4,12,3,13,12};
	init_stack(&s);

	for(i = 0; i < SIZE; i++)
	{
		stack_push(&s, test_data[i]);
	}

	printf(">>>>>>start to pop\n");

	while(!stack_is_empty(&s))
	{
		if(get_min(&s, &tmp))
			printf("min is %d\n", tmp);

		stack_pop(&s, &tmp);
		printf("%d\n", tmp);
	}
	return 0;
}