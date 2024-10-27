#include "BinaryTrees.h"
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>

/* 二叉树的前序遍历递归算法 */
void PreOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	printf("%c", T->data);//打印结点数据,可以更改为其他对结点的操作
	PreOrderTraverse(T->lchild);//再先遍历左子树
	PreOrderTraverse(T->rchild);//再后遍历右子树
}

/* 二叉树的中序遍历递归算法 */
void InOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	InOrderTraverse(T->lchild);//遍历左子树
	printf("%c", T->data);//打印结点数据,可以更改为其他对结点的操作
	InOrderTraverse(T->rchild);//遍历右子树
}

/* 二叉树的后序遍历递归算法 */
void PostOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	PostOrderTraverse(T->lchild);//遍历左子树
	PostOrderTraverse(T->rchild);//遍历右子树
	printf("%c", T->data);//打印结点数据,可以更改为其他对结点的操作
}

/* 按前序输入二叉树中结点的值（一个字符） */
/* #表示空树，构造二叉链表表示二叉树      */
//建立二叉树，只不过在原来打印的地方，改成生成结点、给结点赋值的操作
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