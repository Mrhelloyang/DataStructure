#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string.h>
using namespace std;
#define MaxSize 50
typedef struct {
	int data1[MaxSize];
	char data2[MaxSize];
	int length;
}SqList;//静态分配
#define InitSize 100
typedef struct {
	int* data2;
	int length;
}SeqList;//动态分配
bool ListInsert(SqList& L, int i, int x)//插入元素
{
	if (i<1 || i>L.length + 1)
		return false;
	if (L.length >= MaxSize)
		return false;
	for (int j = L.length; j >= i; j--)
	{
		L.data1[j] = L.data1[j - 1];
	}
	L.data1[i - 1] = x;
	L.length++;
	return true;
}
bool ListDelete(SqList& L, int i, int& e)//删除元素
{
	if (i<1 || i>L.length + 1)
		return false;
	e = L.data1[i - 1];
	for (int j = i; j < L.length; j++)
	{
		L.data1[j - 1] = L.data1[j];
	}
	L.length--;
	return true;
}
int LocateEleam(SqList& L, int b)//查找
{
	int i;
	for (i = 0; i < L.length; i++)
	{
		if (L.data1[i] == b)
		{
			return i + 1;
		}
	}
	return 0;
}
int main()
{
	//1.创建顺序表
	SqList L;
	int j = 30;
	int tmp[] = { 23,74,8,34,252,46,3252,235,463,756,23 };
	int len = sizeof(tmp) / sizeof(tmp[0]);
	memcpy(L.data1, tmp, sizeof(tmp));
	L.length = len;
	bool a = ListInsert(L, 5, 99);
	printf("a=%d\n", a);//a=1
	for (int i = 0; i < L.length; i++)
	{
		printf("%d,", L.data1[i]);
	}
	printf("\n");
	//23, 74, 8, 34, 252, 99, 46, 3252, 235, 463, 756, 23,
	//23, 74, 8, 34, 99, 252, 46, 3252, 235, 463, 756, 23,
	int e;
	ListDelete(L, 2, e);
	for (int i = 0; i < L.length; i++)
	{
		printf("%d,", L.data1[i]);
	}
	printf("\n");
	printf("e=%d\n", e);
	//23, 74, 8, 34, 99, 252, 46, 3252, 235, 463, 756, 23,
	//23, 8, 34, 99, 252, 46, 3252, 235, 463, 756, 23,
	//e = 74,
	int locate = LocateEleam(L, 3252);
	printf("%d,", locate);
	return 0;
}