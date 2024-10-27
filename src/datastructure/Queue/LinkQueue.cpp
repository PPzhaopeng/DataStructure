#include "LinkQueue.h"
#include <stdlib.h>
/**********************************************
队列的链式储存结构
线性表的单链表，尾部进头部出
队头指针指向头结点，队尾指针指向终端结点
*********************************************/

/* 入队操作，插入元素e为Q的新的队尾元素 */
Status EnQueue(LinkQueue *Q, QElemType e)
{
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));//分配一个结点
	s->data = e;		//赋值
	s->next = NULL;		
	Q->rear->next = s;	//把拥有元素e新结点s赋值给原队尾结点的后继
	Q->rear = s;		//把当前的s结点设为队尾结点
	
	return OK;
}

/* 出队操作，若队列部位空，删除Q的对头元素，用e返回其值，并返回OK，否则返回ERROR */
Status DeQueue(LinkQueue *Q, QElemType *e)
{
	QueuePtr p;
	if (Q->front == Q->rear)//判断队列为空
		return ERROR;
	p = Q->front->next;//将欲删除的队头结点暂存给p
	*e = p->data;//将欲删除的队头结点赋值给*e
	Q->front->next = p->next;

	if (Q->rear == p)//若队头是队尾，则删除后将rear指向头结点
		Q->rear = Q->front;
	free(p);
	return OK;
}
