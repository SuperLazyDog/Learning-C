//
//  S4_Stack.h
//  Basic Review
//
//  Created by 徐伟达 on 2018/1/15.
//  Copyright © 2018年 徐伟达. All rights reserved.
//
/*---------------------------------------------------------------------
						    第四章 任务表
 -----------------------------------------------------------------------
 
 ---------------------------------------------------------------------*/
#ifndef S4_Stack_h
#define S4_Stack_h

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
//---------------------------------------------------------------------
//               	数据结构与算法 第四章 栈  p81~109
//---------------------------------------------------------------------
void stackTester(void);


// 20180510 为了树结构
//------------------------------------------------
//                    型声明
//------------------------------------------------
#define PRO_STACK_SIZE_V1 100
struct arrayStack {
	int top; //开头的索引
	int capacity; // 容量
	int *array;
};
//------------------------------------------------
//                   函数声明
//------------------------------------------------
struct arrayStack *createStack(void);// 创建栈
int isEmptyStack(struct arrayStack *s); // 判断是否为空
int isFullStack(struct arrayStack *s);// 判断是否已满
void push(struct arrayStack *s, int data); // push
int pop(struct arrayStack *s); //pop
void deleteStack(struct arrayStack *s); // 删除栈
#endif /* S4_Stack_h */
