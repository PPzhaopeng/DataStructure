#include "CirSequenceQueueApplication.h"
#include "CirSequenceQueue.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
/******************************************************************
使用顺序循环队列和多线程实现一个排队买票的例子。
而且，我们只允许这个队伍中同时排队的只有10个人，那就需要用到队列了。

生产者（等候买票）
消费者 (买票离开)
*******************************************************************/

//卖票平台
int WindowQueue()
{
	Sale *S = (Sale*)malloc(sizeof(Sale));
	S->num = 0;
	S->num1 = 0;
	S->Q = { 0 };
	int num = 0;//统计卖票的数量
	int isAlive = TRUE;//判断是否继续卖票
	while (S->num1 < 100)
	{

		//排队买票
		HANDLE hThread1 = CreateThread(NULL, 0, Consumer, S, 0, NULL);

		//排队卖票	
		HANDLE hThread2 = CreateThread(NULL, 0, Producer, S, 0, NULL);

		Sleep(1);
	}

	return 1;
}

//卖票
DWORD WINAPI Producer(LPVOID lpParamter)
{
	//参数转换
	Sale *S = (Sale *)(lpParamter);
	//判断队列是否为空
	int QLen = QueueLength(S->Q);
	if (QLen == 0)
	{
		printf("无人排队\n");
		return ERROR;
	}
	S->num1++;
	//判断票是否有剩余
	if (S->num1 > 100)
	{
		//printf("结束卖票线程\n");
		return ERROR;
	}
	int *e= (int *)malloc(sizeof(int));
	DeQueue(&(S->Q), e);
	printf("第%d个客户买到票离开队列\n", *e);
	Sleep(1);
	return 1;
}


//买票
DWORD WINAPI Consumer(LPVOID lpParamter)
{
	//参数转换
	Sale *S = (Sale *)(lpParamter);
	
	//判断队列是否为满
	int QLen = QueueLength(S->Q);
	if (QLen >= MAXSIZE)
	{
		printf("排队人数已满。。。，请等待\n");
		return 0;
	}
	S->num++;
	//判断票是否有剩余
	if (S->num > 100)
	{
		//printf("结束排队线程\n");
		return ERROR;
	}

	//队列添加顾客
	EnQueue(&(S->Q), S->num);
	printf("第%d个客户排队等待买票\n",S->num);
	
	Sleep(1);

	return 1;
}


