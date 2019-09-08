#include "SequenceStack.h"
#include <iostream>
using namespace std;
//����Ԫ��e��Ϊ�µ�ջ��Ԫ��
Status Push(SqStack *S, SElemType e)
{
	if (S->top == MAXSIZE - 1)//ջ��
	{
		return ERROR;
	}
	S->top++;
	S->data[S->top] = e;
	return OK;
}

//��ջ����
Status Pop(SqStack *S, SElemType *e)
{
	if (S->top == -1)
	{
		return ERROR;
	}
	*e = S->data[S->top];
	S->top--;
	return OK;
}

/* /��ջ����ռ��ջ������Ԫ��eΪջ��Ԫ�� */
Status SDPush(SqDoubleStack *S, SElemType e, int stackNumber)
{
	if (S->top1 + 1 == S->top2)/* ջ���� */
	{
		return ERROR;
	}
	if (stackNumber == 1)/* ջ1��Ԫ�ؽ�ջ */
	{
		S->data[++S->top1] = e;/* ��++�������ٸ�ֵ */
	}
	else if (stackNumber == 2)/* ջ2��Ԫ�ؽ�ջ */
	{
		S->data[--S->top2] = e;
	}
}
/* ��ջ����ռ��ջ */
Status SDPop(SqDoubleStack S, SElemType *e, int stackNumber)
{
	if (stackNumber == 1)
	{
		if (S.top1 == -1)
		{
			return ERROR;
		}
		*e = S.data[S.top1--];/* �ȸ�ֵ����--���� */
	}
	else if (stackNumber == 2)
	{
		if (S.top2 == MAXSIZE)
		{
			return ERROR;
		}
		*e = S.data[S.top2++];/* �ȸ�ֵ����--���� */
	}
	return OK;
}

void SquenceStackTest()
{
	SqStack S = { 0,0 };

	printf("��ջ��");
	for (int i = 0; i < 6; i++)
	{
		Push(&S, i);
		printf("%d ", i);
	}

	printf("\n��ջ��");
	for (int i = 0; i < 6; i++)
	{
		int *e = (int *)malloc(sizeof(int));
		Pop(&S, e);
		printf("%d ", *e);
	}


}