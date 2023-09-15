#include<iostream>
using namespace std;

void InsertSort(int a[], int Length)
{
	int i, j, low, high, mid;
	for (i = 2; i <= Length; i++)
	{
		a[0] = a[i];
		low = 1; high = i - 1;
		while (low <= high) {
			mid = (low + high) / 2;
			if (a[mid] > a[0])
			{
				high = mid - 1;
			}
			else
				low = mid + 1;
		}
		for (j = i - 1; j >= high + 1; j--)
		{
			a[j + 1] = a[j];
		}
		a[high + 1] = a[0];
	}
}
int main()
{
	int A[21];
	int j = 19;
	for (int i = 1; i <= 20; i++)
	{
		A[i] = j;
		j--;
	}
	for (int i = 1; i <= 20; i++)
	{
		printf("%d,", A[i]);
	}
	printf("\n");
	int Length = 20;
	InsertSort(A, Length);
	for (int i = 1; i <= 20; i++)
	{
		printf("%d,", A[i]);
	}
	printf("\n");
	return 0;
}