#pragma once
#ifndef Queue_h
#define Queue_h
struct Node {
	Node* lchild;
	int data;
	Node* rchild;
};

struct Queue {
	int size;
	int front;
	int Rear;
	Node ** Q;
};
void create(Queue* q, int size) {
	q->size = size;
	q->front = q->Rear = -1;
	q->Q = (Node**)malloc(sizeof(Node *)* q->size);
}
void enqueue(Queue* q, Node *x) {
	if (q->Rear == q->size - 1)
		printf("queue is full\n");
	else
	{
		q->Rear++;
		q->Q[q->Rear] = x;

	}

}
Node * dequeue(Queue* q) {
	Node * x = NULL;
	if (q->Rear==q->front)
		return x;
	else {
		q->front++; 
		x = q->Q[q->front];
	}
	return x;
}
bool isEmpty(Queue q){
	return q.Rear==q.front;
}

#endif // !Queue_h

