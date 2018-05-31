//
//  S8_set.c
//  Basic Review
//
//  Created by 徐伟达 on 2018/6/1.
//  Copyright © 2018年 徐伟达. All rights reserved.
//

#include "S8_set.h"
//---------------------------------------------------------------------
//                        互素集合   p231~241
//---------------------------------------------------------------------
//---------------------------------------------------------------------
//                        8.4   互素集合的实现
//---------------------------------------------------------------------
//------------------------------------------------
//              Fast Union(Slow FIND)
//------------------------------------------------
// Slow FIND的不足
// 歪木多，find效率低 O(n)
//函数声明
void makeSet_SlowFind(int s[], int size);
int find_SlowFind(int s[], int size, int x);
void union_SlowFind(int s[], int size, int root1, int root2);

//实现
void makeSet_SlowFind(int s[], int size) {
	int i;
	for (i=0; i<size; i++) {
		s[i] = i;
	}
}

int find_SlowFind(int s[], int size, int x) { // 获取含有x元素的集合的名字
	if (!(x>=0 && x<size)) {
		return -1;
	}
	if (s[x] == x) {
		return x;
	} else {
		return find_SlowFind(s, size, s[x]);
	}
}

void union_SlowFind(int s[], int size, int root1, int root2) { // 往前并
	int group1 = find_SlowFind(s, size, root1);
	int group2 = find_SlowFind(s, size, root2);
	if (group1 == -1 || group2 == -1) { // 有无效值
		printf("item invalid\n");
		return;
	}
	if (group1 == group2) {
		return;
	}
	s[group2] = s[group1];
}
//------------------------------------------------
//              Fast Union(Quick FIND)
//------------------------------------------------
// 根据集合的size来
// 对应值为负的是集合名
// 函数声明
void makeSet_QuickFind(int s[], int size);
int find_QuickFind(int s[], int size, int x);
void union_QuickFind(int s[], int size, int root1, int root2);
// 实现
void makeSet_QuickFind(int s[], int size) {
	int i;
	for (i=0; i<size; i++) {
		s[i] = -1;
	}
}
int validValue = 100000000;
int find_QuickFind(int s[], int size, int x) {
	if (!(x>=0 && x<size)) {
		return validValue; // 错误值
	}
	if (s[x] < 0) {
		return x;
	} else {
		return find_QuickFind(s, size, s[x]);
	}
}
void union_QuickFind(int s[], int size, int root1, int root2) { // 并入大的一方
	int group1 = find_QuickFind(s, size, root1);
	int group2 = find_QuickFind(s, size, root2);
	if (group1 == validValue || group2 == validValue) { // 有无效值
		printf("item invalid\n");
		return;
	}
	if (group1 == group2) { // 处于同一个集合
		return;
	}
	if (s[group2] < s[group1]) { // root2元素更多
		s[group2] += s[group1];
		s[group1] = group2;
	} else { // root1元素更多或者一样多
		s[group1] += s[group2];
		s[group2] = group1;
	}
	
}

// 压缩路线
int find_QuickFind_Better(int s[], int size, int x) {
	if (!(x>=0 && x<size)) {
		return validValue; // 错误值
	}
	if (s[x] < 0) {
		return x;
	} else {
		s[x] = find_QuickFind(s, size, s[x]);
		return s[x];
	}
}
//---------------------------------------------------------------------
//                             测试函数
//---------------------------------------------------------------------
void s8ShowArray(int *arr, char *arrName);
void setTester() {
	int sampleData[12];
	makeSet_QuickFind(sampleData, 12);
	union_QuickFind(sampleData, 12, 9, 1);
	union_QuickFind(sampleData, 12, 11, 1);
	union_QuickFind(sampleData, 12, 10, 8);
	union_QuickFind(sampleData, 12, 10, 1);
	s8ShowArray(sampleData, "sampleData");
}

void s8ShowArray(int *arr, char *arrName) {
	int i;
	for (i = 0; i<12; i++) {
		printf("%s[%d]: %d\n", arrName, i, arr[i]);
	}
}
