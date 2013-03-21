#include <stdlib.h>
#include <stdio.h>
#define	QUEUE_SIZE (10)
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
	
	r = p->front->next;
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
	init_q_list(&head, &q);

	for (i = 0; i < QUEUE_SIZE; i++)
	{
		enqueue(&q, rand());
	}

	print_q(&q);

	for (i = 0; i < QUEUE_SIZE/2; i++)
	{
		dequeue(&q, &temp);
		printf("dequeue element is %d\n", temp);
	}

	printf(">>>>>now queue is <<<<<<<<<\n");
	print_q(&q);
}

