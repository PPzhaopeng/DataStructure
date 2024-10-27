#pragma once
/*******************************************************
���Ա���������ԣ�
1.�洢�ռ����ʼλ��
2.���Ա�����洢����
4.���Ա�ĵ�ǰ����
********************************************************/
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
typedef int Status;//Status �������͸���ʵ������������������Ϊ int

typedef int ElemType; //ElemType �������͸���ʵ������������������Ϊ int

typedef struct 
{
	ElemType data[MAXSIZE];	//����洢����Ԫ��
	int length;				//���Ա�ǰ����
}SqList;

Status ListInsert(SqList *L, int i, ElemType e);
Status ListDelete(SqList *L, int i, ElemType *e);
void SequenceListTest();
