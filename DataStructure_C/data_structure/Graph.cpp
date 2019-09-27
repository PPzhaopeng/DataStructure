#include "Graph.h"
/* 创建无向网图 */
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