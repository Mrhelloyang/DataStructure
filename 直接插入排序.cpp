#include<iostream>
using namespace std;
typedef struct {
	int key;
	char a;//其他数据项
}RedType;
typedef struct {
	RedType r[21];//r[0]放哨兵；
	int Length;
}SqList;
void InsertSort(SqList& A, int Length)
{
	int i, j;
	for (i = 2; i <= Length; i++)
	{
		if (A.r[i].key < A.r[i - 1].key)
		{
			A.r[0] = A.r[i];
			for (j = i - 1; A.r[0].key < A.r[j].key; --j)
				A.r[j + 1] = A.r[j];
			A.r[j + 1] = A.r[0];
		}
	}
}
int main()
{
	SqList ST;
	int j = 19;
	for (int i = 1; i <= 20; i++)
	{
		ST.r[i].key = j;

		j--;
	}
	ST.Length = 20;
	InsertSort(ST, ST.Length);
	for (int i = 1; i <= 20; i++)
	{
		printf("%d,", ST.r[i].key);
	}
	return 0;
}