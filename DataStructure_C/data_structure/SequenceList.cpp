#include "SequenceList.h"
#include <stdlib.h>

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