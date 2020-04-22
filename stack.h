#pragma once
typedef char ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}*LinkList;
typedef LinkList LinkStack;
typedef struct {
	ElemType *elem; // ����ַ
	int stacksize;  // ��ǰ�����ڴ��С����λ��sizeof(ElemType)
	int top;        // ջ��λ�ã�����Ϊ��-1
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
