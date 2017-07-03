//
//  Recurse.h
//  Basic Review
//
//  Created by 徐伟达 on 2017/7/3.
//  Copyright © 2017年 徐伟达. All rights reserved.
//

#ifndef Recurse_h
#define Recurse_h

#include <stdio.h>
#include "Bool.h"
#include "String.h"
#include "MemorySet.h"
#include "Stack.h"
//---------------------------------------------------------------------------
//                                  笔记
//---------------------------------------------------------------------------
/*---------------------------------------------------------------------------
 */

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
void recurseTest();

//-------------------------------------------------------
//                      求阶乘
//-------------------------------------------------------
unsigned long getFactorial(unsigned long num);

//-------------------------------------------------------
//                      表示数字
//-------------------------------------------------------
//递归法
void numTest_Rescurse(int num);
//去除递归
void numTest_NoRescurse(int num);
#endif /* Recurse_h */
