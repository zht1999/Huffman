#pragma once
typedef char TElemType;
typedef struct BiTNode {
	TElemType data;
	BiTNode *lchild, *rchild;
} *BiTree;
void CreateBiTree(BiTree &T);
void PreOrderTraverse(BiTree T, void(*Visit)(TElemType));
void Print(TElemType e);
void PreOrderPrint(BiTree T);
//void PreOrderTraverse2(BiTree T, void(*Visit)(TElemType));
//void CopyBitree(BiTree &T, BiTree &Tc);
void copy(BiTree &T, BiTree &Tc);
bool similiar(BiTree &T, BiTree &Tc);
//TElemType ancestor(TElemType x, TElemType y, BiTree &T);
TElemType SearchTree(BiTree &T, int &k);
//BiTNode *ancestor(BiTNode x, BiTNode y, BiTree &T);

