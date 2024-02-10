#include<iostream>
#include "Stack.h"
#include "Queue.h"
using namespace std;
Node* root = NULL;
void createTree() {
	int x;
	Node* t;
	Node* s;
	Queue q(50);
	cout << "Enter root value:";
	cin >> x;
	root = new Node;
	root->data = x;
	root->lchild = root->rchild = NULL;
	q.enqueue(root);
	
	while (!q.isEmpty()) {
		s = q.dequeue();
		cout << "Enter left value of " << s->data << ":";
		cin >> x;
		if (x != -1) {
			t = new Node;
			t->data = x;
			t->lchild = t->rchild = NULL;
			s->lchild = t;
			q.enqueue(t);
		}
		cout << "Enter right value of " << s->data << ":";
		cin >> x;
		if (x != -1) {
			t = new Node;
			t->data = x;
			t->lchild = t->rchild = NULL;
			s->rchild = t;
			q.enqueue(t);
		}
	}
	
}

void preorder(Node* p) {
	if (p) {
		cout << p->data << " ";
		preorder(p->lchild);
		preorder(p->rchild);
	}
}
void inorder(Node* p) {
	if (p) {
		preorder(p->lchild);
		cout << p->data << " ";
		preorder(p->rchild);
	}
}
void postorder(Node* p) {
	if (p) {
		preorder(p->lchild);
		preorder(p->rchild);
		cout << p->data << " ";
	}
}

void preorderStack(Node* t) {
	Stack st(50);
	while (t != NULL || !st.isEmpty()) {
		if (t != NULL)
		{
			cout << t->data;
			st.push(t);
			t = t->lchild;
		}
		else
		{
			t = st.pop();
			t = t->rchild;

		}

	}
}
void inorderStack(Node* t) {
	Stack st(50);
	while (t != NULL or !st.isEmpty()) {
		if (t != NULL) {
			st.push(t);
			t = t->lchild;
		}
		else
		{
			t = st.pop();
			cout << t->data;
			t = t->rchild;

		
		}
	}
}

void postorderStack(Node *t) {
	if (t == NULL)
		return;
	
	Stack s1(50);
	Stack s2(50);
	s1.push(t);

	while (!s1.isEmpty()) {
		t = s1.pop();
		s2.push(t);
		if (t->lchild != NULL)
			s1.push(t->lchild);
		
		if (t->rchild != NULL) 
			s1.push(t->rchild);
		

	}
	while (!s2.isEmpty())
	{
		t= s2.pop();
		cout << t->data<<" ";
	}

}

void levelorder(Node* p) {
	Queue q(50);
	cout << p->data << " ";
    q.enqueue(p);
	while (!q.isEmpty()) {
		p = q.dequeue();
		if (p->lchild != NULL)
		{
			cout << p->lchild->data;
			q.enqueue(p->lchild);
		}
		if (p->rchild != NULL)
		{
			cout << p->rchild->data;
			q.enqueue(p->rchild);
		}
		
	}
}
int main() {
	createTree();
	levelorder(root);
}