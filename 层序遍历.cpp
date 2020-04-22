#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"hfm.h"
using namespace std;
void InitQueue_L(LinkQueue &Q) {
	Q.front = Q.rear = new LNode;
	Q.front->next = NULL;
}
bool QueueEmpty_L(LinkQueue Q) {
	return Q.front == Q.rear;
	// 或者 return Q.front->next == NULL;
}
void EnQueue_L(LinkQueue &Q, ElemType e) {
	QueuePtr p = new LNode;
	p->data = e; p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
}
bool DeQueue_L(LinkQueue &Q, ElemType &e) {
	if (QueueEmpty_L(Q)) return false;
	QueuePtr p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p) Q.rear = Q.front; // 注意：队列变空特殊处理
	delete p; return true;
}

/*void LayerTraverse(HuffmanTree T) {
	char e;
	int n = 13;
	int sum = 0;
	LinkQueue Q; Tree p;
	InitQueue_L(Q);
	if(!T)
		EnQueue_L(Q, T->data);
	else
		EnQueue_L(Q, ' ');
	while (!QueueEmpty_L(Q)) {
		DeQueue_L(Q, e);
		for (int i = 0; i < pow(2, n); i++)
			cout << ' ';
		cout << e;
		sum++;
		if(!p->lchild)
			EnQueue_L(Q, p->lchild->data);
		else
			EnQueue_L(Q, ' ');
		if(!p->rchild)
			EnQueue_L(Q, p->rchild->data);
		else
			EnQueue_L(Q, ' ');
		if (sum == pow(2, 13 - n)) {
			n--;
			cout << endl;
		}
	}
}	*/
