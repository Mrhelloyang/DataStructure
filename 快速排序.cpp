#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int partition(int A[], int low, int high)
{
	int pivot = A[low];
	while (low < high)
	{
		while (low < high && A[high] >= pivot) --high;
		A[low] = A[high];
		while (low < high && A[low] <= pivot) low++;
		A[high] = A[low];
	}
	A[low] = pivot;
	return low;//return high;
}
void QuickSort(int A[], int low, int high)
{
	if (low < high)
	{
		int pivotpos = partition(A, low, high);
		QuickSort(A, low, pivotpos - 1);
		QuickSort(A, pivotpos + 1, high);
	}
}
int main()
{
	int A[] = { NULL,23,21,62,24,23,26,43,14,28,8,9,19,11 };
	QuickSort(A, 1, 13);
	for (int i = 1; i <= 13; i++)
	{
		printf("%d ", A[i]);
	}
	return 0;
}