#include "LinkQueue.h"
#include <stdlib.h>
/**********************************************
���е���ʽ����ṹ
���Ա�ĵ�����β����ͷ����
��ͷָ��ָ��ͷ��㣬��βָ��ָ���ն˽��
*********************************************/

/* ��Ӳ���������Ԫ��eΪQ���µĶ�βԪ�� */
Status EnQueue(LinkQueue *Q, QElemType e)
{
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));//����һ�����
	s->data = e;		//��ֵ
	s->next = NULL;		
	Q->rear->next = s;	//��ӵ��Ԫ��e�½��s��ֵ��ԭ��β���ĺ��
	Q->rear = s;		//�ѵ�ǰ��s�����Ϊ��β���
	
	return OK;
}

/* ���Ӳ����������в�λ�գ�ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR */
Status DeQueue(LinkQueue *Q, QElemType *e)
{
	QueuePtr p;
	if (Q->front == Q->rear)//�ж϶���Ϊ��
		return ERROR;
	p = Q->front->next;//����ɾ���Ķ�ͷ����ݴ��p
	*e = p->data;//����ɾ���Ķ�ͷ��㸳ֵ��*e
	Q->front->next = p->next;

	if (Q->rear == p)//����ͷ�Ƕ�β����ɾ����rearָ��ͷ���
		Q->rear = Q->front;
	free(p);
	return OK;
}
