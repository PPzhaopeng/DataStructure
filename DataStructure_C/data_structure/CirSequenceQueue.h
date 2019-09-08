#pragma once
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE	10

/* 类型重定义 */
typedef int QElemType;
typedef int Status;		

/* 循环队列的顺序存储结构 */
typedef struct
{
	QElemType data[MAXSIZE];
	int front;	//头指针
	int rear;	//尾指针，若队尾元素不为空，指向队尾元素的下一个位置
}SqQueue;

Status InitQueue(SqQueue *Q);
int QueueLength(SqQueue Q);
Status EnQueue(SqQueue *Q, QElemType e);
Status DeQueue(SqQueue *Q, QElemType *e);