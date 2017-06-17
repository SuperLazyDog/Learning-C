//
//  Search.c
//  Basic Review
//
//  Created by 徐伟达 on 2017/6/18.
//  Copyright © 2017年 徐伟达. All rights reserved.
//

#include "Search.h"
#define TESTCOUNT 1000

//---------------------------------------------------------------------------
//                               本地函数声明
//---------------------------------------------------------------------------
bool setTarget(bool isOrderd, int num);

//-------------------------------------------------------
//                      共有变量
//-------------------------------------------------------
int *targetSearch = NULL;//搜索的目标数组，目标targetSearch[916]: 624917313
int targetIndex = 0;
int targetNum = 0;
//---------------------------------------------------------------------------
//                                  探索
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
    puts("//                 线性探索");
    puts("//---------------------------------------------");
    lineSearch(targetSearch, TESTCOUNT, 624917313);
    puts("//---------------------------------------------");
    puts("//                 哨兵探索");
    puts("//---------------------------------------------");
    sentinelSearch(targetSearch, TESTCOUNT, 624917313);
}

//-------------------------------------------------------
//                      设置目标
//-------------------------------------------------------
bool setTarget(bool isOrderd, int num) {
    int i;
    targetSearch = (int *)mallocPro(targetSearch, num*sizeof(int));
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
                targetSearch[i] = i*i + i/2 + i/3.4e-1;
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
//本来用while的话是哨兵探索的两倍，用了for后基本上一样
bool lineSearch(const int p[], const int num, const int key) {
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
//                      哨兵探索
//-------------------------------------------------------
//和上一个基本上也没多大差别
bool sentinelSearch(int p[], const int num, const int key) {
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
//                      二叉探索
//-------------------------------------------------------

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
