#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
void HeadAdjust(int A[], int k, int len)
{
	A[0] = A[k];
	for (int i = 2 * k; i <= len; i *= 2)
	{
		if (i < len && A[i] < A[i + 1])
			i++;
		if (A[0] >= A[i])
			break;
		else
		{
			A[k] = A[i];
			k = i;
		}
	}
	A[k] = A[0];

}
void BuildMaxHeap(int A[], int len)
{
	for (int i = len / 2; i > 0; i--)
		HeadAdjust(A, i, len);
}
void HeadSort(int A[], int len)
{
	BuildMaxHeap(A, len);
	for (int i = len; i > 1; i--)
	{
		swap(A[i], A[1]);
		HeadAdjust(A, 1, i - 1);
	}

}
int main()
{
	int A[] = { NULL,23,21,62,24,23,26,43,14,28,8,9,19,11 };
	//BuildMaxHeap(A, 13);
	//for (int i = 1; i <= 13; i++)
	//{
	//	printf("%d ", A[i]);
	//}
	HeadSort(A, 13);
	//printf("\n");
	for (int i = 1; i <= 13; i++)
	{
		printf("%d ", A[i]);
	}
	return 0;
}
//62 28 43 24 23 26 23 14 21 8 9 19 11
//8 9 11 14 19 21 23 23 24 26 28 43 62
//8 9 11 14 19 21 23 23 24 26 28 43 62