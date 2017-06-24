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
bool compare(int a, int b);

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
void funcPoinTest(int lsh, int rsh, bool compare(int a, int b)) {
    if((*compare)(lsh, rsh)) {
        printf("a > b\n");
    }else {
        printf("a <= b\n");
    }
}

bool compare(int a, int b) {
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
