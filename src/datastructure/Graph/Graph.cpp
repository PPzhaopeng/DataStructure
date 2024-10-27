#include "Graph.h"
#include <stdlib.h>
/* 创建无向网图的邻接矩阵结构 */
void CreateMGraph(MGraph *G)
{
	int i, j, k, w;
	printf("输入顶点数和边数：\n");
	scanf("%d,%d", &G->numVertexes, G->numEdges); /* 输入定点数和边数 */
	for (i = 0; i < G->numVertexes; i++)/* 读入顶点信息，建立顶点表 */
	{
		scanf(&G->vex[i]);
	}
	for (i = 0; i < G->numVertexes; i++)
	{
		for (j = 0; j < G->numVertexes; j++)
		{
			G->arc[i][j] = INFINITY;	/* 邻接矩阵初始化 */
		}
	}
	for (k = 0; k < G->numVertexes; k++)
	{
		printf("输入边（vi,vj）上的下标i,下标j和权w:\n");
		scanf("%d,%d,%d", &i, &j, &w);	/* 输入边（vi,vj）上的权w */
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];	/* 对称矩阵 */
	}

}

/* 创建无向图的邻接表结构 */
void CreatALGraph(GraphAdjList *G)
{
	int i, j, k;
	EdgeNode *e;	//边表结点
	printf("请输入定点数和边数!\n");
	scanf("%d,%d", &G->numVertexes, &G->numEdges);//输入定点数和边数
	for (i = 0; i < G->numVertexes; i++)
	{
		scanf(&G->adjList[i].data);			//输入顶点信息
		G->adjList[i].fristedge = NULL;		//将边表置为空表
	}
	for (k = 0; k < G->numEdges; k++)	//建立边表
	{
		printf("输入边（vi,vj）上的顶点序号：\n");
		scanf("%d,%d", &i, &j);

		e = (EdgeNode *)malloc(sizeof(EdgeNode));//向内存申请空间，生成边表结点
		e->adjvex = j;	//邻接序号
		e->next = G->adjList[i].fristedge;		//将e指针指向当前顶点指向的结点
		G->adjList[i].fristedge = e;			//将当前顶点的指针指向 e 

		e = (EdgeNode *)malloc(sizeof(EdgeNode));//向内存申请空间，生成边表结点
		e->adjvex = i;	//邻接序号
		e->next = G->adjList[j].fristedge;		//将e指针指向当前顶点指向的结点
		G->adjList[j].fristedge = e;			//将当前顶点的指针指向 e 
	}

}