#include "Graph.h"
/* ����������ͼ */
void CreateMGraph(MGraph *G)
{
	int i, j, k, w;
	printf("���붥�����ͱ�����\n");
	scanf("%d,%d", &G->numVertexes, G->numEdges); /* ���붨�����ͱ��� */
	for (i = 0; i < G->numVertexes; i++)/* ���붥����Ϣ����������� */
	{
		scanf(&G->vex[i]);
	}
	for (i = 0; i < G->numVertexes; i++)
	{
		for (j = 0; j < G->numVertexes; j++)
		{
			G->arc[i][j] = INFINITY;	/* �ڽӾ����ʼ�� */
		}
	}
	for (k = 0; k < G->numVertexes; k++)
	{
		printf("����ߣ�vi,vj���ϵ��±�i,�±�j��Ȩw:\n");
		scanf("%d,%d,%d", &i, &j, &w);	/* ����ߣ�vi,vj���ϵ�Ȩw */
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];	/* �Գƾ��� */
	}

}