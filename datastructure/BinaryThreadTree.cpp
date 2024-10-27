#include "BinaryThreadTree.h"
#include <stdio.h>
/* �������Ķ��������洢�ṹ */
//Link=0 ��ʾ���Һ��ӵ�ָ��
//Thread=1 ��ʾָ��ǰ�����ߺ�̵�����

typedef struct BiThrNode
{
	TElemType data;
	struct BiThrNode *lchild, *rchild;
	PointerTage LTag;	//���ұ�־
	PointerTage Rtag;	

}BiThrNode,*BiThrTree;

//�������Ĺ��̾����ڱ����������޸Ŀ�ָ��Ĺ���
//����ӡ���Ĺ��ܣ��ĳ����������Ĺ���
BiThrTree pre; //ȫ�ֱ�����ʼ��ָ��ոշ��ʹ��Ľ��
/* ��������������������� */
void InThreading(BiThrTree p)
{
	if (p)
	{
		InThreading(p->lchild);
		if (!p->rchild)
		{
			p->LTag = Thread;	//ǰ������
			p->lchild = pre;	//����ָ��ָ��ǰ��
		}
		if (!p->rchild)
		{
			pre->Rtag = Thread;
			pre->rchild = p;
		}
		pre = p;	//����preָ��p��ǰ��
		InThreading(p->rchild);

	}

}

/* Tָ��ͷ��㣬ͷ�������lchildָ����ڵ㣬ͷ�������rchildָ��������������һ����� */
/* ��������������������ʾ�Ķ�����T */
Status InOrderTraverse_Thr(BiThrTree T)
{
	BiThrTree p;
	p = T->lchild;
	while (p != T)
	{
		while (p->LTag == Link)
		{
			p = p->lchild;
		}
		printf("%c",p->data);
		while (p->Rtag == Thread && p->rchild != T)
		{
			p = p->rchild;
			printf("%c", p->data);
		}
		p = p->rchild;
	}
	return 1;
}