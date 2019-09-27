#pragma once
#include <stdio.h>
//�����ڽӾ���Adjacency Matrix���洢�ṹ
typedef char VertexType;	/* �����������û����� */
typedef int EdgeType;		/* ���ϵ�Ȩֵ����Ӧ���û����� */
#define MAXVEX 100			/* ��󶥵��� */
#define INFINITY 65535		/* ��65535�������� */

typedef struct
{
	VertexType vex[MAXVEX];			/* ����� */
	EdgeType arc[MAXVEX][MAXVEX];	/* �ڽӾ��󣬿��Կ����߱� */
	int numVertexes, numEdges;
}MGraph;

void CreateMGraph(MGraph *G);/* ����������ͼ */
