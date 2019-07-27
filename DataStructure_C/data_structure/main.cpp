#include "stdlib.h"
#include "Parameter.h"
#include "LinkList.h"
#include "iostream"
using namespace std;
void main()
{
	LinkList_test();
}

//使用单链表建立一个线性表，依次输入十个0-99之间的随机数，
//删除第5个元素，打印输出该线性表。
void LinkList_test()
{
	LinkList L= NULL;// L 指针变量
	const int len = 10;
	CreateListHead(&L, len); //建立一个拥有10个结点的线性表,其中&L为指针变量的地址（二级指针）
	int *e = (int *)malloc(sizeof(int));
	LinkList p;		//定义指针变量p
	p = L->next;	//指针变量p指向链表头结点
	while(p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;	
	
	ListDelete(&L, 5, e);
	ListInsert(&L, 1, 100);
	p = L->next;	//指针变量p指向链表头结点
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

	system("pause");
}