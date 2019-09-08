#include "SequenceStack.h"
#include <iostream>
using namespace std;
//插入元素e作为新的栈顶元素
Status Push(SqStack *S, SElemType e)
{
	if (S->top == MAXSIZE - 1)//栈满
	{
		return ERROR;
	}
	S->top++;
	S->data[S->top] = e;
	return OK;
}

//出栈操作
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

/* /两栈共享空间进栈，插入元素e为栈顶元素 */
Status SDPush(SqDoubleStack *S, SElemType e, int stackNumber)
{
	if (S->top1 + 1 == S->top2)/* 栈已满 */
	{
		return ERROR;
	}
	if (stackNumber == 1)/* 栈1有元素进栈 */
	{
		S->data[++S->top1] = e;/* 先++操作，再赋值 */
	}
	else if (stackNumber == 2)/* 栈2有元素进栈 */
	{
		S->data[--S->top2] = e;
	}
}
/* 两栈共享空间出栈 */
Status SDPop(SqDoubleStack S, SElemType *e, int stackNumber)
{
	if (stackNumber == 1)
	{
		if (S.top1 == -1)
		{
			return ERROR;
		}
		*e = S.data[S.top1--];/* 先赋值，再--操作 */
	}
	else if (stackNumber == 2)
	{
		if (S.top2 == MAXSIZE)
		{
			return ERROR;
		}
		*e = S.data[S.top2++];/* 先赋值，再--操作 */
	}
	return OK;
}

void SquenceStackTest()
{
	SqStack S = { 0,0 };

	printf("进栈：");
	for (int i = 0; i < 6; i++)
	{
		Push(&S, i);
		printf("%d ", i);
	}

	printf("\n出栈：");
	for (int i = 0; i < 6; i++)
	{
		int *e = (int *)malloc(sizeof(int));
		Pop(&S, e);
		printf("%d ", *e);
	}


}