#include "CirSequenceQueue.h"

/***************************************************
ѭ������ ˳��洢�ṹ
���������������������
***************************************************/

/* ��ʼ��һ���ն���Q */
Status InitQueue(SqQueue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	return OK;
}

/* ����Q��Ԫ�ظ�����Ҳ���Ƕ��еĵ�ǰ���� */
int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

/* ������δ���������Ԫ��eΪQ�µĶ�βԪ�� */
Status EnQueue(SqQueue *Q, QElemType e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)//���������ж�
		return ERROR;
	Q->data[Q->rear] = e;				
	Q->rear = (Q->rear + 1) % MAXSIZE;	//rearָ�������һλ��

	return OK;
}

/* ѭ�����еĳ��Ӳ����������в�Ϊ�գ�ɾ��Q�Ķ�ͷԪ�أ���e������ֵ */
Status DeQueue(SqQueue *Q, QElemType *e)
{
	if (Q->rear == Q->front)//���пյ��ж�
		return ERROR;
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;

	return OK;
}


