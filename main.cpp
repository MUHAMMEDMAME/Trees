#include<iostream>
#include "Queue.h"
using namespace std;
Node* root = NULL;
void createTree() {
	Node* t=0, * p=0;
	int x=0;
	Queue q;
	create(&q, 50);
	printf("Enter root value:");
	root = (Node*)malloc(sizeof(Node));
	scanf_s("%d", &x);
	root->data = x;
	root->lchild = root->rchild = NULL;
	enqueue(&q, root);
	while (!isEmpty(q)) {
		p = dequeue(&q);
		printf("Enter left child of %d", p->data);
		scanf_s("%d", &x);
		if (x != -1) 
		{
			t = (Node*)malloc(sizeof(Node));
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->lchild = t;
			enqueue(&q, t);

		}
		printf("Enter right child of %d", p->data);
		scanf_s("%d", &x);
		if (x != -1)
		{
			t = (Node*)malloc(sizeof(Node));
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->rchild = t;
			enqueue(&q, t);

		}

	}



}

void preorder(Node *p ,int depth=0,char prefix='-') {
	if (p) {


		// Print the current node
		for (int i = 0; i < depth; ++i)
			cout << "  "; 
		  cout << prefix << " " << p->data << endl;

		// Print left subtree
	preorder(p->lchild, depth + 1, 'L');

	// Print right subtree
		preorder(p->rchild, depth + 1, 'R');
	}
}
int main(){
	createTree();
	preorder(root);
}