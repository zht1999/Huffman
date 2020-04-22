#pragma once
#include"stack.h"
//char source[15] = { "hfmcopy.txt" };
typedef char TElemType;
typedef struct BiTNode {
	TElemType data;
	BiTNode *lchild, *rchild;
} *BiTree;
typedef LinkList QueuePtr;
typedef struct {
	QueuePtr front; // 头指针
	QueuePtr rear;  // 尾指针
} LinkQueue;
typedef unsigned int WeightType;
typedef  char TElemType;
typedef struct {
	TElemType data;
	WeightType weight; // 叶子权值的类型
	int parent, lchild, rchild; // 三叉静态链表
} HTNode, *HuffmanTree;
const unsigned int MAX_WEIGHT = UINT_MAX;
void Select(HuffmanTree HT, int s, int &l, int &r);
void CreateHuffmanTree(HuffmanTree &HT, char fc[], int fi[], int n);
void ReadFile(char fc[], int fi[], int &n,int &sum);
void HuffmanCoding(HuffmanTree HT, char **&HC, int n);
void Coding(HuffmanTree HT, char **&HC, int root, SqStack &S);
void ChangeFile(HuffmanTree HT, char **HC, int n,char name[],int &csum);
void Decoprass(HuffmanTree HT, char **HC, int n,char name2[], char name1[],int sum);
//void LayerTraverse(BiTree T);
void print(HuffmanTree HT, char **HC, int cur, int depth,int* &dep,int count);
void PrintHT(HuffmanTree HT,char **HC , int n);

