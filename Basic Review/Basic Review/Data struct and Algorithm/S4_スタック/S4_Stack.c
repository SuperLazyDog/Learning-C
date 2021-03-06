//
//  S4_Stack.c
//  Basic Review
//
//  Created by 徐伟达 on 2018/1/15.
//  Copyright © 2018年 徐伟达. All rights reserved.
//

#include "S4_Stack.h"

//---------------------------------------------------------------------
//                            栈 p81
//---------------------------------------------------------------------
//---------------------------------------------------------------------
//                       4.5.1 单纯数组实现 p83
//---------------------------------------------------------------------
// SHOW: SAMPLE [书上版本 整个都是]
//------------------------------------------------
//                    型声明
//------------------------------------------------
//#define PRO_STACK_SIZE_V1 100
// 20180510 为了树结构的遍历，移到头文件
//struct arrayStack {
//	int top; //开头的索引
//	int capacity; // 容量
//	int *array;
//};
//------------------------------------------------
//                   函数声明
//------------------------------------------------
struct arrayStack *createStack(void);// 创建栈
int isEmptyStack(struct arrayStack *s); // 判断是否为空
int isFullStack(struct arrayStack *s);// 判断是否已满
void push(struct arrayStack *s, int data); // push
int pop(struct arrayStack *s); //pop
void deleteStack(struct arrayStack *s); // 删除栈
//------------------------------------------------
//                   函数实现
//------------------------------------------------
struct arrayStack *createStack() { // 创建栈
	struct arrayStack *s = (struct arrayStack *)malloc(sizeof(struct arrayStack));
	if (s == NULL) {
		puts("单纯数组版,栈初始化失败");
		return NULL;
	}
	s->capacity = PRO_STACK_SIZE_V1;
	s->top = -1;
	s->array = malloc(s->capacity * sizeof(int));
	if (s->array == NULL) {
		puts("单纯数组版, 栈数据初始化失败");
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
		puts("栈已满");
		return;
	} else {
		s->array[++s->top] = data; //插入到最后一个的后面
	}
}

int pop(struct arrayStack *s) { //pop
	if (isEmptyStack(s)) {
		puts("栈为空");
		return 0;
	}else {
		return s->array[s->top--]; // 返回最后一个并把top-1
	}
}

void deleteStack(struct arrayStack *s) { // 删除栈
	if (s) {
		if (s->array) {
			free(s->array);
		}
		free(s);
	}
}

//---------------------------------------------------------------------
//                       4.5.2 动态数组实现 p85
//---------------------------------------------------------------------
// SHOW: SAMPLE [书上版本 整个都是, 变实现变看书]
//------------------------------------------------
//                    型声明
//------------------------------------------------
#define PRO_STACK_SIZE_V2 100
struct dynArrayStack {
	int top;
	int capacity;
	int *array;
};
//------------------------------------------------
//                   函数声明
//------------------------------------------------
struct dynArrayStack *createStackDyn(void);// 创建栈
int isEmptyStackDyn(struct dynArrayStack *s); // 判断是否为空
int isFullStackDyn(struct dynArrayStack *s);// 判断是否已满
void doubleStackDyn(struct dynArrayStack *s); // 双倍栈数据容量
void pushDyn(struct dynArrayStack *s, int data); // push
int topDyn(struct dynArrayStack *s); // top 查看最后一个元素
int popDyn(struct dynArrayStack *s); //pop
void deleteStackDyn(struct dynArrayStack *s); // 删除栈
//------------------------------------------------
//                   函数实现
//------------------------------------------------
struct dynArrayStack *createStackDyn(void) { // 创建栈
	struct dynArrayStack *s = (struct dynArrayStack *)malloc(sizeof(struct dynArrayStack));
	if (s == NULL) {
		puts("动态数组版, 初始化失败");
		return NULL;
	}
	s->capacity = PRO_STACK_SIZE_V2;
	s->top = -1;
	s->array = (int *)malloc(s->capacity * sizeof(int));
	if (s->array == NULL) {
		puts("动态数组版，栈数据初始化失败");
		return NULL;
	}
	return s;
}
int isEmptyStackDyn(struct dynArrayStack *s) { // 判断是否为空
	return s->top == -1;
}
int isFullStackDyn(struct dynArrayStack *s) { // 判断是否已满
	return (s->top == s->capacity-1);
}
void doubleStackDyn(struct dynArrayStack *s) { // 双倍栈数据容量
	s->capacity = s->capacity*2;
	s->array = realloc(s->array, s->capacity);
	if (s->array == NULL) {
		puts("动态数组版，加长栈容量失败");
		return;
	}
}
void pushDyn(struct dynArrayStack *s, int data) { // push
	if (isFullStackDyn(s)) {
		doubleStackDyn(s);
	}
	s->array[++s->top] = data;
}

int topDyn(struct dynArrayStack *s) { // 查看最后一个元素
	if (isEmptyStackDyn(s)) {
		return INT_MIN; // 在limits.h里
	}
	return s->array[s->top];
}
int popDyn(struct dynArrayStack *s) { // pop
	if (isEmptyStackDyn(s)) {
		return INT_MIN;
	}
	return s->array[s->top--];
}
void deleteStackDyn(struct dynArrayStack *s) { // 删除栈
	if (s) {
		if (s->array) {
			free(s->array);
		}
		free(s);
	}
}

//---------------------------------------------------------------------
//                       4.5.3 链表实现 p85
//---------------------------------------------------------------------
// SHOW: SAMPLE [书上版本 整个都是, 变实现变看书]
//------------------------------------------------
//                    型声明
//------------------------------------------------
struct listNodeStack {
	int data;
	struct listNodeStack *next;
};
//------------------------------------------------
//                   函数声明
//------------------------------------------------
//struct listNodeStack *createStackList(void);// 不用创建
int isEmptyStackList(struct listNodeStack *s); // 判断是否为空
//int isFullStackList(struct listNodeStack *s);// 永不满
void pushList(struct listNodeStack **s, int data); // push
int topList(struct listNodeStack *s); // top 查看最后一个元素
int popList(struct listNodeStack **s); //pop
void deleteStackList(struct listNodeStack **s); // 删除栈
//------------------------------------------------
//                   函数实现
//------------------------------------------------
int isEmptyStackList(struct listNodeStack *s) { // 判断是否为空
	return s == NULL;
}
void pushList(struct listNodeStack **s, int data) { // push
	struct listNodeStack *temp;
	temp = (struct listNodeStack *)malloc(sizeof(struct listNodeStack));
	if (temp == NULL) {
		puts("链表版， push， 生成新节点失败");
		return;
	}
	temp->data = data;
	temp->next = *s;
	*s = temp;
}
int topList(struct listNodeStack *s) { // top 查看最后一个元素
	if (isEmptyStackList(s)) {
		return INT_MIN;
	}
	return s->data;
}
int popList(struct listNodeStack **s) { //pop
	struct listNodeStack *temp;
	int data;
	if (isEmptyStackList(*s)) {
		return INT_MIN;
	}
	temp = *s;
	*s = temp->next;
	data = temp->data;
	free(temp);
	return data;
	
}
void deleteStackList(struct listNodeStack **s) { // 删除栈
	struct listNodeStack *current, *temp;
	current = *s;
	while (current) {
		temp = current;
		current = current->next;
		free(temp);
	}
	*s = NULL;
}
//---------------------------------------------------------------------
//                             测试函数
//---------------------------------------------------------------------
void stackTester(void) {
	
}
