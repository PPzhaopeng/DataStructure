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

/* 栈的链式存储结构——进栈  插入元素e为新的栈顶元素 */
Status Push(LinkStack *S, SElemType e)
{
	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));//申请新结点内存
	s->data = e;	//赋值新节点
	s->next = S->top;/* 把当前栈顶元素赋值给新结点的直接后继 */
	S->top = s;/* 将新结点s赋值给栈顶指针 */
	S->count++;
	return OK;
}

/* 栈的链式存储结构——出栈 */
Status Pop(LinkStack *S, SElemType *e)
{
	LinkStackPtr p;
	if (StackEmpty(*S))
	{
		return ERROR;
	}
	*e = S->top->data;
	p = S->top;				/* 将栈顶结点赋值给p */
	S->top = S->top->next;	/* 使得栈顶结点下移一位，指向后一结点 */
	free(p);/* 释放结点p */
	S->count--;
	return OK;
}

void LinkStackTest()
{
	LinkStack S = {0,-1};//栈为空时，长度为-1；
	printf("是否为空：%d", StackEmpty(S)); // 1

	printf("\n进栈：");
	for (int i = 0; i < 6; i++)
	{
		Push(&S, i);
		printf("%d ", i);
	}
	printf("\n是否为空：%d", StackEmpty(S));// 0

	printf("\n出栈：");
	for (int i = 0; i < 3; i++)
	{
		int *e = (int *)malloc(sizeof(int));
		Pop(&S, e);
		printf("%d ", *e);
	}

}
