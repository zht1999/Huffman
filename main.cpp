#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"hfm.h"
using namespace std;
int main() {
	int sum = 0,csum=0;
	HuffmanTree HT=NULL;
	char c;
	char name1[15] = { 0 }, name2[15] = { 0 };
	char **HC=NULL;
	int n = 128;
	char fc[128];
	int fi[128];
	while (1) {
		cout << "**************************************************" << endl;
		cout << "A:Create Huffman Code\nB:Comprass Document\nC:Decomprass Document\nE:End" << endl;
		cout << "**************************************************" << endl;
		cout << "Please enter to choose" << endl;
		cin >> c;
		switch (c) {
		case 'A':
			ReadFile(fc, fi, n,sum);
/*				for (int i = 0; i < 128; i++) {
					cout <<i<< fc[i] << '\t' << fi[i] << endl;
				}	
				*/
				//	cout << n << endl;
			CreateHuffmanTree(HT, fc, fi, n);
			HuffmanCoding(HT, HC, n);
			PrintHT(HT, HC, n);
			cout << "create success!" << endl;
			break;
		case 'B':
			if (HT && HC) {
				cout << "enter the new file name(dont enter space)" << endl;
				cin >> name1;
				ChangeFile(HT, HC, n,name1,csum);
				cout << "comprass success!" <<  endl;
				cout << "Ñ¹Ëõ±È" << (double)csum / sum << endl;
			}
			else
				cout << "Tree Empty!" << endl;
			break;
		case 'C':
			if (HT && HC&&name1[0]) {
				cout << "enter the new file name(dont enter space)" << endl;
				cin >> name2;
				Decoprass(HT, HC, n,name2,name1,sum);
				cout << "decomprass success!" <<  endl;
			}
			else
				cout << "Tree Empty!" << endl;
			break;
		case 'E':
			return 0;
		default:
			cout << "Enter Error!" << endl;
			break;
		}
	}
	system("pause");
}