#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#define	STACK_SIZE   (20)

typedef unsigned int DATATYPE;

typedef enum 
{
	false,
	true,
}bool;


typedef struct _stack
{
	DATATYPE array[STACK_SIZE];
	unsigned int top;
}STACK;


bool push(STACK* s, DATATYPE data)
{
	if (s->top == STACK_SIZE - 1)
	{
		return false;
	}

	s->array[++s->top] = data;

	return true;
}


bool pop(STACK * s, DATATYPE* out)
{
	if(s == NULL || s->top == false)
	{
		return false;
	}

	*out = s->array[s->top--];

	return true;
}	



bool stack_is_empty(STACK* s)
{
	if(s == NULL)
		return false;

	return s->top == -1?:true:false;
}


bool stack_top(STACK* s, DATATYPE* out)
{
	if(s == NULL || s->top == -1)
		return false;

	*out = s->data[s->top];
	return true;
}


void init_stack(STACK* s)
{
	s->top = -1;
}


int main()
{
	int i;
	DATATYPE r;
	STACK s;

	init_stack(&s);

	for (i = 0 ; i < STACK_SIZE; i++)
	{
		r = rand();
		printf("%d\n", r);
		push(&s, r);
	}
	printf(">>>>>>>>>>>>>>>>>start pop<<<<<<<<<<<<<<<\n");

	for(i = 0; i < STACK_SIZE; i++)
	{
		pop(&s, &r);
		printf("%d\n", r);
	}
}
