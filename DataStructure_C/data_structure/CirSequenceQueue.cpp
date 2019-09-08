#include "CirSequenceQueue.h"

/***************************************************
循环队列 顺序存储结构
面临着数组可能溢出的情况
***************************************************/

/* 初始化一个空队列Q */
Status InitQueue(SqQueue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	return OK;
}

/* 返回Q的元素个数，也就是队列的当前长度 */
int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

/* 若队列未满，则插入元素e为Q新的队尾元素 */
Status EnQueue(SqQueue *Q, QElemType e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)//队列满的判断
		return ERROR;
	Q->data[Q->rear] = e;				
	Q->rear = (Q->rear + 1) % MAXSIZE;	//rear指针向后移一位置

	return OK;
}

/* 循环队列的出队操作，若队列不为空，删除Q的队头元素，用e返回其值 */
Status DeQueue(SqQueue *Q, QElemType *e)
{
	if (Q->rear == Q->front)//队列空的判断
		return ERROR;
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;

	return OK;
}


