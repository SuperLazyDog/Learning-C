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
//-------------------------------------------------------
//                       类型定义
//-------------------------------------------------------
enum Version_Bubble_Sort {
    V1,
    V2,
    V3,
    Default
};
//-------------------------------------------------------
//                     需要自定义的函数
//-------------------------------------------------------
void showAll_Sort(int *data, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("data[%d]: %d\n", i, data[i]);
    }
}
//-------------------------------------------------------
//                     管理测试的函数
//-------------------------------------------------------
void sortTest() {
#define SIZE_SORT 100
    int *sortSample = (int *)calloc(SIZE_SORT, sizeof(int));
    int i;
    for (i = 0; i < SIZE_SORT; i++) {
        sortSample[i] = rand();
    }
    //showAll_Sort(sortSample, SIZE_SORT);
    bubbleSort(sortSample, (unsigned int) SIZE_SORT, false, V3);
    showAll_Sort(sortSample, SIZE_SORT);
}

//-------------------------------------------------------
//                       冒泡排序
//-------------------------------------------------------

Bool bubbleSort(int *data, unsigned int size, Bool beginAtFront, int version) {
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
//                       冒泡排序
//-------------------------------------------------------
