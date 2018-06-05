//
//  S9_graph.c
//  Basic Review
//
//  Created by 徐伟达 on 2018/6/1.
//  Copyright © 2018年 徐伟达. All rights reserved.
//

#include "S9_graph.h"
//---------------------------------------------------------------------
//                        图论算法   p243~296
//---------------------------------------------------------------------
//---------------------------------------------------------------------
//                        9.4   图的数据结构
//---------------------------------------------------------------------
//------------------------------------------------
//             		  邻接矩阵
//------------------------------------------------
struct Graph {
	int v;
	int e;
	int **adj;
};

// 创建图
struct Graph *adjMatrixOfGraph() {
	int i, u, v;
	struct Graph *G = (struct Graph *)malloc(sizeof(struct Graph));
	if (G == NULL) {
		printf("memory error\n");
		return NULL;
	}
	printf("Number of Verticees: ");
	scanf("%d", &G->v);
	printf("Number of Edges: ");
	scanf("%d", &G->e);
	G->adj = (int **)malloc(sizeof(int *) * G->v);
	if (G->adj == NULL) {
		printf("Memory Error\n");
		return NULL;
	}
	for (i = 0; i < G->v; i++) {
		G->adj[i] = (int *)malloc(sizeof(int) * G->v);
		if (G->adj[i] == NULL) {
			printf("Memory Error\n");
			return NULL;
		}
	}
	printf("v: %d, e: %d\n", G->v, G->e);
	for (u=0; u<G->v; u++) { // 初始化点
		for (v=0; v<G->v; v++) {
			if (u==v) {
				G->adj[u][v] = 1;
			} else {
				G->adj[u][v] = 0; // 以0初始化矩阵
			}
		}
	}

	for (i=0; i<G->e; i++) { // 初始化边
		printf("Reading Edge: ");
		scanf("%d %d", &u, &v);
		G->adj[u][v] = G->adj[v][u] = 1;
	}
	return G;
}

//------------------------------------------------
//             		  邻接链表
//------------------------------------------------
struct S9ListNode {
	int vertexNumber;
	struct S9ListNode *next;
};

struct ListGraph {
	int v;
	int e;
	struct S9ListNode *adj;
};

struct ListGraph *adjListOfGraph() { // 无向图
	int i, x, y;
	struct S9ListNode *temp;
	struct ListGraph *G = (struct ListGraph *)malloc(sizeof(struct ListGraph));
	if (G == NULL) {
		printf("Memory Error\n");
		return NULL;
	}
	printf("Number of Vertices: ");
	scanf("%d", &G->v);
	printf("Number of Edges: ");
	scanf("%d", &G->e);
	G->adj = (struct S9ListNode *)malloc(sizeof(struct S9ListNode)*G->v);
	if (G->adj == NULL) {
		printf("Memory Error\n");
		return NULL;
	}
	for (i=0; i<G->v; i++) { // 先初始化所有链表
		G->adj[i] = *(struct S9ListNode *)malloc(sizeof(struct S9ListNode));
		G->adj[i].vertexNumber = i;
		G->adj[i].next = &G->adj[i];
	}
	
	for (i=0; i<G->e; i++) {
		printf("Reading Edge: ");
		scanf("%d %d", &x, &y);
		struct S9ListNode *node;
		temp = (struct S9ListNode *)malloc(sizeof(struct S9ListNode));
		// 把y添加到x的链表上
		temp->vertexNumber = y;
		temp->next = &G->adj[x];
		node = &G->adj[x];
		while (node != NULL && node->next != &G->adj[x]) {
			node = node->next;
		}
		node->next = temp;
		// 把x添加到y的链表山
		temp = (struct S9ListNode *)malloc(sizeof(struct S9ListNode));
		temp->vertexNumber = x;
		temp->next = &G->adj[y];
		node = &G->adj[y];
		while (node != NULL && node->next != &G->adj[y]) {
			node = node->next;
		}
		node->next = temp;
	}
	return G;
}

