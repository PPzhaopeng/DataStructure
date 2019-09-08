#pragma once
#include <windows.h>
#include "CirSequenceQueue.h"

typedef struct
{

	SqQueue Q;	//统计排队
	int num;	//统计买票的数量
	int num1;   //统计卖票的数量
}Sale;

DWORD WINAPI Consumer(LPVOID lpParamter);
DWORD WINAPI Producer(LPVOID lpParamter);
int WindowQueue();