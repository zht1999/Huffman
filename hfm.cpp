#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"hfm.h"
using namespace std;
void CreateHuffmanTree(HuffmanTree &HT, char fc[], int fi[], int n) {
	int m = 2 * n - 1; // 最终将得到2n-1个结点
	int s1, s2;
	HT = new HTNode[m];
	for (int i = 0; i < n; ++i) {
		HT[i].data = fc[i]; //cout << HT[i].data << endl;
		HT[i].weight = fi[i]; //cout << HT[i].weight << endl;
		HT[i].lchild = HT[i].rchild = HT[i].parent = -1;
	}
	for (int i = n; i < m; ++i) {
		Select(HT, i - 1, s1, s2); 
		HT[s1].parent = HT[s2].parent = i; 
//		cout << s1 << '\t' << s2 << endl;
//		cout << HT[s1].data << '\t' << HT[s2].data << endl;
//		cout <<i<< HT[s1].weight << '\t' << HT[s2].weight << endl;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
		HT[i].data = 0;
		HT[i].lchild = s1; HT[i].rchild = s2; HT[i].parent = -1;
	}
}
void Select(HuffmanTree HT, int s, int &l, int &r) {
	// 本函数的作用是从HT[0..s]中找到权值最小的两个结点
	WeightType WL = MAX_WEIGHT, WR = MAX_WEIGHT;
	for (int i = 0; i <= s; ++i) {
		if (HT[i].parent == -1) {
			if (HT[i].weight < WL) {
				WR = WL; WL = HT[i].weight; r = l; l = i;
			}
			else if (HT[i].weight <= WR) {
				WR = HT[i].weight; r = i;
			}
		}
	}
}
void ReadFile(char fc[], int fi[], int &n,int &sum) {
	int count=0;
	char c;
	FILE *fp;
	errno_t err;
	err = fopen_s(&fp,"hfm.txt" , "r");
	for (int i = 0; i < n; i++) {
		fc[i] = 0;
		fi[i] = 0;
	}
	while (!feof(fp)) {
		fscanf_s(fp, "%c", &c,sizeof(char));
		sum++;
		for (int j = 0; j < n; j++) {
			if (c == fc[j]) {
				fi[j]++;
				j = n;
			}
			else if (fc[j] == 0) {
				fc[j] = c;
				fi[j]++;
				count = j+1;
				j = n;
			}
		}
	}
	fclose(fp);
	n = count;
}
void ChangeFile(HuffmanTree HT, char **HC,int n,char name[],int &csum) {
	int j = 0;
	int sign=0;
	unsigned char tc;
	unsigned char dc=0;
	FILE *tfp, *dfp;
	errno_t err;
	err = fopen_s(&tfp, "hfm.txt", "r");
	err = fopen_s(&dfp, name, "wb");
	while (!feof(tfp)) {
		fscanf_s(tfp, "%c", &tc, sizeof(char));
		for (int i = 0; i < n; i++) {
			if (tc == HT[i].data) {
				sign = i;
				i = n;
			}
		}
		for (int i = 0; HC[sign][i] ;i++,j++) {
			if (j == 8) {
//				printf("%0x\n", dc);
				fwrite(&dc, 1, 1, dfp);
				csum++;
				j = 0;
				dc = 0;
			}
			if (HC[sign][i] == '1')
				dc += 1 << (7 - j);
		}
	}
/*	for (int i=0; j < 8; j++,i++) {
		if(i%2==1)
			dc += 1 << (7 - j);
	}*/
//	fwrite(&dc, 1, 1,dfp);	
//	dc = 0;
//	fwrite(&dc, 1, 1, dfp);
	fclose(tfp);
	fclose(dfp);
}
void HuffmanCoding(HuffmanTree HT, char **&HC, int n) {
	SqStack S;
	InitStack_sq(S, 100);
	HC = (char**)malloc(sizeof(char*)*(n));
	Coding(HT, HC, 2 * n - 2, S);
}
void Coding(HuffmanTree HT, char **&HC, int root, SqStack &S) {
	char ch;
	if (root != -1) {
		if (HT[root].lchild == -1) {
			Push_sq(S, '\0');
			HC[root] = (char *)malloc((S.top+1));
			strcpy_s(HC[root],S.top+1 , S.elem);
			cout <<HT[root].data<< HC[root] << endl;
			Pop_sq(S, ch);
		}
		Push_sq(S, '0');
		Coding(HT, HC, HT[root].lchild, S);
		Pop_sq(S,ch);
		Push_sq(S, '1');
		Coding(HT, HC, HT[root].rchild, S);
		Pop_sq(S, ch);
	}
}
void Decoprass(HuffmanTree HT, char **HC, int n,char name2[],char name1[],int sum) {
	int b=0;
	unsigned char c;
	int j = 0;
	int leave = 2*n-2;
//	unsigned char s[8] ;
	unsigned char dc=0;
	FILE *tfp, *dfp;
	errno_t err;
	err = fopen_s(&tfp, name2, "w");
	err = fopen_s(&dfp, name1, "rb");
	while (!feof(dfp)&&b<sum-1) {
//		fseek(dfp, -1L, SEEK_CUR);
		fread(&dc, 1, 1, dfp);
		for (int j = 0; j < 8; j++){
			c = dc & (1 << (7 - j));
/*			if (c == 0)
				b++;
			else
				b = 0;	*/
//			printf("%d\n", c);
//			s[j] =c+'0';
//			cout << s[j] << endl;
//			s[j] = '1';
			if (c==0)
				leave = HT[leave].lchild;
			else
				leave = HT[leave].rchild;	
			if (HT[leave].lchild == -1) {
				fprintf_s(tfp, "%c", HT[leave].data);
				b++;
				leave = 2 * n - 2;
			}
		}
//		fseek(dfp, 1L, SEEK_CUR);
	}
	fclose(tfp);
	fclose(dfp);
}
void print(HuffmanTree HT, char **HC, int cur, int depth,int* &dep,int count) {
	if (HT[cur].rchild != -1) {
		print(HT,HC, HT[cur].rchild, depth + 1, dep, 0);
	}
	dep[depth] = 1;
	for (int i = 0; i < depth; i++) {
		if (dep[i + 1] == 1)
			cout << "   |";
		else
			cout << "    ";
	}
	if (HT[cur].data == '\n')
		cout << "-ENT" <<HC[cur]<< endl;
	else if (HT[cur].data == 0)
		cout << "--[ " << endl;
	else if (HT[cur].data == ' ')
		cout << "-SPA" << HC[cur] << endl;
	else if (HT[cur].data == '\t')
		cout << "-TAB" << HC[cur] << endl;
	else
		cout <<"-\""<< HT[cur].data<<"\" "<< HC[cur] << endl;
	if(count==1)
		dep[depth] = 0;
	if (HT[cur].lchild != -1) {
		print(HT, HC,HT[cur].lchild, depth + 1, dep, 1);
	}
}
void PrintHT(HuffmanTree HT, char **HC,int n) {
	int *dep;
//	int count = 0;
	dep = new int[15];
	for (int i = 0; i < 15; i++) {
		dep[i] = 0;
	}
	printf("\nPrinting the Huffman Tree*******************************************************\n");
	printf(" 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |10 |11 |12 |13 |14 |15 |\n");//树的深度  
	print(HT,HC, 2 * n - 2, 0,dep,-1);
}
