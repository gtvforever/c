#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#define	STACK_SIZE   (20)

typedef unsigned int DATATYPE;

typedef struct _stack
{
	DATATYPE array[STACK_SIZE];
	unsigned int top;
}STACK;


int push(STACK* s, DATATYPE data)
{
	if (s->top == STACK_SIZE -1)
	{
		return -1;
	}

	s->array[++s->top] = data;

	return 0;
}

int pop(STACK * s, DATATYPE* out)
{
	if(s == NULL || s->top == -1)
	{
		return  -1;
	}

	*out = s->array[s->top--];

	return 0;
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

	for (i =0 ; i < STACK_SIZE; i++)
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
