#pragma once
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
typedef int Status;		//Status �������͸���ʵ������������������Ϊ int
typedef int SElemType;	//SElemType �������͸���ʵ������������������Ϊ int

typedef struct StackNode
{
	SElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr/*����typedef struct StackNode *LinkStackPtr*/;

typedef struct LinkStack
{
	LinkStackPtr top;	//ջ��ָ��
	int count;			//ջ���
}LinkStack;

Status StackEmpty(LinkStack S);
Status Push(LinkStack *S, SElemType e);
Status Pop(LinkStack *S, SElemType *e)
