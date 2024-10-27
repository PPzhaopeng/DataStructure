#pragma once
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
typedef int Status;//Status 数据类型根据实际情况而定，这里假设为 int

typedef int SElemType; //SElemType 数据类型根据实际情况而定，这里假设为 int
typedef struct 
{
	SElemType data[MAXSIZE];
	int top;	//用于栈顶指针
}SqStack;

Status Push(SqStack *S, SElemType e);
Status Pop(SqStack *S, SElemType *e);
void SquenceStackTest();

/* 两栈共享空间结构 */
//主要用于两个栈的空间需求有相反的关系，也就是一个栈增长，另一个会减小
typedef struct
{
	SElemType data[MAXSIZE];
	int top1;
	int top2;
}SqDoubleStack;
Status SDPush(SqDoubleStack *S, SElemType e, int stackNumber);
Status SDPop(SqDoubleStack S, SElemType *e, int stackNumber);