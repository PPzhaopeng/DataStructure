#pragma once
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;		//Status 数据类型根据实际情况而定，这里假设为 int
typedef int SElemType;	//SElemType 数据类型根据实际情况而定，这里假设为 int

typedef struct StackNode
{
	SElemType data;				//数据
	struct StackNode *next;		//下一个数据的地址
}StackNode, *LinkStackPtr/*等于typedef struct StackNode *LinkStackPtr*/;

typedef struct LinkStack
{
	LinkStackPtr top;	//栈顶指针
	int count;			//栈深度
}LinkStack;

Status StackEmpty(LinkStack S);
Status Push(LinkStack *S, SElemType e);
Status Pop(LinkStack *S, SElemType *e);
void LinkStackTest();
