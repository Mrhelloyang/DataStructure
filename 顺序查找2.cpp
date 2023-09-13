#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
typedef struct {
	int tmp;
}ElemType;
typedef struct {
	ElemType* elem;
	int TableLen;
}SSTable;
int search_Seq(SSTable& ST, int key)
{
	ST.elem[0].tmp = key;
	int i;
	for (i = ST.TableLen; ST.elem[i].tmp != key; i--);
	return i;
}
int main()
{
	SSTable ST;
	ST.elem = new ElemType[20];
	int j = 19;
	for (int i = 1; i <= 19; i++)
	{
		ST.elem[i].tmp = j; //(* (ST.elem + i)).tmp = j; //(ST.elem+i)->tmp = j; 
		j--;
	}
	ST.TableLen = 19;
	int key = 7;
	int ret = search_Seq(ST, key);
	printf("ret=%d\n", ret);
	return 0;
}