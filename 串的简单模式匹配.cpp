#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#define MaxLen 50
typedef struct {
	char ch[MaxLen];
	int length;
}SString;
typedef struct {
	char* ch;
	int length;
}HString;
int Index(SString SS, SString T)
{
	int i = 1, j = 1;
	while (i <= SS.length && j <= T.length)
	{
		if (SS.ch[i] == T.ch[j])
		{
			i++, j++;
		}
		else
		{
			i = i - j + 2, j = 1;
		}
	}
	if (j > T.length)//当匹配到最后一个时j会+1，所以j>T.length；
	{
		return i - j + 1;//i-T,length;
	}
	else
		return 0;
}
int main()
{
	SString SS;
	SS.length = 0;
	int j = 30;
	for (int i = 1; i <= 20; i++)
	{
		SS.ch[i] = j--;
		SS.length++;
	}
	for (int i = 1; i <= 20; i++)
	{
		printf("%d,", SS.ch[i]);
	}
	SString T;
	T.length = 0;
	j = 15;
	for (int i = 1; i <= 4; i++)
	{
		T.ch[i] = j--;
		T.length++;
	}
	printf("\n");
	for (int i = 1; i <= 4; i++)
	{
		printf("%d,", T.ch[i]);
	}
	int ret = Index(SS, T);
	printf("\n");
	printf("%d\n", ret);
	HString HS;
	HS.ch = (char*)malloc(50 * sizeof(char));
	HS.length = 0;
	free(HS.ch);
	return 0;
}