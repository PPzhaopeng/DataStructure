#pragma once
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE	10

typedef int QElemType;
typedef int Status;		

typedef struct
{
	QElemType data[MAXSIZE];
	int front;
	int rear;
}SqQueue;

Status InitQueue(SqQueue *Q);
int QueueLength(SqQueue Q);
Status EnQueue(SqQueue *Q, QElemType e);
Status DeQueue(SqQueue *Q, QElemType *e);