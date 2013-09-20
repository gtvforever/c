#include <stdio.h>
#define QUEUE_SIZE    (10)

typedef unsigned int ElementType;

typedef struct _queue_array
{
	ElementType data[QUEUE_SIZE];
	int front;
	int rear;
}QUEUE;


typedef enum 
{
	false,
	true,
}bool;


bool queue_init(QUEUE* q)
{
	if (q == NULL)
		return false;

	q->front = 0;
	q->rear = 0;

	return true;	
}


int get_queue_length(QUEUE* q)
{
	if (q == NULL)
		return -1;

	return (q->rear - q->front + QUEUE_SIZE)%QUEUE_SIZE;
}


bool en_queue(QUEUE* q, ElementType e)
{
	if (q == NULL)
		return false;

	if ((q->rear + 1)%QUEUE_SIZE == q->front)
	{
		printf("queue is full\n");
		return false;
	}

	q->data[q->rear] = e;
	q->rear = (q->rear + 1)%QUEUE_SIZE;

	return true;
}


int de_queue(QUEUE* q, ElementType * e)
{
	if (q == NULL)
		return false;

	if (q->rear == q->front)
	{
		printf("queue is empty\n");
		return false;
	}

	*e = q->data[q->front];
	q->front = (q->front + 1)%QUEUE_SIZE;

	return true;
}


bool queue_is_empty(QUEUE* q)
{
	if(q == NULL)
		return false;

	return q->rear == q->front?true:false;
}


int main()
{
	ElementType i, j;
	QUEUE q;

	queue_init(&q);

	for(i = 0; i < QUEUE_SIZE - 1; i++)
	{
		en_queue(&q, rand());
	}

	for(i = 0; i < QUEUE_SIZE - 1; i++)
	{
		printf("%d\n", q.data[i]);
	}

	for(i = 0; i < QUEUE_SIZE - 6; i++)
	{
		de_queue(&q, &j);
	}
	printf("\nfront is %d, rear is %d\n", q.front, q.rear);
	printf("\nleft queue length is %d\n\n", get_queue_length(&q));
	for(i = q.front; i < q.rear - 1; i++)
	{
		printf("%d\n", q.data[i]);
	}
}
