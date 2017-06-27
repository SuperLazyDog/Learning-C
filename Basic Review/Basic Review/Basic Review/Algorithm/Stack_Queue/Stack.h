//
//  Stack.h
//  Basic Review
//
//  Created by 徐伟达 on 2017/6/28.
//  Copyright © 2017年 徐伟达. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include <stdio.h>
#include <stdlib.h>
#include "Bool.h"
#include "MemorySet.h"

//# TODO: Hash.h改名---> Hash_Chain.h
//# TODO: 增加备注: Hash_Chain 拉链法   Hash_OpenAdressing 开放寻址法  如这里的线性探测再散列法

//---------------------------------------------------------------------------
//                                  笔记
//---------------------------------------------------------------------------
/*---------------------------------------------------------------------------
 */

//---------------------------------------------------------------------------
//                                堆(stack)
//---------------------------------------------------------------------------
//-------------------------------------------------------
//                       类型定义
//-------------------------------------------------------
//------------------------------
//实际使用时候改变这个定义     散式哈希表处理的数据类型
typedef int Stack_Data;
//------------------------------
typedef int INT;
typedef INT SIZE, LENGTH;
typedef SIZE Size;
typedef LENGTH Length;
typedef INT Capacity;
typedef INT POINTER;


typedef struct {
    Capacity max;
    POINTER pointer;
    Stack_Data *stackList;
} Stack;

//-------------------------------------------------------
//                     需要自定义的函数
//-------------------------------------------------------
//---------------------------------------------
//                获取哈希值的函数
//---------------------------------------------
/*OpenAdressingHash_Key getHashKey_OpenAdressingHash(const OpenAdressingHash_Data *data, SIZE size); // 测试专用
//---------------------------------------------
//                再次哈希值的函数
//---------------------------------------------
OpenAdressingHash_Key getReHashKey_OpenAdressingHash(const OpenAdressingHash_Key key, SIZE size);
//---------------------------------------------
//                  数据对比函数
//---------------------------------------------
bool compareData_OpenAdressingHash(const OpenAdressingHash_Data *ldata, const OpenAdressingHash_Data *rdata);//测试专用
//---------------------------------------------
//                  输出格式
//---------------------------------------------
bool showBucket_OpenAdressingHash(OpenAdressingHash_Data *data);*/

//-------------------------------------------------------
//                     管理测试的函数
//-------------------------------------------------------
void stackTestPro();

//-------------------------------------------------------
//                       初始化
//-------------------------------------------------------
bool initialize_Stack(Stack *stack, Capacity max); // 初始化堆

//-------------------------------------------------------
//                        Push
//-------------------------------------------------------
bool push_In_Stack(Stack *stack, Stack_Data *data);

//-------------------------------------------------------
//                        Pop
//-------------------------------------------------------
bool pop_From_Stack(Stack *stack, Stack_Data *temp);

//-------------------------------------------------------
//                        Peek
//-------------------------------------------------------
bool peek_at_Stack(const Stack *stack, Stack_Data *temp);

//-------------------------------------------------------
//                        Clear
//-------------------------------------------------------
bool clear_Stack(Stack *stack);

//-------------------------------------------------------
//                       获取容量
//-------------------------------------------------------
Capacity getCapacity_From_Stack(const Stack *stack);

//-------------------------------------------------------
//                      获取数据数
//-------------------------------------------------------
Size getCount_Of_Data(const Stack *stack);

//-------------------------------------------------------
//                       是否空
//-------------------------------------------------------
bool isEmpty_Stack(const Stack *stack);

//-------------------------------------------------------
//                       是否满
//-------------------------------------------------------
bool isFull_Stack(const Stack *stack);

//-------------------------------------------------------
//                       搜索数据
//-------------------------------------------------------
Stack_Data *search_In_Stack(const Stack *stack, const Stack_Data *data);

//-------------------------------------------------------
//                        表示
//-------------------------------------------------------
bool showStack(const Stack *stack);

//-------------------------------------------------------
//                        收尾
//-------------------------------------------------------
bool terminate_Stack(Stack *stack);
#endif /* Stack_h */
