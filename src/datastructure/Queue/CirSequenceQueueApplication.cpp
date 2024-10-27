#include "CirSequenceQueueApplication.h"
#include "CirSequenceQueue.h"
#include <stdio.h>
#include <stdlib.h>
/******************************************************************
ʹ��˳��ѭ�����кͶ��߳�ʵ��һ���Ŷ���Ʊ�����ӡ�
���ң�����ֻ�������������ͬʱ�Ŷӵ�ֻ��?10���ˣ��Ǿ���Ҫ�õ������ˡ�

�����ߣ��Ⱥ���Ʊ��
������ (��Ʊ�뿪)
*******************************************************************/

//��Ʊƽ̨
int WindowQueue()
{
	Sale *S = (Sale*)malloc(sizeof(Sale));
	S->num = 0;
	S->num1 = 0;
	S->Q = { 0 };
	int num = 0;//ͳ����Ʊ������
	int isAlive = TRUE;//�ж��Ƿ�������?
	while (S->num1 < 100)
	{

		//�Ŷ���Ʊ
		HANDLE hThread1 = CreateThread(NULL, 0, Consumer, S, 0, NULL);

		//�Ŷ���Ʊ	
		HANDLE hThread2 = CreateThread(NULL, 0, Producer, S, 0, NULL);

		Sleep(1);
	}

	return 1;
}

//��Ʊ
DWORD WINAPI Producer(LPVOID lpParamter)
{
	//����ת��
	Sale *S = (Sale *)(lpParamter);
	//�ж϶����Ƿ�Ϊ��
	int QLen = QueueLength(S->Q);
	if (QLen == 0)
	{
		printf("�����Ŷ�\n");
		return ERROR;
	}
	S->num1++;
	//�ж�Ʊ�Ƿ���ʣ��
	if (S->num1 > 100)
	{
		//printf("������Ʊ�߳�\n");
		return ERROR;
	}
	int *e= (int *)malloc(sizeof(int));
	DeQueue(&(S->Q), e);
	printf("��%d���ͻ���Ʊ�뿪����\n", *e);
	Sleep(1);
	return 1;
}


//��Ʊ
DWORD WINAPI Consumer(LPVOID lpParamter)
{
	//����ת��
	Sale *S = (Sale *)(lpParamter);
	
	//�ж϶����Ƿ�Ϊ��
	int QLen = QueueLength(S->Q);
	if (QLen >= MAXSIZE)
	{
		printf("�Ŷ�������������������ȴ�\n");
		return 0;
	}
	S->num++;
	//�ж�Ʊ�Ƿ���ʣ��
	if (S->num > 100)
	{
		//printf("�����Ŷ��߳�\n");
		return ERROR;
	}

	//�������ӹ˿�
	EnQueue(&(S->Q), S->num);
	printf("��%d���ͻ��Ŷӵȴ���Ʊ\n",S->num);
	
	Sleep(1);

	return 1;
}


