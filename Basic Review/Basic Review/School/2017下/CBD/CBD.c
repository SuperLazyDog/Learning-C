//
//  CBD.c
//  Basic Review
//
//  Created by 徐伟达 on 2018/1/17.
//  Copyright © 2018年 徐伟达. All rights reserved.
//

#include "CBD.h"
#include <sys/time.h>
#include <String.h>
#include "Bool.h"

//------------------------------------------------
//                    型声明
//------------------------------------------------
#define CBD_SORT_TEST_MAX (100*100*100)
#define CBD_SORT_TEST_MIDDLE (100*100)
#define CBD_SORT_TEST_SMALL (100)
//------------------------------------------------
//                   函数声明
//------------------------------------------------
int *CBDGetSampleData(int size);
void CBDShowSampleData(int size, int *data);
void CBDSortTest(int size, Bool isBubble);
int time_substract(struct timeval *result, struct timeval *begin,struct timeval *end); //计时
void printTime(struct timeval *diff);
void strat(struct timeval *start);
void over(struct timeval *start, struct timeval *over);
//------------------------------------------------
//                   函数实现
//------------------------------------------------
int *CBDGetSampleData(int size) { // 设置测试数据
	int *temp = (int *)calloc(sizeof(int), size), i;
	for (i=0; i<size; i++) {
		temp[i] = rand();
	}
	return temp;
}

void CBDShowSampleData(int size, int *data) { // 打印测试数据
	int i;
	for (i = 0; i < size; i++) {
		printf("data[%10d]: %d\n", i, data[i]);
	}
	puts("");
}

int time_substract(struct timeval *result, struct timeval *begin,struct timeval *end) { // 计算时间差
	if (begin->tv_sec > end->tv_sec) {
		return -1;
	}
	if ((begin->tv_sec == end->tv_sec) && (begin->tv_usec > end->tv_usec)) {
		return -2;
	}
	result->tv_sec = (end->tv_sec - begin->tv_sec);
	result->tv_usec = (end->tv_usec - begin->tv_usec);
	if (result->tv_usec < 0) {
		result->tv_sec--;
		result->tv_usec += 1000000;
	}
	return 0;
}

void printTime(struct timeval *diff) { // 打印时间
	puts("------------------------------------------------------");
	printf("Total time : %d s,%d us\n",(int)(diff->tv_sec),(int)(diff->tv_usec));
	puts("------------------------------------------------------");
}

void TimerStrat(struct timeval *start) { // 开始计时
	gettimeofday(start,0);
}
void TimerOver(struct timeval *start, struct timeval *stop) { // 结束计时并打印结果
	struct timeval diff;
	memset(&diff,0,sizeof(struct timeval));
	gettimeofday(stop,0);
	time_substract(&diff, start, stop);
	printTime(&diff);
}

void CBDSortTest(int size, Bool isBubble) {
	int *sampleData;
	struct timeval start,stop; //计时器
	memset(&start,0,sizeof(struct timeval));
	memset(&stop,0,sizeof(struct timeval));
	sampleData = CBDGetSampleData(size); //设置测试数据
	CBDShowSampleData(size, sampleData); //打印数据
	if (isBubble) {
		TimerStrat(&start);
		bubbleSort(sampleData, size, true, Default);
	} else {
		TimerStrat(&start);
		quickSort(sampleData, size);
	}
	TimerOver(&start, &stop);
	CBDShowSampleData(size, sampleData); //打印数据
}


void CBDTestSelector(enum CBDItem selector) {
	int size;
	
	switch (selector) {
		case small:
			puts("--------------------------------------------\n");
			puts("                small data");
			puts("--------------------------------------------\n");
			size = CBD_SORT_TEST_SMALL;
			CBDSortTest(size, false);
			break;
		case middle:
			puts("--------------------------------------------\n");
			puts("                middle data");
			puts("--------------------------------------------\n");
			size = CBD_SORT_TEST_MIDDLE;
			break;
		case max:
			puts("--------------------------------------------\n");
			puts("                 max data");
			puts("--------------------------------------------\n");
			size = CBD_SORT_TEST_MAX;
			break;
	}
}
