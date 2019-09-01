#include "Parameter.h"
#include "LinkList.h"
#include "stdlib.h"
#include "time.h"

/*****************************************************
获得链表第i个数据的算法思路
1.声明一个指针p指向指向链表的第一个结点，初始化j从1开始；
2.当j<i时，就遍历链表，让p的指针向后移动，不断指向下一个结点，j累加1
3.若到链表末尾p为空，则说明第i个结点不存在；（注：链表的最后一个结点指向NULL）
4.否则查找成功，返回结点p的数据。
******************************************************/
/*初始条件：顺序线性表L已存在，1<=i<=ListLength(L)*/
/*操作结果：用e返回第i个数据元素的值*/
Status GetElem(LinkList L, int i, ElemType *e)
{
	int j;
	LinkList p;		/*声明一个指针p，此指针代表一个结点*/
	p = L->next;	/*让p指向链表L的第一个节点*/
	j = 1;
	while (p&&j < i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
	{
		return ERROR;
	}
	*e = p->data;/*取第i个元素的数据*/
	return OK;
}

/*******************************************************
单链表第i个数据插入结点的算法思路
1.声明一个指针p指向链表头结点，初始化j从1开始；
2.当j<i时，就遍历列表，让p的指针向后移动，不断指向下一结点，j累加1；
3.若到链表末尾p为空，则说明第i个结点不存在;
4.否则查找成功，在系统中生成一个空结点s;
5.将元素e赋值给s->data;
6.单链表的插入标准语句s->next=p->next,p->next=s;
7.返回成功。
注：LinkList *L 为二级指针 
	结构体结点的地址是结构体指针变量，因此要对结构体进行插入数据、删除数据
	等操作，需要使用二级指针来传递实参，即修改指针变量，需要传递指针变量的地址。
	int **a; *a存储**a的地址，a存储*a的地址
	参考：https://blog.csdn.net/oqqHuTu12345678/article/details/60962223
*********************************************************/
/*初始条件：顺序线性表L已存在，1<=i<=ListLength(L)*/
/*操作结果：在L中第i个节点位置之前插入新的数据元素e,L的长度加1*/
Status ListInsert(LinkList *L, int i, ElemType e)
{
	int j;
	LinkList p, s;	//结构体指针变量
	p = *L;			//指针p指向链表头结点
	j = 1;
	while (p&&j < i)//遍历链表，寻找第i-1个结点
	{					//假设 i=5
		p = p->next;    // 1 2 3 4  p指向第4个结点 
		++j;			// 2 3 4 5
	}
	if (!p || j > i)//第i个结点不存在
	{
		return ERROR;
	}
	s = (LinkList)malloc(sizeof(Node));	//生成新节点
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}


/*******************************************************
单链表第i个数据删除结点的算法思路
1.声明一个指针p指向链表头指针，初始化j从1开始；
2.当j<i时，就遍历列表，让p的指针向后移动，不断指向下一结点，j累加1；
3.若到链表末尾p为空，则说明第i个结点不存在;
4.否则查找成功，将欲删除的结点p-next赋值给q;
5.单链表的删除标准语句p->next=q->next;
6.释放q结点
7.返回成功。
注：需要修改链表，故需要以链表指针变量为参数（LinkList *L）
*********************************************************/
/*初始条件：顺序线性表L已存在，1<=i<=ListLength(L)*/
/*操作结果：在L中第i个节点位置之前插入新的数据元素e,L的长度加1*/
Status ListDelete(LinkList *L, int i, ElemType *e)
{
	int j;
	LinkList p, q;
	p = *L; //指针p指向链表头指针
	j = 1;
	while (p->next && j < i) //遍历链表，寻找第i-1个结点
	{					//假设 i=5
		p = p->next;    // 1 2 3 4  p指向第4个结点 
		++j;			// 2 3 4 5
	}
	if (!(p->next) || j > i)//第i个结点不存在
	{
		return ERROR;
	}
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return OK;
}

/************************************
单链表的整表创建-(头查法)
算法思路：
1.声明一个指针p和计数器变量i
2.初始化一个空链表L;
3.让L的头结点的指针指向NULL，即建立一个带头结点的单链表
4.循环
	# 生成一个新结点赋值给p
	# 随机生成一个数字赋值给p的数据域p->data
	# 将p插入到头结点与前一新结点之间。
*************************************/
/*随机产生n个元素的值，建立带头节点的单链表L */
void CreateListHead(LinkList *L, int n)
{
	LinkList p;//声明一个指针变量p
	int i;
	srand(time(0));//初始化随机种子
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		p->next = (*L)->next;
		(*L)->next = p;
	}
}

/************************************
单链表的整表创建-(尾查法)
算法思路：
1.声明一个指针p,一个指针r和计数器变量i
2.初始化一个空链表L;
3.让r指针指向L的头结点
4.循环
	# 生成一个新结点赋值给p
	# 随机生成一个数字赋值给p的数据域p->data
	# 将p插入到前一新结点的后面。
*************************************/
/*随机产生n个元素的值，建立带头节点的单链表L（尾插法）*/
void CreateListTail(LinkList *L, int n)
{
	LinkList p, r;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;
	for (i = 0; i < n; i++)
	{
		p = (Node *)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

/************************************
单链表的整表删除，即释放内存
算法思路：
1.声明一结点p和q
2.将第一个结点赋值给p
3.循环
	# 将下一结点赋值给q
	# 释放p
	# 将q赋值给p
*************************************/
/*初始条件：链式线性表L已存在,操作结果：将L重置为空表*/
Status ClearList(LinkList *L)
{
	LinkList p, q;
	p=(*L)->next;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return OK;
}

