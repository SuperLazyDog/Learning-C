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
	int *array; // 数据
	int count; // 收容的数据数量
	int capicity; // 可收容的数据容量
	int heap_type; // 堆的种类: 最大堆, 最小堆
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
int deleteMax(struct Heap *h); // 删除元素
void insertIntoHeap(struct Heap *h, int data); // 插入新元素
void insertIntoHeapV2(struct Heap *h, int data); // 优化版 插入新元素
void resizeHeap(struct Heap *h); // 已满的容量变为2倍
void destroyHeap(struct Heap *h); // 删除堆
void buildHeap(struct Heap *h, int A[], int n); // 通过数组构建堆
// 应用: 堆排序
void heapSort(int A[], int n); // 堆排序
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

// 注意: 忘记了数量关系就自己算一遍
// l(o) = (l(A)-1)/2 = (l(b)-2)/2
// l(a) = 2*l(o) + 1
// l(b) = 2*(l)
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

void percolateDown(struct Heap *h, int i) { // 对位置i处的元素进行堆化
	// 注意: 除i外其他所有地方都满足堆
	int l, r, max, temp;
	l = leftChild(h, i);
	r = rightChild(h, i);
	if (l == -1 && r == -1) { // 这个可以不要: 不存在子节点则下面的max = i
		return;
	}
	if (l != -1 && h->array[l] > h->array[i]) { // 左子节点存在且大于当前节点
		max = l;
	} else {
		max = i;
	}
	if (r != -1 && h->array[r] > h->array[max]) { // 右子节点存在且大于 [当前节点, 左子节点].max
		max = r;
	}
	if (max != i) {
		temp = h->array[i];
		h->array[i] = h->array[max];
		h->array[max] = temp;
		percolateDown(h, max);
	} else {
		return;
	}
	
}

int deleteMax(struct Heap *h) { // 删除元素
	int data;
	if (h->count == 0) { // 堆里没有数据
		return -1;
	}
	data = h->array[0];
	h->array[0] = h->array[h->count-1];
	h->count--;
	percolateDown(h, 0);
	return data;
}

void insertIntoHeap(struct Heap *h, int data) { // 插入新元素
	int parentNodeIndex, i;
	if (h->count >= h->capicity-1) {
		resizeHeap(h); // 已满则容量变为2倍
	}
	h->count += 1;
	i = h->count-1;
	h->array[h->count+1] = data;
	parentNodeIndex = parent(h, i);
	while (parentNodeIndex >= 0 && h->array[parentNodeIndex] < h->array[i]) {
		int temp = h->array[i];
		h->array[i] = h->array[parentNodeIndex];
		h->array[parentNodeIndex] = temp;
		i = parentNodeIndex;
		parentNodeIndex = parent(h, i);
	}
}

void insertIntoHeapV2(struct Heap *h, int data) { // 优化版 插入新元素
	int i;
	if (h->count >= h->capicity-1) {
		resizeHeap(h); // 已满则容量变为2倍
	}
	h->count += 1;
	i = h->count-1;
	while (i>=1 && data > h->array[(i-1)/2]) { // 优化逻辑
		h->array[i] = h->array[(i-1)/2];
		i = (i-1)/2;
	}
	h->array[i] = data;
}
	
void resizeHeap(struct Heap *h) { // 已满的容量变为2倍
	int *old_array = h->array, i;
	h->array = (int *)malloc(sizeof(int) * (h->capicity*2));
	if (h->array == NULL) {
		printf("memory error\n");
		return;
	}
	for (i=0; i<h->capicity; i++) {
		h->array[i] = old_array[i];
	}
	h->capicity *= 2;
	free(old_array);
}

void destroyHeap(struct Heap *h) { // 删除堆
	if (h==NULL) {
		return;
	}
	if (h->array == NULL) {
		free(h);
	}
	free(h->array);
	free(h);
	h = NULL;
}

void buildHeap(struct Heap *h, int A[], int n) { // 通过数组构建堆
	int i;
	if (h==NULL) {
		return;
	}
	while (n > h->capicity) {
		resizeHeap(h);
	}
	for (i = 0; i < n; i++) {
		h->count++;
		h->array[i] = A[i];
	}
	for (i = (n-1)/2; i >= 0; i--) {
		percolateDown(h, i);
	}
}
// 应用: 堆排序
void heapSort(int A[], int n) { // 堆排序
	int i;
	struct Heap *h = createHeap(n, 1);
	buildHeap(h, A, n);
	for (i = 0; i < n; i++) {
		A[i] = deleteMax(h);
	}
}

//---------------------------------------------------------------------
//                             测试函数
//---------------------------------------------------------------------
void heapTester() {
	int i;
	int a[8] = {100, 29, 982, 1, 42, 1, 1999, 27};
	heapSort(a, 8);
	for (i = 0; i<sizeof(a)/sizeof(int); i++) {
		printf("a[%d]: %d\n", i, a[i]);
	}
}
