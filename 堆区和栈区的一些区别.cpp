#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <stdio.h>
#include<stdlib.h>
#include<ctime>
int* func(int n)
{
	int a;
	int RandomNumber;
	//int p[100];//err
	int* p = (int*)malloc(100 * sizeof(int));
	srand((unsigned)time(NULL));//time()用系统时间初始化种。为rand()生成不同的随机种子。
	while (n > 0)
	{
		n--;
		RandomNumber = rand() % 100;
		p[n] = RandomNumber;
	}
	return p;
	//函数调用完毕，这个函数的栈区变量全部释放；所以使用堆区去存放。
}
int main01()
{
	int a[100];
	int b;
	char c;
	double d;
	int* p = (int*)malloc(100 * sizeof(int)); //sizeof()测大小，malloc()是在堆区分配()大小的空间，然后(int*)强制类型转换，把地址给p
	//[]和*等价
	int t[3][3];
	*(t[2] + 2) = 10;//和t[2][2]=10等价
	printf("%d\n", t[2][2]);
	free(p);
	//new的使用
	int* p2 = new int[100];//
	p2[0] = 19;
	printf("%d\n", p2[0]);
	free(p2);
	return 0;
}
int main()
{
	int* ret = func(100);
	for (int i = 0; i < 100; i++)
	{
		printf("%d,", ret[i]);
	}
	return 0;
}