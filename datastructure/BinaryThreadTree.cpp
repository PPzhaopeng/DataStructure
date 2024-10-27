#include "BinaryThreadTree.h"
#include <stdio.h>
/* 二叉树的二叉线索存储结构 */
//Link=0 表示左右孩子的指针
//Thread=1 表示指向前驱或者后继的线索

typedef struct BiThrNode
{
	TElemType data;
	struct BiThrNode *lchild, *rchild;
	PointerTage LTag;	//左右标志
	PointerTage Rtag;	

}BiThrNode,*BiThrTree;

//线索化的过程就是在遍历过程中修改空指针的过程
//将打印结点的功能，改成了线索化的功能
BiThrTree pre; //全局变量，始终指向刚刚访问过的结点
/* 中序遍历进行中序线索化 */
void InThreading(BiThrTree p)
{
	if (p)
	{
		InThreading(p->lchild);
		if (!p->rchild)
		{
			p->LTag = Thread;	//前驱线索
			p->lchild = pre;	//左孩子指针指向前驱
		}
		if (!p->rchild)
		{
			pre->Rtag = Thread;
			pre->rchild = p;
		}
		pre = p;	//保持pre指向p的前驱
		InThreading(p->rchild);

	}

}

/* T指向头结点，头结点左链lchild指向根节点，头结点右链rchild指向中序遍历的最后一个结点 */
/* 中序遍历二叉线索链表表示的二叉树T */
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