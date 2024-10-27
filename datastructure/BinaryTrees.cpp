#include "BinaryTrees.h"
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>

/* ��������ǰ������ݹ��㷨 */
void PreOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	printf("%c", T->data);//��ӡ�������,���Ը���Ϊ�����Խ��Ĳ���
	PreOrderTraverse(T->lchild);//���ȱ���������
	PreOrderTraverse(T->rchild);//�ٺ����������
}

/* ����������������ݹ��㷨 */
void InOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	InOrderTraverse(T->lchild);//����������
	printf("%c", T->data);//��ӡ�������,���Ը���Ϊ�����Խ��Ĳ���
	InOrderTraverse(T->rchild);//����������
}

/* �������ĺ�������ݹ��㷨 */
void PostOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	PostOrderTraverse(T->lchild);//����������
	PostOrderTraverse(T->rchild);//����������
	printf("%c", T->data);//��ӡ�������,���Ը���Ϊ�����Խ��Ĳ���
}

/* ��ǰ������������н���ֵ��һ���ַ��� */
/* #��ʾ������������������ʾ������      */
//������������ֻ������ԭ����ӡ�ĵط����ĳ����ɽ�㡢����㸳ֵ�Ĳ���
void CreateBiTree(BiTree *T)
{
	TElemType ch;
	scanf("%c", &ch);
	if (ch == '#')
		*T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if (!*T)
			exit(1);
		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}

}