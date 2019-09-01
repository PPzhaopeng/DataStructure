#include "LinkStack.h"
#include <stdlib.h>

Status StackEmpty(LinkStack S)
{
	if (S.count == -1)
		return FALSE;
	return TRUE;
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

