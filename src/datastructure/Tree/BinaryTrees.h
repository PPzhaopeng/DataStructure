#pragma once
typedef int TElemType;
typedef int Status;

/* �������Ķ���������ṹ���� */
typedef struct BiTNode
{
	TElemType data;						//�������
	struct BiTNode *lchild, *rchild;	//���Һ���ָ��
}BiTNode, *BiTree;


void PreOrderTraverse(BiTree T);
void InOrderTraverse(BiTree T);
void PostOrderTraverse(BiTree T);
void CreateBiTree(BiTree *T);
