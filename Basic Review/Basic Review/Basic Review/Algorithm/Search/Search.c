//
//  Search.c
//  Basic Review
//
//  Created by 徐伟达 on 2017/6/18.
//  Copyright © 2017年 徐伟达. All rights reserved.
//

#include "Search.h"
#define TESTCOUNT 100000

//---------------------------------------------------------------------------
//                               本地函数声明
//---------------------------------------------------------------------------
Bool setTarget(Bool isOrderd, int num);

//-------------------------------------------------------
//                      共有变量
//-------------------------------------------------------
//          目标
//targetSearch[916]: 624917313
//targetSearch[969]: 942295 二分
int *targetSearch = NULL;//搜索的目标数组
int targetIndex = 0;
int targetNum = 0;
//---------------------------------------------------------------------------
//                                  检索
//---------------------------------------------------------------------------
//-------------------------------------------------------
//                     管理测试的函数
//-------------------------------------------------------
void searchTest(){
    printf("just a test to confirm\n");
    puts("//---------------------------------------------");
    puts("//                set target");
    puts("//---------------------------------------------");
    setTarget(false, TESTCOUNT);
    puts("//---------------------------------------------");
    puts("//                 线性检索");
    puts("//---------------------------------------------");
    lineSearch(targetSearch, TESTCOUNT, 624917313);
    puts("//---------------------------------------------");
    puts("//                 哨兵检索");
    puts("//---------------------------------------------");
    sentinelSearch(targetSearch, TESTCOUNT, 624917313);
    puts("//---------------------------------------------");
    puts("//                二分法检索");
    puts("//----------- ----------------------------------");
    setTarget(true, TESTCOUNT);
    binarySearch(targetSearch, TESTCOUNT, 781);
}

//-------------------------------------------------------
//                      设置目标
//-------------------------------------------------------
Bool setTarget(Bool isOrderd, int num) {
    int i;
    targetSearch = (int *)mallocPro(targetSearch, num*sizeof(int), GETSTR_MEMSET);
    if(targetSearch) {
        //targetSearch = (int *)targetSearch;
        if(!isOrderd) {//无序
            for(i = 0; i < num; i++) {
                targetSearch[i] = rand();
                printf("targetSearch[%d]: %d\n", i, targetSearch[i]);
            }
            return true;
        }else {//升序
            for(i = 0; i < num; i++) {
                targetSearch[i] = i;//i*i + i/2 + i/3.4e-1;
                printf("targetSearch[%d]: %d\n", i, targetSearch[i]);
            }
            return true;
        }
    }
    
    return false;
}

//-------------------------------------------------------
//                      线性搜索
//-------------------------------------------------------
//本来用while的话是哨兵检索的两倍，用了for后基本上一样
Bool lineSearch(const int p[], const int num, const int key) {
    int i;
    for(i = 0; i < num; i++) {
        if(p[i] == key) {
            targetIndex = i;
            targetNum = p[i];
            printf("find!\n");
            printf("targetIndex = %d\ntargetNum = %d\n", targetIndex, targetNum);
            return true;
        }
    }
    return false;
}

//-------------------------------------------------------
//                      哨兵检索
//-------------------------------------------------------
//和上一个基本上也没多大差别
Bool sentinelSearch(int p[], const int num, const int key) {
    int i, temp = p[num-1];
    p[num-1] = key;
    for(i = 0; i < num; i++) {
        if(p[i] == key) {
            targetIndex = i;
            targetNum = p[i];
            break;
        }
    }
    p[num-1] = temp;
    if(i < num-1) {
        printf("find!\n");
        printf("targetIndex = %d\ntargetNum = %d\n", targetIndex, targetNum);
        return true;
    }
    return false;
}

//-------------------------------------------------------
//                      二分法检索
//-------------------------------------------------------
Bool binarySearch(const int p[], const int num, const int key) {
    int lb = 0; //left border
    int rb = num-1; //right border
    int ml;//middle line
    
    do {
        ml = (lb + rb) / 2;
        int temp = p[ml];
        printf("temp = %d\n", temp);
        if(temp == key) {
            targetIndex = ml;
            targetNum = p[ml];
            printf("find!\n");
            printf("targetIndex = %d\ntargetNum = %d\n", targetIndex, targetNum);
            return true;
        }else if(key > temp) {
            lb = ml + 1;
        }else {
            rb = ml - 1;//注意是ml,不要写错
        }
    } while(lb <= rb);
    printf("lb = %d   rb = %d\n", lb, rb);
    return false;
}
// # TODO: 哈希表的检索 p102~137   6E232BC8-AEC4-4264-91C7-95253570F2CB
//---------------------------------------------------------------------------
//                                  笔记
//---------------------------------------------------------------------------
/* 无限循环的实现
 for( ; ; ) {
 ...;
 }
 
 while(true) {
 ...;
 }
 
 do {
 ...
 } while(true);
 */
