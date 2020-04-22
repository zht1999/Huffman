# pragma once
typedef int ElemType;
typedef struct {
	ElemType *elem; // ����ַ
	int queuesize;  // ��ǰ�����ڴ��С
	int rear, length; // ����front����rear֮һ����
} SqQueue;
void EnQueue_sq(SqQueue &Q, ElemType e);
ElemType DeQueue_sq(SqQueue &Q, ElemType &e);
void InitQueue_sq(SqQueue &Q, int msize);
bool QueueFull(SqQueue &Q);

