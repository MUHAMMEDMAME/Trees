#pragma once
#ifndef Queue_h
#include "Queue.h"
#define Queue_h

class Stack {
private:
	int size;
	int top;
	Node** s;
public:
	Stack(int size);
	void push(Node* x);
	Node* pop();
	bool isEmpty();
};

Stack::Stack(int size) {
	this->size = size;
	top = -1;
	s = new Node * [sizeof(size)];

}
void Stack::push(Node* x) {
	if (top == size)
		printf("Stack is full\n");
	else
	{
		top++;
		s[top] = x;

	}
}

Node* Stack::pop() {
	Node* x = NULL;
	if (top == -1)
		printf("Stack is empty\n");
	else
	{
		x = s[top];
		top--;
	}
	return x;
}

bool Stack::isEmpty() {
	return top == -1;
}

#endif // !Queue_h

