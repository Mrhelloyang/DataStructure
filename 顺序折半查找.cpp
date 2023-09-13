#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
typedef struct {
	int* elem;
	int TableLen;
}SSTable;
int Binary_Seq(SSTable L, int key)
{
	int low = 0, high = L.TableLen - 1, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key == L.elem[mid])
		{
			return mid;
		}
		else if (L.elem[mid] < key)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return -1;
}
int main()
{
	SSTable L;
	L.elem = new int[20];
	for (int i = 0; i <= 19; i++)
	{
		L.elem[i] = i; //(* (ST.elem + i))p = i;  
	}
	L.TableLen = 20;
	int key = 15;
	int ret = Binary_Seq(L, key);
	printf("ret=%d\n", ret);
	return 0;
}