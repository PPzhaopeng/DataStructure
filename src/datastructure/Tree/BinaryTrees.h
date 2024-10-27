#pragma once
typedef int TElemType;
typedef int Status;

/* 二叉树的二叉链表结点结构定义 */
typedef struct BiTNode
{
	TElemType data;						//结点数据
	struct BiTNode *lchild, *rchild;	//左右孩子指针
}BiTNode, *BiTree;


void PreOrderTraverse(BiTree T);
void InOrderTraverse(BiTree T);
void PostOrderTraverse(BiTree T);
void CreateBiTree(BiTree *T);
