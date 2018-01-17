//
//  Sort.c
//  Basic Review
//
//  Created by 徐伟达 on 2017/7/5.
//  Copyright © 2017年 徐伟达. All rights reserved.
//

#include "Sort.h"

//---------------------------------------------------------------------------
//                               排列(sort)
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//                                  笔记
//---------------------------------------------------------------------------
/*---------------------------------------------------------------------------
// !! # TODO: 补充为什么不能同序 36027820-79A9-4F89-B162-6FF58BE8EF19 2017/07/06
   冒泡排序每一轮是把最大/小的移到右/左边, 所以要保证每一次移好以后下一轮剩下的都参与排序
*/
#define swap(type, x, y) do { type t = x; x = y; y = t; } while(false)
//-------------------------------------------------------
//                       类型定义
//-------------------------------------------------------

//-------------------------------------------------------
//                     需要自定义的函数
//-------------------------------------------------------
void showAll_Sort(int *data, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("data[%2d]: %12d\n", i, data[i]);
    }
}

//-------------------------------------------------------
//                       本地函数
//-------------------------------------------------------
void divideArray(int *data);

//-------------------------------------------------------
//                     管理测试的函数
//-------------------------------------------------------
void sortTest() {
#define SIZE_SORT 100
    int *sortSample = (int *)calloc(SIZE_SORT, sizeof(int));
    int i;
    puts("-------------------------------------------------");
    puts("                   冒泡排序");
    puts("-------------------------------------------------");
    for (i = 0; i < SIZE_SORT; i++) {
        sortSample[i] = rand();
    }
    //showAll_Sort(sortSample, SIZE_SORT);
    bubbleSort(sortSample, (unsigned int) SIZE_SORT, false, V3);
    showAll_Sort(sortSample, SIZE_SORT);
    
    puts("-------------------------------------------------");
    puts("                  直接选择排序");
    puts("-------------------------------------------------");
    for (i = 0; i < SIZE_SORT; i++) {
        sortSample[i] = rand();
    }
    straightSelectionSort(sortSample, SIZE_SORT);
    showAll_Sort(sortSample, SIZE_SORT);
    
    puts("-------------------------------------------------");
    puts("                    插入排序");
    puts("-------------------------------------------------");
    for (i = 0; i < SIZE_SORT; i++) {
        sortSample[i] = rand();
    }
    insertSort(sortSample, SIZE_SORT);
    showAll_Sort(sortSample, SIZE_SORT);
    
    puts("-------------------------------------------------");
    puts("                    shell排序");
    puts("-------------------------------------------------");
    for (i = 0; i < SIZE_SORT; i++) {
        sortSample[i] = rand();
    }
    shellSort(sortSample, SIZE_SORT);
    showAll_Sort(sortSample, SIZE_SORT);
    puts("-------------------------------------------------");
    puts("                     快速排序");
    puts("-------------------------------------------------");
    quickSort(NULL, (unsigned long)false);
}

//-------------------------------------------------------
//                       冒泡排序
//-------------------------------------------------------

Bool bubbleSort(int *data, unsigned int size, Bool beginAtFront, enum Version_Bubble_Sort version) {
    // !! # TODO: 补充为什么不能同序 36027820-79A9-4F89-B162-6FF58BE8EF19
    int i, j;
    int count = 0;
    int k = 0;
    if (data == NULL) {
        return false; //没有排序数据
    }
    switch (version) {
        case V2:
            if (beginAtFront) { //从头开始
                for (i = size; i > 0 ; i--) {
                    Bool hasChanged = false;
                    for (j = 1; j < i; j++) {
                        if (data[j-1] > data[j]) {
                            //printf("%d > %d\n", data[j-1], data[j]);
                            int temp = data[j];
                            data[j] = data[j-1];
                            data[j-1] = temp;
                            hasChanged = true;
                        }
                    }
                    count++;
                    printf("count %d, hasChanged %s\n", count, Bool_STR(hasChanged));
                    //printf("count %d\n", count);
                    if (hasChanged == false) {
                        break;
                    }
                }
                return true;
            }else { //从尾开始
                for (i = 0; i < size-1; i++) {
                    Bool hasChanged = false;
                    for (j = size-1; j > i; j--) {
                        if (data[j-1] > data[j]) {
                            //printf("%d > %d\n", data[j-1], data[j]);
                            int temp = data[j];
                            data[j] = data[j-1];
                            data[j-1] = temp;
                            hasChanged = true;
                        }
                    }
                    count++;
                    printf("count %d, hasChanged %s\n", count, Bool_STR(hasChanged));
                    //printf("count %d\n", count);
                    if (hasChanged == false) {
                        break;
                    }
                }
                return false;
            }
            return true;
        case V3:
            if (beginAtFront) { //从头开始
                for (i = size; i > k;) {
                    Bool hasChanged = false;
                    k = i;
                    for (j = 1; j < i; j++) {
                        if (data[j-1] > data[j]) {
                            //printf("%d > %d\n", data[j-1], data[j]);
                            int temp = data[j];
                            data[j] = data[j-1];
                            data[j-1] = temp;
                            k = j;
                            hasChanged = true;
                        }
                    }
                    count++;
                    printf("count %d, hasChanged %s\n", count, Bool_STR(hasChanged));
                    //printf("count %d\n", count);
                    if (hasChanged == false) {
                        break;
                    }
                }
                return true;
            }else { //从尾开始
                k = size - 1;
                for (i = 0; i < size-1; i++) {
                    Bool hasChanged = false;
                    for (j = size-1; j > 0; j--) {
                        if (data[j-1] > data[j]) {
                            //printf("%d > %d\n", data[j-1], data[j]);
                            int temp = data[j];
                            data[j] = data[j-1];
                            data[j-1] = temp;
                            hasChanged = true;
                            k = j;
                        }
                    }
                    i = k;
                    count++;
                    printf("count %d, hasChanged %s, k %d\n", count, Bool_STR(hasChanged), k);
                    //printf("count %d\n", count);
                    if (hasChanged == false) {
                        break;
                    }
                }
                return true;
            }
            return false;
        case V1://默认版本,没有任何改进
        case Default:
        default:
            if (beginAtFront) { //从头开始
                for (i = size-1; i >= 0 ; i--) {
                    for (j = 1; j < i; j++) {
                        if (data[j-1] > data[j]) {
                            int temp = data[j];
                            data[j] = data[j-1];
                            data[j-1] = temp;
                        }
                    }
                }
                return true;
            }else { //从尾开始
                for (i = 0; i < size-1; i++) {
                    for (j = size-1; j > i; j--) {
                        if (data[j-1] > data[j]) {
                            printf("%d > %d\n", data[j-1], data[j]);
                            int temp = data[j];
                            data[j] = data[j-1];
                            data[j-1] = temp;
                        }
                    }
                }
                return false;
            }
            break;
    }
    return false;
    
}

