#pragma once
/**************************************************************************
注：
1.结构体的定义
	struct是用来定义新的数据类型-结构体
	typedef是类型取别名，typedef struct是为了使用结构体方便。
	struct node{}定义结构体，声明变量需要用struct node n1;，
	typedef struct node{}NODE;,声明变量需要用NODE n2;
	可以省去关键字struct。
2.结构体类型的指针变量
	1）定义：一个指向结构体变量的指针变量，指针变量指向结构体变量的首地址。
	2）访问结构体成员
		(*结构体指针变量).成员名 或者 结构体指针变量->成员名
3.typedef struct Node *LinkList; 	
	struct Node* 的别称
	LinkList p1; 定义一个结构体指针变量，存储结点地址,等同于struct Node *p1;
	p1表示结点的地址，*p1表示结点，比如(*p1).data,(*p1).next,其中next也是表示地址
****************************************************************************/
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;	/*ElemType数据类型根据情况而定，这里默认为int类型*/
typedef int Status;		/*类型重定义*/

/*线性表的单链表存储结构*/
typedef struct Node
{
	ElemType data;
	struct Node *next;//定义结构体指针变量，存储结构体地址，
}Node;

// 给 struct Node* 起一个指针别名LinkList ，Linklist L与struct Node *next具有相同的数据类型
typedef struct Node *LinkList;

Status GetElem(LinkList L, int i, ElemType *e);
Status ListInsert(LinkList *L, int i, ElemType e);
Status ListDelete(LinkList *L, int i, ElemType *e);
void CreateListHead(LinkList *L, int n);
void CreateListTail(LinkList *L, int n);
Status ClearList(LinkList *L);
void LinkListTest();
