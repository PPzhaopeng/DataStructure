#pragma once
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE	10

/* �����ض��� */
typedef int QElemType;
typedef int Status;		

/* ѭ�����е�˳��洢�ṹ */
typedef struct
{
	QElemType data[MAXSIZE];
	int front;	//ͷָ��
	int rear;	//βָ�룬����βԪ�ز�Ϊ�գ�ָ���βԪ�ص���һ��λ��
}SqQueue;

Status InitQueue(SqQueue *Q);
int QueueLength(SqQueue Q);
Status EnQueue(SqQueue *Q, QElemType e);
Status DeQueue(SqQueue *Q, QElemType *e);