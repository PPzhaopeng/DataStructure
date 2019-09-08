#pragma once
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
typedef int Status;//Status �������͸���ʵ������������������Ϊ int

typedef int SElemType; //SElemType �������͸���ʵ������������������Ϊ int
typedef struct 
{
	SElemType data[MAXSIZE];
	int top;	//����ջ��ָ��
}SqStack;

Status Push(SqStack *S, SElemType e);
Status Pop(SqStack *S, SElemType *e);
void SquenceStackTest();

/* ��ջ����ռ�ṹ */
//��Ҫ��������ջ�Ŀռ��������෴�Ĺ�ϵ��Ҳ����һ��ջ��������һ�����С
typedef struct
{
	SElemType data[MAXSIZE];
	int top1;
	int top2;
}SqDoubleStack;
Status SDPush(SqDoubleStack *S, SElemType e, int stackNumber);
Status SDPop(SqDoubleStack S, SElemType *e, int stackNumber);