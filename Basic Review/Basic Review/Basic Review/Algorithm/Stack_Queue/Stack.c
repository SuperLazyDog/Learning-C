//
//  Stack.c
//  Basic Review
//
//  Created by 徐伟达 on 2017/6/28.
//  Copyright © 2017年 徐伟达. All rights reserved.
//

#include "Stack.h"


//---------------------------------------------------------------------------
//                                堆(stack)
//---------------------------------------------------------------------------

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
void stackTestPro() {
    
}

//-------------------------------------------------------
//                       初始化
//-------------------------------------------------------
bool initialize_Stack(Stack *stack, Capacity max) { // 初始化堆
	
	if (stack == NULL) {
		stack = (Stack *)mallocPro(stack, sizeof(Stack));
		if (stack == NULL) {
			return false;//初始化内存失败
		}
	}
	
	if ((stack->stackList = (Stack_Data *)callocPro(stack->stackList, max, sizeof(Stack_Data))) == NULL) {
		return false;//堆的数据链内存初始化失败
	}
	stack->max = max;
    return true;
}

//-------------------------------------------------------
//                        Push
//-------------------------------------------------------
bool push_In_Stack(Stack *stack, Stack_Data *data) {
    return false;
}

//-------------------------------------------------------
//                        Pop
//-------------------------------------------------------
bool pop_From_Stack(Stack *stack, Stack_Data *temp) {
    return false;
}

//-------------------------------------------------------
//                        Peek
//-------------------------------------------------------
bool peek_at_Stack(const Stack *stack, Stack_Data *temp) {
    return false;
}

//-------------------------------------------------------
//                        Clear
//-------------------------------------------------------
bool clear_Stack(Stack *stack) {
    return false;
}

//-------------------------------------------------------
//                       获取容量
//-------------------------------------------------------
Capacity getCapacity_From_Stack(const Stack *stack) {
    return false;
}

//-------------------------------------------------------
//                      获取数据数
//-------------------------------------------------------
Size getCount_Of_Data(const Stack *stack) {
    return false;
}

//-------------------------------------------------------
//                       是否空
//-------------------------------------------------------
bool isEmpty_Stack(const Stack *stack) {
    return false;
}

//-------------------------------------------------------
//                       是否满
//-------------------------------------------------------
bool isFull_Stack(const Stack *stack) {
    return false;
}

//-------------------------------------------------------
//                       搜索数据
//-------------------------------------------------------
Stack_Data *search_In_Stack(const Stack *stack, const Stack_Data *data) {
    return NULL;
}

//-------------------------------------------------------
//                        表示
//-------------------------------------------------------
bool showStack(const Stack *stack) {
    return false;
}

//-------------------------------------------------------
//                        收尾
//-------------------------------------------------------
bool terminate_Stack(Stack *stack) {
    return false;
}
