#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"stack.h"
#include"tree.h"
#include"quene.h"
using namespace std;
/*void CreateNode(BiTree &T,TElemType e) {
	T = new BiTNode;
	T->data = e;
}
void CreateTree(BiTree &T) {
	i++;
	CreateNode(T, j++);
	if (i > 10) {
		T->rchild = NULL;
		T->lchild = NULL;
	}
	else if (i % 3 == 0) {
		CreateTree(T->lchild);
		T->rchild = NULL;
	}
	else if (i % 3 == 2) {
		CreateTree(T->rchild);
		T->lchild = NULL;
	}
	else if(i%3==1){
		CreateTree(T->rchild);
		CreateTree(T->lchild);
	}
}	*/
void CreateBiTree(BiTree &T) {
	// 读入扩展的先序序列，假定数据元素为字符型，空格表示NULL
	char ch;
	ch = getchar();
//	cin >> ch;
//	scanf_s("%c", &ch);
	if (ch == ' ') T = NULL;
	else {
		T = new BiTNode; T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}
void PreOrderTraverse(BiTree T, void(*Visit)(TElemType)) {
	// Visit是函数指针，表示对数据元素所进行的访问操作
	if (T) {
		Visit(T->data);
		PreOrderTraverse(T->lchild, Visit);
		PreOrderTraverse(T->rchild, Visit);
	}
}
void Print(TElemType e) {
	cout << e << ' ';
}
void PreOrderPrint(BiTree T) {
	PreOrderTraverse(T, Print);
}
/*void PreOrderTraverse2(BiTree T, void(*Visit)(TElemType)) {
	LinkList S; BiTree p = T;
	BiTNode e;
	InitStack_L(S);
	while (p || !StackEmpty(S)) {
		if (p) {
			Visit(p->data);
			Push_L(S, *p);
			p = p->lchild;
		}
		else {
			Pop_L(S, e);
			p = &e;
			p = p->rchild;
		}
	}
}*/

/*void CopyBitree(BiTree &T, BiTree &pc) {
	LinkList S; LinkList Sc; BiTree p = T; BiTree Tc = pc;
	BiTNode e; BiTNode ec;
	InitStack_L(S); InitStack_L(Sc);
	while (p || !StackEmpty(S)) {
		if (p) {
			Tc = new BiTNode; 
			Tc->data =p->data ;
			Push_L(Sc, *Tc);
			Push_L(S, *p);
			Tc = Tc->lchild;
			p = p->lchild;
		}
		else {
			Tc = NULL;
			Pop_L(S, e); Pop_L(Sc, ec);
			p = &e; Tc = &ec;
			p = p->rchild; Tc = Tc->rchild;
		}
	}
	while (!StackEmpty(Sc))
		Pop_L(Sc, e);
	pc = &e;
}	*/
void copy(BiTree &T, BiTree &Tc) {
	if (T) {
		Tc = new BiTNode;
		Tc->data = T->data;
		copy(T->lchild, Tc->lchild);
		copy(T->rchild, Tc->rchild);
	}
	else
		Tc = NULL;
}
bool similiar(BiTree &T, BiTree &Tc) {
	if (T) {
		if (!Tc)
			return false;
		else
			return similiar(T->lchild, Tc->lchild) && similiar(T->rchild, Tc->rchild);
	}
	else {
		if (Tc)
			return false;
		else
			return true;
	}
}
/*BiTNode *ancestor(BiTNode x, BiTNode y, BiTree &T) {
	int i=0, j=0;
	BiTNode *an;
	LinkList S; BiTree p = T;
	BiTNode e;
	InitStack_L(S);
	while (p || !StackEmpty(S)) {
		if (p) {
			if (i == 1)	 j =1;
			Push_L(S, *p);			
			if (p->data == x.data || p->data == y.data) 	i ++;
			p = p->lchild;
		}
		else {
			Pop_L(S, e);
			if (j == 0)	 an = &e;
			if (i == 1)	 j=0;
			p = &e;
			p = p->rchild;
		}
	}
	if (i < 2) {
		cout << "ERROR!  can not find x or y" << endl;
		return NULL;
	}
	else
		return an;
}	*/
TElemType SearchTree(BiTree &T, int &k) {
	TElemType cl, cr;
	if (T) {
		if (k == 0)
			return T->data;
		else {
			cl = SearchTree(T->lchild, --k);
			if (cl)
				return cl;
			cr = SearchTree(T->rchild, --k);
			if (cr)
				return cr;
			return 0;
		}
	}
	else
		return 0;
}
void LayerTraverse(BiTree T, void(*Visit)(TElemType)) {
	Queue Q; BiTree p;
	InitQueue(Q);
	EnQueue(Q, T);
	while (!QueueEmpty(Q)) {
		DeQueue(Q, p);
		if (p) {
			Visit(p->data);
			EnQueue(Q, p->lchild); EnQueue(Q, p->rchild);
		}
	}
}
