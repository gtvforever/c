#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


typedef struct
{
	List* rear;
	List* front;
}Queue;


void init_queue(Queue* q)
{
	q->rear = NULL;
	q->front = NULL;
}


bool enqueue(Queue* q, int value)
{
	if(q == NULL)
		return false;
	List* node;

	node =(List*)malloc(sizeof(List));
	node->key = value;
	node->next = NULL;

	if(q->front == NULL)
	{
		q->front = node;
	}
	else
	{
		q->rear->next = node;
	}

	q->rear = node;

	return true;
}
 
bool dequeue(Queue* q, int* out)
{
	List* tmp;
	if(q == NULL)
		return false;
	if(q->front == NULL)
		return false;

	*out = q->front->key;
	
	tmp = q->front;
	q->front = tmp->next;
	if(q->front == NULL)
		q->rear = NULL;

	free(tmp);
	
	return true;
}


bool queue_is_empty(Queue* q)
{
	if(q == NULL)
		return false;

	return q->front == NULL?true:false;
}


int main()
{
	Queue q;
	unsigned int i;
	unsigned int tmp;
	init_queue(&q);

	for(i = 0; i < SIZE; i++)
	{
		tmp = rand();
		printf("%d\n", tmp);
		enqueue(&q, tmp);
	}

	printf(">>>>>>start dequeue\n");

	// while(!queue_is_empty(&q))
	// {
	// 	dequeue(&q, &tmp);
	// 	printf("%d\n", tmp);
	// }
	for(i = 0; i < SIZE - 1; i++)
	{
		dequeue(&q, &tmp);
		printf("%d\n", tmp);
	}
	printf("%d %d\n", q.front->key, q.rear->key);
	return 0;
}