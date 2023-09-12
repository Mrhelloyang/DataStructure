#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
typedef struct {
	int* elem;
	int TableLen;
}SSTable;
int search_Seq(SSTable& ST, int key)
{
	ST.elem[0] = key;
	int i;
	for (i = ST.TableLen; ST.elem[i] != key; i--);
	printf("ret=%d\n", i);
	return i;
}
int main()
{
	SSTable ST;
	ST.elem = new int[20];
	for (int i = 1; i <= 10; i++)
	{
		ST.elem[i] = i;
	}
	ST.TableLen = 10;
	int key = 4;
	int ret = search_Seq(ST, key);
	printf("ret=%d\n", ret);
	return 0;
}