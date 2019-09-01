#include "test.h"
#include <stdlib.h>
#include "LinkList.h"
#include "SequenceList.h"
#include <iostream>
using namespace std;

void SequenceList_test()
{
	SqList L = {0,0};//�ṹ�������ʼ��

	for (int i = 1; i < 5; i++)
	{
		ListInsert(&L, 1, i);
	}
	int *e = (int*)malloc(sizeof(int));
	ListDelete(&L, 3, e);
	cout << L.length << endl;
	for (int i = 0; i < L.length; i++)
	{
		cout << L.data[i] << " ";
	}
	cout << endl;

}


//ʹ�õ�������һ�����Ա���������ʮ��0-99֮����������
//ɾ����5��Ԫ�أ���ӡ��������Ա�
void LinkList_test()
{
	LinkList L = NULL;// L ָ�����
	const int len = 10;
	CreateListHead(&L, len); //����һ��ӵ��10���������Ա�,����&LΪָ������ĵ�ַ������ָ�룩
	int *e = (int *)malloc(sizeof(int));
	LinkList p;		//����ָ�����p
	p = L->next;	//ָ�����pָ������ͷ���
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

	ListDelete(&L, 5, e);
	ListInsert(&L, 1, 100);
	p = L->next;	//ָ�����pָ������ͷ���
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}