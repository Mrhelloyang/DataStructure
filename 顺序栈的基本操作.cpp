#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#define MaxSize 50
typedef struct {
	int data[MaxSize];
	int top;//栈顶指针
}SqStack;
void InitStack(SqStack& S)
{
	S.top = -1;
}
bool StackEmpty(SqStack& S)
{
	if (S.top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool push(SqStack& S, int x)
{
	if (S.top == MaxSize - 1)
		return false;
	//S.top++;
	//S.data[S.top] = x;
	S.data[++S.top] = x;
	return true;
}
bool Pop(SqStack& S, int& x)
{
	if (S.top == -1)
		return false;
	x = S.data[S.top--];
	return true;
}

int main()
{
	SqStack S;
	InitStack(S);
	int x;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &x);
		push(S, x);
	}
	int tmp;
	for (int i = 0; i < 10; i++)
	{
		Pop(S, tmp);
		printf("%d\n", tmp);
	}
	return 0;
}