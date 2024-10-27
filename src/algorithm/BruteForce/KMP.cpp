#include "KMP.h"

/* Brute-Force(BF)�㷨,�����ص�ģʽƥ���㷨 */
//����S���ҳ��Ӵ�T�����ֵ�λ�ã�posΪ������ʼ���ҵ�λ��
int BFIndex(String S, String T, int pos)
{
	int i = pos;	//������λ��
	int j = 1;		//�Ӵ���λ��
	//��ʼ����
	while (i <= S[0] && j <= T[0])
	{
		if (T[j] == S[i])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 2;//���ش˴�ƥ���һ�����λ�õ���һ��λ��
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


