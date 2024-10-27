#pragma once
#include <stdio.h>
typedef char VertexType;	/* �����������û����� */
typedef int EdgeType;		/* ���ϵ�Ȩֵ����Ӧ���û����� */

//�����ڽӾ���Adjacency Matrix���洢�ṹ
#define MAXVEX 100			/* ��󶥵��� */
#define INFINITY 65535		/* ��65535�������� */

typedef struct
{
	VertexType vex[MAXVEX];			/* ����� */
	EdgeType arc[MAXVEX][MAXVEX];	/* �ڽӾ��󣬿��Կ����߱� */
	int numVertexes, numEdges;
}MGraph;

void CreateMGraph(MGraph *G);/* ����������ͼ */

//�����ڽӱ�Adjacency List���洢�ṹ
typedef struct EdgeNode		/* �߱��� */
{
	int adjvex;				/* �ڽӶ��㣬�洢�ö����Ӧ���±� */
	EdgeType weight;		/* ���ڴ洢Ȩֵ */
	struct EdgeNode *next;  /* ����ָ����һ���ڽӵ� */
}EdgeNode;
typedef struct VertexNode	/* ������� */
{
	VertexType data;		/* �����򣬴洢������Ϣ */
	EdgeNode *fristedge;	/* �߱�ͷָ�� */
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVertexes, numEdges;	/* ͼ�е�ǰ������ */
}GraphAdjList;





