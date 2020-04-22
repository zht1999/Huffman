# pragma once
typedef int ElemType;
typedef struct {
	ElemType *elem; // 基地址
	int queuesize;  // 当前分配内存大小
	int rear, length; // 保留front或者rear之一即可
} SqQueue;
void EnQueue_sq(SqQueue &Q, ElemType e);
ElemType DeQueue_sq(SqQueue &Q, ElemType &e);
void InitQueue_sq(SqQueue &Q, int msize);
bool QueueFull(SqQueue &Q);

