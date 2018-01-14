//
//  S2_Recursion.c
//  Basic Review
//
//  Created by 徐伟达 on 2018/1/14.
//  Copyright © 2018年 徐伟达. All rights reserved.
//

#include "S2_Recursion.h"

//---------------------------------------------------------------------
//                           递归 p31
//---------------------------------------------------------------------
//------------------------------------------------
//                    型声明
//------------------------------------------------
typedef enum {
	departure,
	auxiliary,
	destination
} typeOfHanoi;
//------------------------------------------------
//                   函数声明
//------------------------------------------------
unsigned long fact(unsigned long int n);
int printRecursion(int n);
int printRecursion_r(int n);
void towerOfHanoi(int n, typeOfHanoi from, typeOfHanoi auxiliary, typeOfHanoi destination);
char *getStrOfHanoi(typeOfHanoi type);
//------------------------------------------------
//                   阶乘 p32
//------------------------------------------------
// n! = n(n-1)(n-2)....(1)
// 0! = 1
unsigned long fact(unsigned long int n) {
	// SHOW: SAMPLE [书上版本]
	if (n == 1) {
		return 1;
	} else if (n == 0) {
		return 1;
	} else {
		return n*fact(n-1);
	}
}

//------------------------------------------------
//                 可视化的打印 p32
//------------------------------------------------
int printRecursion(int n) {
	// SHOW: SAMPLE [书上版本]
	if (n == 0) {
		printf("\nover\n");
		return 0;
	} else {
		printf("%d ", n);
		return printRecursion(n-1);
	}
}

//------------------------------------------------
//                  汉诺塔 p32
//------------------------------------------------
int countOfHanoi = 0;
void towerOfHanoi(int n, typeOfHanoi from, typeOfHanoi auxiliary, typeOfHanoi destination) {
	// SHOW: SELF
	if (n==1) {
		countOfHanoi++;
		printf("第%d个: %s -> %s\n", n, getStrOfHanoi(from), getStrOfHanoi(destination));
		return;
	}
	// 上方开始n-1个移到辅助位置
	towerOfHanoi(n-1, from, destination, auxiliary);
	//最底下的一个移到目的地
	countOfHanoi++;
	printf("第%d个: %s -> %s\n", n, getStrOfHanoi(from), getStrOfHanoi(destination));
	// n-1个从辅助位置移到目的地
	towerOfHanoi(n-1, auxiliary, from, destination);
}

char *getStrOfHanoi(typeOfHanoi type) {
	switch (type) {
		case departure:
			return "A";
		case auxiliary:
			return "B";
		case destination:
			return "C";
		default:
			return "";
	}
}
//---------------------------------------------------------------------
//                             回溯 p36
//---------------------------------------------------------------------
//------------------------------------------------
//                    型声明
//------------------------------------------------

//------------------------------------------------
//                   函数声明
//------------------------------------------------
void binary(int n, int *dataSource, int originN);
//------------------------------------------------
//             生成长度n的2进制列 p36
//------------------------------------------------
//TODO-PRO: PREC [2-2 p36]
void binary(int n, int *dataSource, int originN) {
	if (n<1) {
//		printf("1%s\n", (char *)dataSource); // 这个有问题，要像下面这样
//		printf("a[0]: %d, a[1]: %d, a[2]: %d, a[3]: %d\n", dataSource[0], dataSource[1], dataSource[2], dataSource[3]);
		int i;
		for (i = 0; i < originN; i++) {
			printf("a[%d]: %d ", i, dataSource[i]);
		}
		puts("");
	}else {
		dataSource[n-1] = 0;
		binary(n-1, dataSource, originN);
		dataSource[n-1] = 1;
		binary(n-1, dataSource,originN);
	}
}
//------------------------------------------------
//             生成长度n的k进制列 p36
//------------------------------------------------
//TODO-PRO: add [补充这一题 2-3 p36]
//---------------------------------------------------------------------
//                             测试函数
//---------------------------------------------------------------------
void recursionTester(void) {
	//------------------------------------------------
	//                     阶乘
	//------------------------------------------------
//	unsigned long int n;
//	printf("输入你的n:");
//	scanf("%lu", &n);
//	printf("你输入的n: %lu\n", n);
//	unsigned long int result = fact(n);
//	printf("fact(%lu) = %lu\n", n, result);
	
	//------------------------------------------------
	//                100到1的逆序打印
	//------------------------------------------------
//	printRecursion(100);
	
	//------------------------------------------------
	//                  汉诺塔测试
	//------------------------------------------------
//	towerOfHanoi(20, departure, auxiliary, destination);
//	printf("步数: %d\n", countOfHanoi);
	
	//------------------------------------------------
	//                  2进制列测试
	//------------------------------------------------
//	int *a = (int *)calloc(sizeof(int), 8);
//	binary(8, a, 8);
}
