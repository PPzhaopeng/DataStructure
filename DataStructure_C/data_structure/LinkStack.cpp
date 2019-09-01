#include "LinkStack.h"
#include <stdlib.h>

Status StackEmpty(LinkStack S)
{
	if (S.count == -1)
		return FALSE;
	return TRUE;
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

