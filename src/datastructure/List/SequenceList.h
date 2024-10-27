#pragma once
/*******************************************************
线性表的三个属性：
1.存储空间的起始位置
2.线性表的最大存储能量
4.线性表的当前长度
********************************************************/
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
typedef int Status;//Status 数据类型根据实际情况而定，这里假设为 int

typedef int ElemType; //ElemType 数据类型根据实际情况而定，这里假设为 int

typedef struct 
{
	ElemType data[MAXSIZE];	//数组存储数据元素
	int length;				//线性表当前长度
}SqList;

Status ListInsert(SqList *L, int i, ElemType e);
Status ListDelete(SqList *L, int i, ElemType *e);
void SequenceListTest();
