//
//  S7_heap.c
//  Basic Review
//
//  Created by 徐伟达 on 2018/5/18.
//  Copyright © 2018年 徐伟达. All rights reserved.
//

#include "S7_heap.h"
//---------------------------------------------------------------------
//                        优先队列与堆   p209~220
//---------------------------------------------------------------------
//---------------------------------------------------------------------
//                       7.5   堆
//---------------------------------------------------------------------
//------------------------------------------------
//                  堆的型声明
//------------------------------------------------
struct Heap {
	int *array;
	int count;
	int capicity;
	int heap_type;
};
//------------------------------------------------
//                   函数声明
//------------------------------------------------
struct Heap *createHeap(int capicity, int heap_type); // 创建堆
int parent(struct Heap *h, int i); // 堆的父节点
int leftChild(struct Heap *h, int i); // 左子节点
int rightChild(struct Heap *h, int i); // 右子节点
int getMaximun(struct Heap *h); // 获取最大节点
void percolateDown(struct Heap *h, int i); // 堆化

//------------------------------------------------
//                   函数实现
//------------------------------------------------
struct Heap *createHeap(int capicity, int heap_type) { // 创建堆
	struct Heap *h = (struct Heap *)malloc(sizeof(struct Heap));
	if (h==NULL) {
		printf("memory error\n");
		return NULL;
	}
	h->heap_type = heap_type;
	h->capicity = capicity;
	h->count = 0;
	h->array = (int *)malloc(sizeof(int)*capicity);
	if (h->array == NULL) {
		printf("memory error");
		return NULL;
	}
	return h;
}

// TODO-PRO: [p213]
int parent(struct Heap *h, int i) { // 堆的父节点
	if (i<0 || i>h->count) {
		return -1;
	}
	return (i-1)/2;
}

int leftChild(struct Heap *h, int i) { // 左子节点
	int left = 2*i+1;
	if (left>h->count) {
		return -1;
	}
	return left;
}
int rightChild(struct Heap *h, int i) { // 右子节点
	int right = 2*i+2;
	if (right>h->count) {
		return -1;
	}
	return right;
}

int getMaximun(struct Heap *h) { // 获取最大节点
	if (h->count == 0) {
		return -1;
	}
	return h->array[0];
}

void percolateDown(struct Heap *h, int i) { // 堆化
	int l, r, max, temp;
	l = leftChild(h, i);
	r = rightChild(h, i);
	if (l != -1 && h->array[l] > h->array[i]) {
		max = l;
	} else {
		max = i;
	}
	
	if (r != -1 && h->array[r] > h->array[max]) {
		max = r;
	}
	if (max != i) {
		temp = h->array[i];
		h->array[i] = h->array[max];
		h->array[max] = temp;
	}
	percolateDown(h, max);
}
//---------------------------------------------------------------------
//                             测试函数
//---------------------------------------------------------------------
void heapTester() {
	
}
