#include "LinkStack.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
Status StackEmpty(LinkStack S)
{
	if (S.count == -1)
		return TRUE;
	return FALSE;
}

/* ջ����ʽ�洢�ṹ������ջ  ����Ԫ��eΪ�µ�ջ��Ԫ�� */
Status Push(LinkStack *S, SElemType e)
{
	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));//�����½���ڴ�
	s->data = e;	//��ֵ�½ڵ�
	s->next = S->top;/* �ѵ�ǰջ��Ԫ�ظ�ֵ���½���ֱ�Ӻ�� */
	S->top = s;/* ���½��s��ֵ��ջ��ָ�� */
	S->count++;
	return OK;
}

/* ջ����ʽ�洢�ṹ������ջ */
Status Pop(LinkStack *S, SElemType *e)
{
	LinkStackPtr p;
	if (StackEmpty(*S))
	{
		return ERROR;
	}
	*e = S->top->data;
	p = S->top;				/* ��ջ����㸳ֵ��p */
	S->top = S->top->next;	/* ʹ��ջ���������һλ��ָ���һ��� */
	free(p);/* �ͷŽ��p */
	S->count--;
	return OK;
}

void LinkStackTest()
{
	LinkStack S = {0,-1};//ջΪ��ʱ������Ϊ-1��
	printf("�Ƿ�Ϊ�գ�%d", StackEmpty(S)); // 1

	printf("\n��ջ��");
	for (int i = 0; i < 6; i++)
	{
		Push(&S, i);
		printf("%d ", i);
	}
	printf("\n�Ƿ�Ϊ�գ�%d", StackEmpty(S));// 0

	printf("\n��ջ��");
	for (int i = 0; i < 3; i++)
	{
		int *e = (int *)malloc(sizeof(int));
		Pop(&S, e);
		printf("%d ", *e);
	}

}
