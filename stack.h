#pragma once
typedef char ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}*LinkList;
typedef LinkList LinkStack;
typedef struct {
	ElemType *elem; // 基地址
	int stacksize;  // 当前分配内存大小，单位是sizeof(ElemType)
	int top;        // 栈顶位置，定义为表长-1
} SqStack;
const int SQSTACK_INC_SIZE = 10;
void InitStack_L(LinkStack &S);
void DestroyStack_L(LinkStack &S);
bool GetTop_L(LinkStack S, ElemType &e);
void Push_L(LinkStack &S, ElemType e);
bool Pop_L(LinkStack &S, ElemType &e);
void InitStack_sq(SqStack &S, int msize);
void DestroyStack_sq(SqStack &S);
void Push_sq(SqStack &S, ElemType e);
bool Pop_sq(SqStack &S, ElemType &e);
//bool StackEmpty(LinkList &S);
