#include "stdlib.h"
#include "Parameter.h"
#include "LinkList.h"
#include "iostream"
using namespace std;
void main()
{
	LinkList_test();
}

//ʹ�õ�������һ�����Ա���������ʮ��0-99֮����������
//ɾ����5��Ԫ�أ���ӡ��������Ա�
void LinkList_test()
{
	LinkList L= NULL;// L ָ�����
	const int len = 10;
	CreateListHead(&L, len); //����һ��ӵ��10���������Ա�,����&LΪָ������ĵ�ַ������ָ�룩
	int *e = (int *)malloc(sizeof(int));
	LinkList p;		//����ָ�����p
	p = L->next;	//ָ�����pָ������ͷ���
	while(p)
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

	system("pause");
}