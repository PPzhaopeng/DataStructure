#pragma once
#include <stdio.h>
//定义邻接矩阵（Adjacency Matrix）存储结构
typedef char VertexType;	/* 顶点类型由用户定义 */
typedef int EdgeType;		/* 边上的权值类型应有用户定义 */
#define MAXVEX 100			/* 最大顶点数 */
#define INFINITY 65535		/* 用65535代替无穷 */

typedef struct
{
	VertexType vex[MAXVEX];			/* 顶点表 */
	EdgeType arc[MAXVEX][MAXVEX];	/* 邻接矩阵，可以看作边表 */
	int numVertexes, numEdges;
}MGraph;

void CreateMGraph(MGraph *G);/* 创建无向网图 */
