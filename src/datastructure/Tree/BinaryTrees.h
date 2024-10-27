#pragma once
typedef int TElemType;
typedef int Status;

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;


void PreOrderTraverse(BiTree T);
void InOrderTraverse(BiTree T);
void PostOrderTraverse(BiTree T);
void CreateBiTree(BiTree *T);
