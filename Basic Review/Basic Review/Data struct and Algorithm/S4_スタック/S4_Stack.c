//
//  S4_Stack.c
//  Basic Review
//
//  Created by 徐伟达 on 2018/1/15.
//  Copyright © 2018年 徐伟达. All rights reserved.
//

#include "S4_Stack.h"

//---------------------------------------------------------------------
//                            堆 p81
//---------------------------------------------------------------------
//---------------------------------------------------------------------
//                        4.5.1 单纯数组实现
//---------------------------------------------------------------------
// SHOW: SAMPLE [书上版本 整个都是]
//------------------------------------------------
//                    型声明
//------------------------------------------------
#define PRO_STACK_SIZE_V1 100
struct arrayStack {
	int top; //开头的所以
	int capacity; // 容量
	int *array;
};
//------------------------------------------------
//                   函数声明
//------------------------------------------------
struct arrayStack *createStack(void);// 创建堆
int isEmptyStack(struct arrayStack *s); // 判断是否为空
int isFullStack(struct arrayStack *s);// 判断是否已满
void push(struct arrayStack *s, int data); // push
int pop(struct arrayStack *s); //pop
void deleteStack(struct arrayStack *s); // 删除堆
//------------------------------------------------
//
//
//------------------------------------------------
struct arrayStack *createStack() { // 创建堆
	struct arrayStack *s = (struct arrayStack *)malloc(sizeof(struct arrayStack));
	if (s == NULL) {
		puts("单纯数组版,堆初始化失败");
		return NULL;
	}
	s->capacity = PRO_STACK_SIZE_V1;
	s->top = -1;
	s->array = malloc(s->capacity * sizeof(int));
	if (s->array == NULL) {
		puts("单纯数组版, 堆数据初始化失败");
		return NULL;
	}
	return s;
}

int isEmptyStack(struct arrayStack *s) { // 判断是否为空
	return (s->top == -1); // 条件成立返回1(真), 不成立返回0(否)
}

int isFullStack(struct arrayStack *s) { // 判断是否已满
	return (s->top >= (s->capacity -1));
}

void push(struct arrayStack *s, int data) { // push
	if (isFullStack(s)) {
		puts("堆已满");
		return;
	} else {
		s->array[++s->top] = data; //插入到最后一个的后面
	}
}

int pop(struct arrayStack *s) { //pop
	if (isEmptyStack(s)) {
		puts("堆为空");
		return 0;
	}else {
		return s->array[s->top--]; // 返回最后一个并把top-1
	}
}

void deleteStack(struct arrayStack *s) { // 删除堆
	if (s) {
		if (s->array) {
			free(s->array);
		}
		free(s);
	}
}
//---------------------------------------------------------------------
//                             测试函数
//---------------------------------------------------------------------
void stackTester(void) {
	
}