//---------------------------------------------------------------------
//                        9.5   图的遍历
//---------------------------------------------------------------------
//------------------------------------------------
//                深度优先搜索  DFS
//------------------------------------------------
int visited[128]; // 实际只需要点的数量的长度
// 状态: 1: 已访问     0: 未访问
// 邻接矩阵的DFS
void depthFirstSearch(struct Graph *g, int u) {
	int v;
	visited[u] = 1;
	printf("%d visited\n", u); // 访问中的处理
	for (v = 0; v <g->v; v++) {
		// 对点u连接的未访问的节点进行访问
		if (visited[v] == 0 && g->adj[u][v] != 0) { // 节点并未访问且u和v连接
			depthFirstSearch(g, v); // 从v出发
		}
	}
}

void depthFirstSearchTraversal(struct Graph *g) {
	int i;
	for (i = 0; i < g->v; i++) { // 初始化访问表
		visited[i] = 0;
	}
	// 有不通的子连接图时需要
	for (i = 0; i < g->v; i++) {
		if (visited[i] == 0) {
			depthFirstSearch(g, i); // 一次呼出直接遍历完i可到的所有点
		}
	}
}

// 邻接链表的DFS
void depthFirstSearch_List(struct ListGraph *g, int u) {
	struct S9ListNode *temp = g->adj[u].next;
	visited[u] = 1;
	printf("%d visited\n", u); // 访问中的处理
	while (temp != &g->adj[u]) {
		if (visited[temp->vertexNumber] == 0) {
			depthFirstSearch_List(g, temp->vertexNumber);
		}
		temp = temp->next;
	}
	
}

void depthFirstSearchTraversal_List(struct ListGraph *g) {
	int i;
	for (i = 0; i < g->v; i++) { // 初始化访问表
		visited[i] = 0;
	}
	// 有不通的子连接图时需要
	for (i = 0; i < g->v; i++) {
		if (visited[i] == 0) {
			depthFirstSearch_List(g, i); // 一次呼出直接遍历完i可到的所有点
		}
	}
}
//------------------------------------------------
//                宽度优先搜索  BFS
//------------------------------------------------

//---------------------------------------------------------------------
//                             测试函数
//---------------------------------------------------------------------
void showMatrixGraph(struct Graph *g); // 展示邻接矩阵图
void showListGraph(struct ListGraph *g); // 展示邻居链表图

void graphTester() {
	// 邻接矩阵的创建测试
//	struct Graph *g = adjMatrixOfGraph();
//	showMatrixGraph(g);
//	depthFirstSearchTraversal(g);
	
	// 邻接链表的创建测试
	struct ListGraph *listGraph = adjListOfGraph();
	showListGraph(listGraph);
	depthFirstSearchTraversal_List(listGraph);
}

void showMatrixGraph(struct Graph *g) { // 展示邻接矩阵图
	int i, j;
	char c = 'A';
	puts("--------------------------------------");
	puts("		   show matrix graph");
	puts("--------------------------------------");
	printf("v: %d, e: %d\n", g->v, g->e);
	printf("\t");
	for (i = 0; i < g->v; i++) {
		printf("%c\t", c++);
	}
	puts("");
	c = 'A';
	for (i=0; i<g->v; i++) {
		printf("%c", c++);
		for (j=0; j<g->v; j++) {
			printf("\t%d", g->adj[i][j]);
		}
		puts("");
	}
	puts("");
}

void showListGraph(struct ListGraph *g) { // 展示邻居链表图
	int i;
	struct S9ListNode *temp;
	puts("--------------------------------------");
	puts("			 show list graph");
	puts("--------------------------------------");
	printf("v: %d, e: %d\n", g->v, g->e);
	for (i=0; i<g->v; i++) {
		temp = &g->adj[i];
		printf("%2d: ", temp->vertexNumber);
		temp = temp->next;
		while (temp != &g->adj[i]) {
			printf("%d\t", temp->vertexNumber);
			temp = temp->next;
		}
		puts("");
	}
}
