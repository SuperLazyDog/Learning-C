//
//  test.c
//  Basic Review
//
//  Created by 徐伟达 on 2017/6/17.
//  Copyright © 2017年 徐伟达. All rights reserved.
//

#include "test.h"

//---------------------------------------------------------------------------
//                               本地函数声明
//---------------------------------------------------------------------------
Bool compare(int a, int b);

//-------------------------------------------------------
//                      共有变量
//-------------------------------------------------------



//---------------------------------------------------------------------------
//                               选择器
//---------------------------------------------------------------------------
void testSelector(int num) {
    switch (num) {
        case first:
            break;
        case second:
            funcPoinTest(12, 22, compare);
            break;
        case third:
            pointProTest();
            break;
        case chainHash:
            chainHashProTest();
        case memTest:
            memsetProTest();
            break;
        default:
            break;
    }
}

//-------------------------------------------------------
//                      第一次测试
//-------------------------------------------------------
//int a = 100;
void printA(int num) { //2017/06/17
    printf("%d\n", num);
}


//-------------------------------------------------------
//                       函数指针
//-------------------------------------------------------
void funcPoinTest(int lsh, int rsh, Bool compare(int a, int b)) {
    if((*compare)(lsh, rsh)) {
        printf("a > b\n");
    }else {
        printf("a <= b\n");
    }
}

Bool compare(int a, int b) {
    return a > b;
}


//-------------------------------------------------------
//                      结构体里的指针
//-------------------------------------------------------
typedef struct __Point_Test {
    int a;
    struct __Point_Test *next;
} PointTest;

void pointProTest() {
    PointTest *test = NULL;
    if ((test = (PointTest *)mallocPro(test, sizeof(PointTest *), GETSTR_MEMSET))) {
        puts("success");
        test->a = 1;
        PointTest *temp = test->next;
        if (temp == NULL) {
            printf("failed\n");
        }
    }
    
}

//-------------------------------------------------------
//                       链式哈希表
//-------------------------------------------------------
#define __USE_CHAINHASH
//typedef int ChainHash_Data;

void chainHashProTest() {
    ChainHash table;
    int size = 100;
    Bool result = initialize_ChainHash(&table, size);
    printf("result: %s\n", Bool_STR(result));
    ChainHash_Data i;
    
    for (i = 0; i < 10000; i++) {
        printf("i = %d  ", i);
        insert_Data_ChainHash(&table, &i, chainHash_last, compareData_ChainHash);
    }
    dump_ChainHash(&table, showNode);
    
}

//-------------------------------------------------------
//                         内存
//-------------------------------------------------------
void memsetProTest() {
    int *a = malloc(sizeof(int)*20); //a[20]
    int **b = calloc((unsigned long)20, sizeof(int *));//b[20][20]
    //memset(<#void *__b#>, <#int __c#>, <#size_t __len#>)
    for (int i = 0; i < 20; i++) {
        b[i] = (int *)malloc((sizeof(int)*20));
    }
    b[2][1] = 1;
    printf("b[2][1]: %d\n", b[2][1]);
    free(b);
    free(a);
    return;
}
