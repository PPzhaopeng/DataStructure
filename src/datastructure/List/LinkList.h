#pragma once
/**************************************************************************
ע��
1.�ṹ��Ķ���
	struct�����������µ���������-�ṹ��
	typedef������ȡ������typedef struct��Ϊ��ʹ�ýṹ�巽�㡣
	struct node{}����ṹ�壬����������Ҫ��struct node n1;��
	typedef struct node{}NODE;,����������Ҫ��NODE n2;
	����ʡȥ�ؼ���struct��
2.�ṹ�����͵�ָ�����
	1�����壺һ��ָ��ṹ�������ָ�������ָ�����ָ��ṹ��������׵�ַ��
	2�����ʽṹ���Ա
		(*�ṹ��ָ�����).��Ա�� ���� �ṹ��ָ�����->��Ա��
3.typedef struct Node *LinkList; 	
	struct Node* �ı��
	LinkList p1; ����һ���ṹ��ָ��������洢����ַ,��ͬ��struct Node *p1;
	p1��ʾ���ĵ�ַ��*p1��ʾ��㣬����(*p1).data,(*p1).next,����nextҲ�Ǳ�ʾ��ַ
****************************************************************************/
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;	/*ElemType�������͸����������������Ĭ��Ϊint����*/
typedef int Status;		/*�����ض���*/

/*���Ա�ĵ�����洢�ṹ*/
typedef struct Node
{
	ElemType data;
	struct Node *next;//����ṹ��ָ��������洢�ṹ���ַ��
}Node;

// �� struct Node* ��һ��ָ�����LinkList ��Linklist L��struct Node *next������ͬ����������
typedef struct Node *LinkList;

Status GetElem(LinkList L, int i, ElemType *e);
Status ListInsert(LinkList *L, int i, ElemType e);
Status ListDelete(LinkList *L, int i, ElemType *e);
void CreateListHead(LinkList *L, int n);
void CreateListTail(LinkList *L, int n);
Status ClearList(LinkList *L);
void LinkListTest();
