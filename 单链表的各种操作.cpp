#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
typedef struct _Node {
	int id;
	struct _Node* next;
}Node;
Node* CreateListTail()
{
	Node* head;
	Node* ptail;
	Node* pnew;
	head = (Node*)malloc(sizeof(Node));
	//head=new Node;
	head->next = NULL;
	ptail = head;
	while (1)
	{

		int tmp;
		scanf("%d", &tmp);
		if (tmp < 0)
		{
			break;
		}
		pnew = (Node*)malloc(sizeof(Node));
		ptail->next = pnew;
		ptail = pnew;
		ptail->id = tmp;
		ptail->next = NULL;

	}
	return head;
}
Node* CreateListHead()
{
	Node* head;
	Node* pnew;
	//head = (Node*)malloc(sizeof(Node));
	head = new Node;
	head->next = NULL;
	while (1)
	{
		int tmp;
		scanf("%d", &tmp);
		if (tmp < 0)
		{
			break;
		}
		pnew = new Node;// (Node*)malloc(sizeof(Node));
		pnew->next = head->next;
		pnew->id = tmp;
		head->next = pnew;
	}
	return head;
}
void PrintfNode(Node* head)
{
	Node* tmp;
	tmp = head->next;
	while (tmp != NULL)
	{
		printf("->%d", tmp->id);
		tmp = tmp->next;
	}
}

void InsertNode(Node* head, int x, int y)//在x的前面插入y，如果没找到就在表尾插入；
{
	Node* pre;
	Node* cur;
	Node* pnew;
	pnew = new Node;// (Node*)malloc(sizeof(Node) * 1);
	pnew->id = y;
	pre = head;
	cur = head->next;
	while (cur != NULL)
	{
		if (cur->id == x)
		{
			break;
		}
		pre = cur;
		cur = cur->next;
	}
	pre->next = pnew;
	pnew->next = cur;
}
void DeleteNode(Node* head, int x)
{
	Node* pre;
	Node* cur;
	Node* pnew;
	pre = head;
	cur = head->next;
	while (cur != NULL)
	{
		if (cur->id == x)
		{
			break;
		}
		pre = cur;
		cur = cur->next;
	}
	if (cur != NULL)
	{
		pre->next = cur->next;
		free(cur);
	}
	else
	{
		printf("没有找到\n");
	}
}
int main01()
{
	Node* head = CreateListTail();
	printf("%p\n", head);
	PrintfNode(head);
	return 0;
}
int main()
{
	Node* head = CreateListHead();
	//printf("%p\n", head);
	PrintfNode(head);
	printf("\n");
	InsertNode(head, 30, 20);
	PrintfNode(head);
	DeleteNode(head, 40);
	PrintfNode(head);
	delete(head);
	//->36->4536->40->4363->30->34->457->564->8->47->463->34
	//->36->4536->40->4363->20->30->34->457->564->8->47->463->34
	//->36->4536->4363->20->30->34->457->564->8->47->463->34
	return 0;
}