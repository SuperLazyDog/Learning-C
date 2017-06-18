//
//  test.h
//  Basic Review
//
//  Created by 徐伟达 on 2017/6/17.
//  Copyright © 2017年 徐伟达. All rights reserved.
//

#ifndef test_h
#define test_h

//标准库头文件
#include <stdio.h>
//功能性头文件
#include "AlgorithmSelector.h"//算法
//辅助类头文件
#include "Bool.h"//创建bool
#include "MemorySet.h"//安全的动态内存



enum test {//选择器的列举型
    first,
    second,
};

//---------------------------------------------------------------------------
//                               选择器
//---------------------------------------------------------------------------
void testSelector(int num);

//-------------------------------------------------------
//                      第一次测试
//-------------------------------------------------------
void printA(int num);
//-------------------------------------------------------
//                       函数指针
//-------------------------------------------------------
void funcPoinTest(int lsh, int rsh, bool compare(int a, int b));

#endif /* test_h */
