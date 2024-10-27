#pragma once
#include <stdio.h>
typedef char VertexType;	/* 顶点类型由用户定义 */
typedef int EdgeType;		/* 边上的权值类型应有用户定义 */

//定义邻接矩阵（Adjacency Matrix）存储结构
#define MAXVEX 100			/* 最大顶点数 */
#define INFINITY 65535		/* 用65535代替无穷 */

typedef struct
{
	VertexType vex[MAXVEX];			/* 顶点表 */
	EdgeType arc[MAXVEX][MAXVEX];	/* 邻接矩阵，可以看作边表 */
	int numVertexes, numEdges;
}MGraph;

void CreateMGraph(MGraph *G);/* 创建无向网图 */

//定义邻接表（Adjacency List）存储结构
typedef struct EdgeNode		/* 边表结点 */
{
	int adjvex;				/* 邻接顶点，存储该定点对应的下标 */
	EdgeType weight;		/* 用于存储权值 */
	struct EdgeNode *next;  /* 链域，指向下一个邻接点 */
}EdgeNode;
typedef struct VertexNode	/* 顶点表结点 */
{
	VertexType data;		/* 定点域，存储顶点信息 */
	EdgeNode *fristedge;	/* 边表头指针 */
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVertexes, numEdges;	/* 图中当前顶点数 */
}GraphAdjList;





