#include "Graph.h"
#include <stdlib.h>
/* ����������ͼ���ڽӾ���ṹ */
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

/* ��������ͼ���ڽӱ�ṹ */
void CreatALGraph(GraphAdjList *G)
{
	int i, j, k;
	EdgeNode *e;	//�߱���
	printf("�����붨�����ͱ���!\n");
	scanf("%d,%d", &G->numVertexes, &G->numEdges);//���붨�����ͱ���
	for (i = 0; i < G->numVertexes; i++)
	{
		scanf(&G->adjList[i].data);			//���붥����Ϣ
		G->adjList[i].fristedge = NULL;		//���߱���Ϊ�ձ�
	}
	for (k = 0; k < G->numEdges; k++)	//�����߱�
	{
		printf("����ߣ�vi,vj���ϵĶ�����ţ�\n");
		scanf("%d,%d", &i, &j);

		e = (EdgeNode *)malloc(sizeof(EdgeNode));//���ڴ�����ռ䣬���ɱ߱���
		e->adjvex = j;	//�ڽ����
		e->next = G->adjList[i].fristedge;		//��eָ��ָ��ǰ����ָ��Ľ��
		G->adjList[i].fristedge = e;			//����ǰ�����ָ��ָ�� e 

		e = (EdgeNode *)malloc(sizeof(EdgeNode));//���ڴ�����ռ䣬���ɱ߱���
		e->adjvex = i;	//�ڽ����
		e->next = G->adjList[j].fristedge;		//��eָ��ָ��ǰ����ָ��Ľ��
		G->adjList[j].fristedge = e;			//����ǰ�����ָ��ָ�� e 
	}

}