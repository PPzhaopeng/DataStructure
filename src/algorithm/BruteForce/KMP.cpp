#include "KMP.h"

/* Brute-Force(BF)算法,即朴素的模式匹配算法 */
//主串S中找出子串T，出现的位置，pos为主串开始查找的位置
int BFIndex(String S, String T, int pos)
{
	int i = pos;	//主串的位置
	int j = 1;		//子串的位置
	//开始查找
	while (i <= S[0] && j <= T[0])
	{
		if (T[j] == S[i])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 2;//返回此次匹配第一个相等位置的下一个位置
			j = 1;
		}

	}
	if (j > T[0])
	{
		return (i - T[0]);
	}
	else
		return 0;
}


