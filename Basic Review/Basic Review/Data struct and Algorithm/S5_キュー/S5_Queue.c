//
//  S5_Queue.c
//  Basic Review
//
//  Created by 徐伟达 on 2018/4/7.
//  Copyright © 2018年 徐伟达. All rights reserved.
//

#include "S5_Queue.h"

//---------------------------------------------------------------------
//                            序列 p111~122
//---------------------------------------------------------------------
//---------------------------------------------------------------------
//                       5.6.2 单纯循环数组实现 p113
//---------------------------------------------------------------------
//------------------------------------------------
//                  序列的型声明
//------------------------------------------------
struct ArrayQueue {
	int front, rear;
	int capacity;
	int *array;
};

//------------------------------------------------
//                   函数声明
//------------------------------------------------
// SHOW: SAMPLE [书上版本]
struct ArrayQueue *Queue(int size); // 初始化
int isEmptyQueue(struct ArrayQueue *Q); // 是否为空
int isFullQueue(struct ArrayQueue *Q); // 是否已满
int QueueSize(struct ArrayQueue *Q); // 获取大小
void enQueue(struct ArrayQueue *Q, int data); // push元素
int deQueue(struct ArrayQueue *Q); // unshift元素
void deleteQueue(struct ArrayQueue *Q); // 删除整个队列
//------------------------------------------------
//                   函数实现
//------------------------------------------------
struct ArrayQueue *Queue(int size) { // 初始化
	struct ArrayQueue *Q = (struct ArrayQueue *)malloc(sizeof(struct ArrayQueue));
	if (!Q) {
		return NULL;
	}
	Q->capacity = size;
	Q->front = Q->rear = -1;
	Q->array = (int *)malloc(Q->capacity*size);
	if (!Q->array) {
		return NULL;
	}
	return Q;
}

int isEmptyQueue(struct ArrayQueue *Q) { // 是否为空
	return Q->front == -1;
}

int isFullQueue(struct ArrayQueue *Q) { // 是否已满
	return (Q->rear+1) % Q->capacity == Q->front;
}

int QueueSize(struct ArrayQueue *Q) { // 获取大小
	// TODO-PRO: problem [p114  书上的括号里为什么要加Q->capacity?]
	return (Q->rear - Q->front + 1) % Q->capacity;
}

void enQueue(struct ArrayQueue *Q, int data) { // push元素
	if (isFullQueue(Q)) {
		printf("Queue Overflow");
	} else {
		Q->rear = (Q->rear + 1) % Q->capacity; // 0 ..< Q->capacity 之间
		Q->array[Q->rear] = data;
		if (Q->front == -1) {
			Q->front = Q->rear;
		}
	}
}

int deQueue(struct ArrayQueue *Q) { // unshift元素
	int data;
	if (isEmptyQueue(Q)) {
		printf("Queue is Empty\n");
		return 0;
	} else {
		data = Q->array[Q->front];
		if (Q->front == Q->rear) {
			Q->front = Q->rear = -1;
		} else {
			Q->front = (Q->front + 1) % Q->capacity;
		}
		return 0;
	}
}

void deleteQueue(struct ArrayQueue *Q) { // 删除整个队列
	if (Q) {
		if (Q->array) {
			free(Q->array);
		}
		free(Q);
	}
}

//---------------------------------------------------------------------
//                       5.6.3 动态循环数组实现 p115
//---------------------------------------------------------------------
// 就只需要在 静态循环数组实现 基础上增加 容量满了的时候扩容的方法
//------------------------------------------------
//                   函数声明
//------------------------------------------------
// SHOW: SAMPLE [书上版本]
void resizeQueue(struct ArrayQueue *Q);
//------------------------------------------------
//                   函数实现
//------------------------------------------------
void resizeQueue(struct ArrayQueue *Q) { // 满容量时候容量扩为两倍
	int size = Q->capacity;
	Q->capacity *= 2;
	Q->array = (int *)realloc(Q->array, Q->capacity);
	if (!Q->array) {
		printf("Memory Error");
		return;
	}
	if (Q->front > Q->rear) { // 处理原数据后边因为超过容量移到前面的情况
		for (int i = 0; i < Q->front; i++) {
			Q->array[i+size] = Q->array[i];
		}
		Q->rear += size;
	}
}

//---------------------------------------------------------------------
//                       5.6.4 链表实现 p117
//---------------------------------------------------------------------
//------------------------------------------------
//                  序列的型声明
//------------------------------------------------
struct ListNode {
	int data;
	struct ListNode *next;
};

struct ListQueue {
	struct ListNode *front;
	struct ListNode *rear;
};

//------------------------------------------------
//                   函数声明
//------------------------------------------------
// SHOW: SAMPLE [书上版本]
struct ListQueue *Queue_list(void); // 创建链表队列
int isEmptyQueue_list(struct ListQueue * Q); // 是否为空
void enQueue_List(struct ListQueue *Q, int data); //插入 push
int deQueue_list(struct ListQueue *Q); // 取出第一个 unshift
void deleteQueue_list(struct ListQueue * Q); // 删除链表队列

//------------------------------------------------
//                   函数实现
//------------------------------------------------
struct ListQueue *Queue_list(void) { // 创建链表队列
	struct ListQueue *Q;
	Q = (struct ListQueue *)malloc(sizeof(struct ListQueue));
	if (!Q) {
		printf("Memory Error\n");
		return NULL;
	}
	Q->front = Q->rear = NULL;
	return Q;
}

int isEmptyQueue_list(struct ListQueue * Q) { // 是否为空
	return Q->front == NULL;
}

void enQueue_List(struct ListQueue *Q, int data) { //插入 push
	struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
	if (!newNode) {
		printf("Memory Error\n");
		return;
	}
	newNode->data = data;
	newNode->next = NULL;
	if (!Q->front || !Q->rear) { // TODO-PRO:  explain [书上此处有误]
		Q->front = Q->rear = newNode;
	} else {
		Q->rear->next = newNode;
		Q->rear = newNode;
		
	}
}

int deQueue_list(struct ListQueue *Q) { // 取出第一个 unshift
	int data;
	struct ListNode *temp;
	if (isEmptyQueue_list(Q)) {
		printf("ListQueue is Empty\n");
		return 0;
	} else {
		temp = Q->front;
		data = temp->data;
		Q->front = Q->front->next;
		free(temp);
	}
	return data;
}

void deleteQueue_list(struct ListQueue * Q) { // 删除链表队列
	struct ListNode *currentNode = Q->front, *nextNode;
	if (Q) { // TODO-PRO:  explain [书上此处有误]
		while (currentNode) {
			nextNode = currentNode->next;
			free(currentNode);
			currentNode = nextNode;
		}
		free(Q);
	}
}

//---------------------------------------------------------------------
//                             测试函数
//---------------------------------------------------------------------
void queueTester(void) {
	
}
