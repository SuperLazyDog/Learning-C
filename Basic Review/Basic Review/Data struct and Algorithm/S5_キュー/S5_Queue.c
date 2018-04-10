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
int enQueue(struct ArrayQueue *Q, int data); // push元素
int deQueue(struct ArrayQueue *Q); // unshift元素
int deleteQueue(struct ArrayQueue *Q); // 删除整个队列
//------------------------------------------------
//                   函数实现
//------------------------------------------------
struct ArrayQueue *Queue(int size) { // 初始化
	struct ArrayQueue *Q = (struct ArrayQueue *)malloc(sizeof(struct ArrayQueue));
	if (!Q) {
		return NULL
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
	return NULL;
}

int enQueue(struct ArrayQueue *Q, int data) { // push元素
	return NULL;
}

int deQueue(struct ArrayQueue *Q) { // unshift元素
	return NULL;
}

int deleteQueue(struct ArrayQueue *Q) { // 删除整个队列
	return NULL;
}

//---------------------------------------------------------------------
//                             测试函数
//---------------------------------------------------------------------
void queueTester(void) {
	printf("hello in queueTester\ns");
}
