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
//-------------------------------------------------------
//                       类型定义
//-------------------------------------------------------

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
#define SIZE_SORT 8
    int *sortSample = (int *)calloc(SIZE_SORT, sizeof(int));
    int i;
    for (i = 0; i < SIZE_SORT; i++) {
        sortSample[i] = rand();
    }
    //showAll_Sort(sortSample, SIZE_SORT);
    bubbleSort(sortSample, (unsigned int) SIZE_SORT, true);
    showAll_Sort(sortSample, SIZE_SORT);
}

//-------------------------------------------------------
//                       冒泡排序
//-------------------------------------------------------
Bool bubbleSort(int *data, unsigned int size, Bool beginAtFront) {
    // # TODO: 补充为什么不能同序
    int i, j,count;
    if (data == NULL) {
        return false; //没有排序数据
    }
    if (beginAtFront) { //从头开始
        count = 0;
        for (i = 0; i < size-1; i++) {
            /*for (j = i + 1; j < size; j++) {
                if (data[j-1] > data[j]) {
                    int temp = data[j];
                    data[j] = data[j-1];
                    data[j-1] = temp;
                }
            }*/
            for (j = i; j < size-1-count; j++) {
                if (data[j] > data[j+1]) {
                    //printf("%12d > %12d\n", data[j], data[j+1]);
                    int temp = data[j+1];
                    data[j+1] = data[j];
                    data[j] = temp;
                }else {
                    //printf("%12d < %12d\n", data[j], data[j+1]);
                }
                
            }
            //count++;
            printf("data[%d] = %d\n", size-1-i, data[size-1-i]);
        }//7 6 10 1 2 8
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
}