//-------------------------------------------------------
//                     直接选择排序
//-------------------------------------------------------
//straight selection sort
Bool straightSelectionSort(int *data, unsigned long size) {
    int i, j;
    
    for (i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (j = i + 1; j < size; j++) {
            if (data[minIndex] > data[j]) {
                minIndex = j;
            }
        }
        int temp = data[i];
        data[i] = data[minIndex];
        data[minIndex] = temp;
    }
    return true;
}

//-------------------------------------------------------
//                      插入排序
//-------------------------------------------------------
//shuttle sort
Bool insertSort(int *data, unsigned long size) {
    int i, j, temp;
    
    //冒泡排序升级版
    /*for (i = 1; i < size; i++) {
        for (j = i; j >= 1; j--) {
            if (data[j] < data[j-1]) {
                int temp = data[j];
                data[j] = data[j-1];
                data[j-1] = temp;
            }
        }
    }*/
    //真插入排序
    for (i = 1; i < size; i++) {
        temp = data[i];
        for (j = i; j >= 1; j--) {
            if (data[j-1] > temp) {
                data[j] = data[j-1];
            }else {
                break;
            }
        }
        data[j] = temp;
    }
    
    return true;
}

//-------------------------------------------------------
//                     shell排序
//-------------------------------------------------------
//shell sort
// # TODO 自己重新实现shell排序
Bool shellSort(int *data, unsigned long size) {
    unsigned long i, h, j;

    for (h = size/2; h > 0; h /= 2) {
        for (i = h; i < size; i++) {
            int temp = data[i];
            //for (j = i-h; j >= 1; j -= h) {  //错了!!!这一种是看的前一个，所以第一个也要取到
            //for (j = i-h; j >= 0; j -= h) { //Xcode bug，这样会警告，把【>= 0】改成【> -1】
            /*for (j = i-h; j >= 0; j -= h) {
                if (temp >= data[j]) {
                    break;
                }else {
                    data[j+h] = data[j];
                }
            }
            data[j+h] = temp;*/
            
            
            for (j = i; j >= h; j -= h) {
                if (temp < data[j-h]) {
                    data[j] = data[j-h];
                }else {
                    break;
                }
            }
            data[j] = temp;
        }
    }
    return true;
}

//-------------------------------------------------------
//                      快速排序
//-------------------------------------------------------
//quick sort
// 1 14 17 8 8  8 9 3 1
// 1 1  17 8 8  8 9 3 14
// 1 1  3  8 8  8 9 17 14
// 1 1  3  8‘8‘’8’9 17 14
void divideArray(int *data) {//本地函数，分割数列测试
//    puts("测试");
}


//Bool quickSort(int *data, unsigned long size) {

//    divideArray(NULL);
//    return false;
	// TODO: 完成自己的版本
void quickSort(int *data, unsigned long size) {
	// 下面版本为CBD报告测试用 https://www.cnblogs.com/landpack/p/4781579.html
	int i, j, p, tmp;
	if (size < 2)  return;
	
	p = data[size / 2];
	
	for ( i = 0, j = (int)size -1;; i++, j--) {
		while (data[i] < p)
			i++;
		while (p < data[j])
			j--;
		if ( i >= j)
			break;
		tmp = data[i]; data[i] = data[j]; data[j] = tmp;
	}
	quickSort( data, i);
	quickSort( data + i, size - i);
}
