#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include "quene.h"
using namespace std;
/*typedef struct {
	ElemType *elem; // ����ַ
	int queuesize;  // ��ǰ�����ڴ��С
	int rear, length; // ����front����rear֮һ����
} SqQueue;	*/
void EnQueue_sq(SqQueue &Q, ElemType e) {
	if (QueueFull(Q))return;//Increment(Q);
	Q.elem[Q.rear] = e;
	Q.rear = (Q.rear + 1) % Q.queuesize;
	Q.length++;
//	cout << Q.length << endl;
}
ElemType DeQueue_sq(SqQueue &Q, ElemType &e) {
	if (!Q.length) {
		cout << "ERROR! EMPTY QUEUE!" << endl;
		return -1;
	}
	e = Q.elem[(Q.rear-Q.length+Q.queuesize)%Q.queuesize]; 
	Q.length--;
//	Q.front = (Q.front + 1) % Q.queuesize;
	return Q.elem[(Q.rear - Q.length+Q.queuesize)%Q.queuesize]; ;
}
void InitQueue_sq(SqQueue &Q, int msize) {
	Q.elem = new ElemType[msize];
	Q.queuesize = msize;
	Q.length = Q.rear = 0;
}
bool QueueFull(SqQueue &Q) {
	return Q.length == Q.queuesize;
}
