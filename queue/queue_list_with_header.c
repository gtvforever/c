#include <stdlib.h>
#include <stdio.h>
#define	QUEUE_SIZE (10)

#define USE_MY_QUEUE (1)
typedef int DataType;

typedef struct qnode {
	DataType data;
	struct qnode*  next;
}Q_NODE, *P_Q_NODE;


typedef struct qlist{
	P_Q_NODE rear;
	P_Q_NODE front;
}Q_LIST;


void print_q(Q_LIST* q)
{
	Q_LIST * p = q;
	P_Q_NODE r;
	if (p == NULL || p->front == p->rear)
	{
		printf("invalid queue\n");
		return;
	}
#if USE_MY_QUEUE
	r = p->front;
#else
	r = p->front->next;
#endif
	while (r != NULL)
	{
		printf("%d\n", r->data);

		r = r->next;
	}
}
void init_q_list(Q_NODE * head, Q_LIST * q)
{
	head->next = NULL;
	q->rear = head;
	q->front = head;
}

void init_q(Q_LIST* q)
{
	q->rear = q->front = NULL;
}

void enqueue1(Q_LIST* q, DataType e)
{
	P_Q_NODE new;

	new = (P_Q_NODE)malloc(sizeof(Q_NODE));
	new->data = e;
	new->next = NULL;
	if(q->front == NULL)
	{
		q->front = q->rear = new;
	}
	else
	{
		q->rear->next = new;
		q->rear = new;
	}
}

int dequeue1(Q_LIST* q, DataType * out)
{
	P_Q_NODE tmp;
	if(q->front == NULL)
		return -1;
	tmp = q->front->next;
	*out = q->front->data;
	free(q->front);
	q->front = tmp;

	return 0;
}
int enqueue(Q_LIST* q, DataType e)
{
	P_Q_NODE n;

	n = (P_Q_NODE)malloc(sizeof(Q_NODE));

	if (n == NULL)
		return -1;
	n->data = e;
	n->next = NULL;
	q->rear->next = n;

	q->rear = n;

	return 0;
}

int dequeue(Q_LIST* q, DataType* e)
{
	P_Q_NODE temp;

	if (q->front == q->rear)
		return -1;
	temp = q->front->next;

	*e = temp->data;

	q->front->next = temp->next;

	if (q->rear == temp)
		q->rear = q->front;

	free(temp);

	return 0;


}
int main()
{
	Q_NODE head;
	Q_LIST q;
	int i;
	DataType temp;
#if USE_MY_QUEUE
	init_q(&q);
#else
	init_q_list(&head, &q);
#endif
	for (i = 0; i < QUEUE_SIZE; i++)
	{
#if USE_MY_QUEUE
		enqueue1(&q, rand());
#else
		enqueue(&q, rand());
#endif
	}

	print_q(&q);

	for (i = 0; i < QUEUE_SIZE/2; i++)
	{
#if USE_MY_QUEUE
		dequeue1(&q, &temp);
#else
		dequeue(&q, &temp);
#endif
		printf("dequeue element is %d\n", temp);
	}

	printf(">>>>>now queue is <<<<<<<<<\n");
	print_q(&q);
}

