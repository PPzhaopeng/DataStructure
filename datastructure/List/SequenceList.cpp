#include "SequenceList.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
//获得数据元素操作
Status GetElm(SqList L, int i, ElemType *e)
{
	if (L.length == 0 || i<1 || i>L.length)//异常检测
	{
		return ERROR;
	}
	*e = L.data[i - 1];
	return OK;
}

//插入操作
Status ListInsert(SqList *L, int i, ElemType e)
{
	if (L->length == MAXSIZE)
		return ERROR;
	if (i<1 || i>L->length + 1)
		return ERROR;
	if (i <= L->length)//若插入的数据不在表尾
	{
		for (int k = L->length - 1; k >= i - 1; k--)
		{
			L->data[k + 1] = L->data[k];
		}
	}
	L->data[i - 1] = e;
	L->length++;
	return OK;
}

//删除操作
Status ListDelete(SqList *L, int i, ElemType *e)
{
	if (L->length == MAXSIZE)
		return ERROR;
	if (i<1 || i>L->length + 1)
		return ERROR;
	*e = L->data[i - 1];
	if (i < L->length)
	{
		for (int k = i; k < L->length; k++)
		{
			L->data[k - 1] = L->data[k];
		}
		L->length--;
		return OK;
	}
}



void SequenceListTest()
{
	SqList L = { 0,0 };//结构体数组初始化

	for (int i = 1; i < 5; i++)
	{
		ListInsert(&L, 1, i);
	}
	int *e = (int*)malloc(sizeof(int));
	ListDelete(&L, 3, e);
	cout << L.length << endl;
	for (int i = 0; i < L.length; i++)
	{
		cout << L.data[i] << " ";
	}
	cout << endl;

}

