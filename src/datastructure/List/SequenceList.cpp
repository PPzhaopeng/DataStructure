#include "SequenceList.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
//�������Ԫ�ز���
Status GetElm(SqList L, int i, ElemType *e)
{
	if (L.length == 0 || i<1 || i>L.length)//�쳣���
	{
		return ERROR;
	}
	*e = L.data[i - 1];
	return OK;
}

//�������
Status ListInsert(SqList *L, int i, ElemType e)
{
	if (L->length == MAXSIZE)
		return ERROR;
	if (i<1 || i>L->length + 1)
		return ERROR;
	if (i <= L->length)//����������ݲ��ڱ�β
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

//ɾ������
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
	SqList L = { 0,0 };//�ṹ�������ʼ��

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

