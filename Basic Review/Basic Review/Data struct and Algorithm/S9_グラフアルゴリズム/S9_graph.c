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
struct S9QueueNode {
	int data;
	struct S9QueueNode *next;
};
struct S9Queue {
	struct S9QueueNode *front;
};

struct S9Queue *S9CreateQueue() {
	struct S9Queue *q = (struct S9Queue *)malloc(sizeof(struct S9Queue));
	if (q == NULL) {
		return NULL;
	}
	q->front = NULL;
	return q;
}

int S9DeQueue(struct S9Queue *queue) {
	if (queue==NULL) {
		return -1;
	}
	if (queue->front == NULL) {
		return -1;
	}
	struct S9QueueNode *temp = queue->front;
	if (queue->front == NULL) {
		return -1;
	}
	int data = temp->data;
	queue->front = queue->front->next;
	free(temp);
	return data;
}
void S9EnQueue(struct S9Queue *queue, int data) {
	if (queue == NULL) {
		queue = (struct S9Queue *)malloc(sizeof(struct S9Queue));
	}
	struct S9QueueNode *newNode = (struct S9QueueNode *)malloc(sizeof(struct S9QueueNode));
	struct S9QueueNode *temp = queue->front;
	newNode->next = NULL;
	newNode->data = data;
	if (temp == NULL) {
		queue->front = newNode;
	} else {
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

void S9FreeQueue(struct S9Queue *q) {
	if (q == NULL) {
		return;
	}
	if (q->front != NULL) {
		struct S9QueueNode *temp = q->front, *temp2;
		while (temp != NULL) {
			temp2 = temp;
			temp = temp->next;
			free(temp2);
		}
	}
	free(q);
}

int S9IsEmptyQueue(struct S9Queue *queue) { // true: 1, false: 0
	if (queue == NULL) {
		return 1;
	}
	int result = queue->front == NULL ? 1 : 0;
	return result;
}
void S9ShowQueue(struct S9Queue *q) {
	if (q == NULL) {
		printf("queue is null\n");
		return;
	}
	if (q->front == NULL) {
		printf("queue has no data\n");
		return;
	}
	struct S9QueueNode *temp = q->front;
	int count = 0;
	while (temp) {
		printf("[%d]: %d ", count, temp->data);
		temp = temp->next;
		count++;
	}
	puts("");
}

int visited_bfs[128];
void breadthFirstSearch(struct Graph *g, int u) { // 矩阵
	int count = 0, i;
	struct S9Queue *queue = S9CreateQueue();
	S9EnQueue(queue, u);
	while (!S9IsEmptyQueue(queue)) {
		int u = S9DeQueue(queue);
		printf("顶点[%d]: %d\n", count, u);
		count++;
		visited_bfs[u] = 1;
		for (i=0; i<g->v; i++) {
			if (g->adj[u][i] == 1 && visited_bfs[i] == 0) {
				S9EnQueue(queue, i);
			}
		}
	}
	S9FreeQueue(queue);
}
void breadthFirstSearchTravsal(struct Graph *g) {
	for (int i=0; i<128; i++) {
		visited_bfs[i] = 0;
	}
	for (int i = 0; i<g->v; i++) {
		if (visited_bfs[i] == 0) {
			breadthFirstSearch(g, i);
		}
	}
}

//---------------------------------------------------------------------
//                      9.6   拓扑排序 p258~259
//---------------------------------------------------------------------
// TODO-PRO: add [补充拓扑排序]

//---------------------------------------------------------------------
//                      9.7   最短路线 p259~266
//---------------------------------------------------------------------
//------------------------------------------------
//             	 不带加权的图
//------------------------------------------------
int distant[128];
int path[128];
int S9DeleteMin(struct S9Queue *queue) {
	// 获取已经设定了值的里面最小的
	if (queue == NULL || queue->front == NULL) {
		return 0;
	}
	struct S9QueueNode *temp = queue->front;
	int current, currentIndex, minIndex=-1, min=-1, i=0, index=0;
	int hasBeenInited = 0;
	while (temp != NULL) {
		currentIndex = temp->data;
		current = distant[currentIndex];
		if (current < 0) {
			break;
		}
		if (hasBeenInited == 0) {
			index = i;
			min = current;
			minIndex = currentIndex;
			hasBeenInited = 1;
		} else {
			if (min>current) {
				index = i;
				min = current;
				minIndex = currentIndex;
			}
		}
		temp = temp->next;
		i++;
	}
	printf("result: %d\n", hasBeenInited ? minIndex : -1);
	if (hasBeenInited) {
		temp = queue->front;
		if (index == 0) {
			temp = queue->front;
			free(temp);
			queue->front = NULL;
		} else {
			temp = &queue->front[index-1];
			temp->next = &queue->front[index+1];
			free(&queue->front[index]);
		}
		
		
	}
	return hasBeenInited ? minIndex : -1;
}


void unweightedShortestPath(struct Graph *g, int s) { // 邻接矩阵版
	struct S9Queue *queue = S9CreateQueue();
	int v, w;
	S9EnQueue(queue, s);
	for (int i = 0; i<g->v; i++) {
		distant[i] = -1;
		path[i] = -1; // 起点为-1
	}
	distant[s] = 0;
	while(!S9IsEmptyQueue(queue)) {
		v = S9DeQueue(queue);
		for (w = 0; w<g->v; w++) {
			if (g->adj[v][w] != 0 && distant[w] == -1) {
				S9EnQueue(queue, w);
				distant[w] = distant[v] + 1;
				path[w] = v;
			}
		}
	}
	S9FreeQueue(queue);
}

//------------------------------------------------
//            不带负加权的图 迪杰斯特拉算法
//------------------------------------------------
void dijkstra(struct Graph *g, int s) {
	struct S9Queue *queue = S9CreateQueue(); // 优先队列
	int v, w;
	S9EnQueue(queue, s);
	for (int i = 0 ; i<g->v; i++) {
		distant[i] = -1; // -1 表示还没处理
	}
	distant[s] = 0; // 自己到自己的距离为0
	while (!S9IsEmptyQueue(queue)) {
//		v = S9DeQueue(queue); // TODO-PRO: fix here [这里要改成以距离为排序的DeleteMin]
		v = S9DeleteMin(queue);
		for (w = 0; w<g->v; w++) {
			if (g->adj[v][w] != 0) { // v -> w 直接相同
				int newDistant = distant[v] + g->adj[v][w]; // 新距离
				printf("distant[v]: %d\n", distant[v]);
				if (distant[w] == -1) {
					distant[w] = newDistant;
					S9EnQueue(queue, w);
					path[w] = v;
				} else if (newDistant < distant[w]) {
					distant[w] = newDistant;
					path[w] = v;
					// 更新w
					S9EnQueue(queue, w);
				}
			}
		}
	}
}

//------------------------------------------------
//                贝尔曼-福特算法(可带负权)
//------------------------------------------------
void bellmanFord(struct Graph *g, int s) {
	struct S9Queue *queue = S9CreateQueue();
	int v, w;
	S9EnQueue(queue, s);
	for (int i = 0; i<128; i++) {
		distant[i] = INT_MAX; // 初始值为无限大(其实有限)
	}
	distant[s] = 0;
	while (!S9IsEmptyQueue(queue)) {
		v = S9DeQueue(queue);
		for (w = 0; w < g->v; w++) {
			int weight = g->adj[v][w];
			if (weight != 0) { // v -> w 有通路
				if (distant[v] + weight < distant[w]) {
					distant[w] = distant[v] + weight; // 更新最小距离
					path[w] = v;
					S9EnQueue(queue, w);
				}
			}
		}
	}
}

//---------------------------------------------------------------------
//                    9.8   最小全域木 p266~271
//---------------------------------------------------------------------
// TODO-PRO: add [最小全域木]
//---------------------------------------------------------------------
//                             测试函数
//---------------------------------------------------------------------
void showMatrixGraph(struct Graph *g); // 展示邻接矩阵图
void showListGraph(struct ListGraph *g); // 展示邻居链表图
void showS9Array(int ary[], int length, char *name); // 展示数组

void graphTester() {
	//----------------------------------------------------
	// 					邻接矩阵的测试
	//----------------------------------------------------
	struct Graph *g = adjMatrixOfGraph();
	showMatrixGraph(g);
//	puts("//   深度优先探索");
//	depthFirstSearchTraversal(g); // 深度优先探索
//	puts("//   宽度优先探索");
//	breadthFirstSearchTravsal(g); // 宽度优先探索
//	unweightedShortestPath(g, 0); // 无加权最短路径算法
//	dijkstra(g, 0); // 迪杰斯特拉算法
//	bellmanFord(g, 0); // 贝尔曼福特算法
//	showS9Array(distant, 5, "distant");
//	showS9Array(path, 5, "path");
	//----------------------------------------------------
	// 					邻接链表的测试
	//----------------------------------------------------
//	struct ListGraph *listGraph = adjListOfGraph();
//	showListGraph(listGraph);
//	depthFirstSearchTraversal_List(listGraph);
	
	//----------------------------------------------------
	// 					   链表测试
	//----------------------------------------------------
//	struct S9Queue *queue = S9CreateQueue();
//	srand((unsigned int)time(NULL));
//	for (int i = 0; i<50; i++) {
//		S9EnQueue(queue, i);
//	}
//	S9ShowQueue(queue);
//	for (int i = 0; i<50; i++) {
//		printf("dequeue: %d\n", S9DeQueue(queue));
//	}
//	S9ShowQueue(queue);
//	S9FreeQueue(queue);
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

void showS9Array(int ary[], int length, char *name) { // 展示数组
	int columns = 6, j=0;
	for (int i = 0; i<length; i++) {
		printf("%s[%d]: %d\t", name, i, ary[i]);
		j++;
		if (j==columns) {
			puts("");
			j=0;
		}
	}
	puts("");
}
