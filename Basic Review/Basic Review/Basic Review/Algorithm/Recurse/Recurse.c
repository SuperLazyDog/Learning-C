//
//  Recurse.c
//  Basic Review
//
//  Created by 徐伟达 on 2017/7/3.
//  Copyright © 2017年 徐伟达. All rights reserved.
//

#include "Recurse.h"

//---------------------------------------------------------------------------
//                               递归(recurse)
//---------------------------------------------------------------------------
//-------------------------------------------------------
//                       类型定义
//-------------------------------------------------------

//-------------------------------------------------------
//                     需要自定义的函数
//-------------------------------------------------------

//-------------------------------------------------------
//                     管理测试的函数
//-------------------------------------------------------
#define TEST_I_RECURSE 4
void recurseTest() {
    //-----------------------------------------------
    //                    阶乘
    //-----------------------------------------------
    unsigned long testNum = TEST_I_RECURSE;
    printf("result: %lu\n", getFactorial(testNum));
    
    //-----------------------------------------------
    //                    阶乘
    //-----------------------------------------------
    puts("------------------------------");
    puts("          递归数字测试");
    puts("------------------------------");
    numTest_Rescurse(4);
    
    puts("------------------------------");
    puts("           非递归数字测试");
    puts("------------------------------");
    numTest_NoRescurse(4);
}

//-------------------------------------------------------
//                      求阶乘
//-------------------------------------------------------
// n! = n(n-1)(n-2) *** 3*2*1
unsigned long getFactorial(unsigned long num) {
    if (num == 1) {
        return 1;
    }
    return num * getFactorial(num-1);
}

//-------------------------------------------------------
//                      表示数字
//-------------------------------------------------------
//递归法
void numTest_Rescurse(int num) {
    if (num > 0) {
        numTest_Rescurse(num-1);
        printf("num: %d\n", num);
        numTest_Rescurse(num-2);
    }
}
//去除递归
void numTest_NoRescurse(int num) {
    Stack stack;
    Capacity max = 100;
    initialize_Stack(&stack, max);
Sample:
    if (num > 0) {
        push_In_Stack(&stack, (Stack_Data *)&num);
        num = num - 1;
        goto Sample;
    }
    if (isEmpty_Stack(&stack) == false) {
        pop_From_Stack(&stack, &num);
        printf("num: %d\n", num);
        num = num - 2;
        goto Sample;
    }
    terminate_Stack(&stack);
/*Sample:
    if (num > 0) {
        numTest_NoRescurse(num-1);
        printf("num: %d\n", num);
        num = num - 2;
        goto Sample;
    }*/
    
    /*while (num > 0) {
        numTest_NoRescurse(num-1);
        printf("num: %d\n", num);
        num = num - 2;
    }*/
}
