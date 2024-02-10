#pragma once
#ifndef Queue_h
#define Queue_h
class Node {
public:
	Node* lchild;
	int data;
	Node* rchild;
};

class Queue {
private:
	int size;
	int front;
	int rear;
	Node** Q;
public:
	Queue(int size);
	void enqueue(Node* x);
	Node* dequeue();
	bool isEmpty();
};
Queue::Queue(int size) {
	this->size = size;
	front = rear = -1;
	Q = new Node * [sizeof(size)];
}
void Queue::enqueue(Node* x) {
	if (rear == size)
		printf("Queue is full\n");
	else
	{
		rear++;
		Q[rear] = x;

	}
}
Node* Queue::dequeue() {
	Node* x = NULL;
	if (rear == front)
		return x;
	else
	{
		front++;
		x = Q[front];
	}

	return x;
}
bool Queue::isEmpty() {
	return front == rear;
}

#endif // !Queue_h

