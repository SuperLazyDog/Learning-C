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
//                  数据对比函数
//---------------------------------------------
bool compareData_Stack(const Stack_Data *ldata, const Stack_Data *rdata) {//测试专用
	return *ldata == *rdata;
}
//---------------------------------------------
//                  输出格式
//---------------------------------------------
bool showData_Stack(Stack_Data *data) { //测试专用
	printf("%d \n", *data);

//---------------------------------------------
//                  数据对比函数
//---------------------------------------------
bool compareData_Stack(const Stack_Data *ldata, const Stack_Data *rdata);//测试专用
//---------------------------------------------
//                  输出格式
//---------------------------------------------
bool showData_Stack(OpenAdressingHash_Data *data); //测试专用
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
	stack->pointer = 0;
	if (stack == NULL) {
		stack = (Stack *)mallocPro(stack, sizeof(Stack));
		if (stack == NULL) {
			return false;//初始化内存失败
		}
	}
	
	if ((stack->stackList = (Stack_Data *)callocPro(stack->stackList, max, sizeof(Stack_Data))) == NULL) {
		stack->max = 0;
		return false;//堆的数据链内存初始化失败
	}
	stack->max = max;
    return true;
}

//-------------------------------------------------------
//                        Push
//-------------------------------------------------------
bool push_In_Stack(Stack *stack, Stack_Data *data) {
	if (stack->pointer >= stack->max) {
		return false; //堆内数据已满
	}
	stack->stackList[stack->pointer] = *data;
	stack->pointer += 1;
    return true;
}

//-------------------------------------------------------
//                        Pop
//-------------------------------------------------------
bool pop_From_Stack(Stack *stack, Stack_Data *temp) {
	if (stack->pointer <= 0) {
		return false; //堆为空
	}
	*temp = stack->stackList[--pointer];//--pointer 
    return true;
}

//-------------------------------------------------------
//                        Peek
//-------------------------------------------------------
bool peek_at_Stack(const Stack *stack, Stack_Data *temp) {
	if (stack->pointer <= 0) {
		return false; //堆为空
	}
	*temp = stack->stackList[stack->pointer - 1];
    return true;
}

//-------------------------------------------------------
//                        Clear
//-------------------------------------------------------
bool clear_Stack(Stack *stack) {
	stack->pointer = 0;
    return true;
}

//-------------------------------------------------------
//                       获取容量
//-------------------------------------------------------
//# TODO: bool ---> Bool   /Basic Resive/session/Bool.h
Capacity getCapacity_From_Stack(const Stack *stack) {
	if (stack == NULL) { //指定堆不存在
		return (Capacity)false;
	}
	if (stack->max == 0) { //堆是空堆
		return (Capacity)false;
	}
    return false;
}

//-------------------------------------------------------
//                      获取数据数
//-------------------------------------------------------
Size getCount_Of_Data(const Stack *stack) {
	if (stack == NULL) { //指定堆不存在
		return false;
	}

	if (stack->pointer == 0) { //堆是空堆
		return (Size)stack->pointer;
	}

    return stack->pointer;
}

//-------------------------------------------------------
//                       是否空
//-------------------------------------------------------
bool isEmpty_Stack(const Stack *stack) {
	if (stack == NULL) { //指定堆不存在
		return false;
	}
    return (stack->pointer <= 0);
}

//-------------------------------------------------------
//                       是否满
//-------------------------------------------------------
bool isFull_Stack(const Stack *stack) {
	if (stack == NULL) { //指定堆不存在
		return false;
	}
    return (stack->pointer >= stack->max);
}

//-------------------------------------------------------
//                       搜索数据
//-------------------------------------------------------
//# TODO: 搜索顺序: 从头到尾， 从尾到头
bool search_In_Stack(const Stack *stack, const Stack_Data *data, 
			bool compareData_Stack(const Stack_Data *ldata, const Stack_Data *rdata)) {
	int i;
	if (stack == NULL) { //指定堆不存在
		return false;
	}
	for(i=0; i < stack->pointer; i++) {
		if (compareData_Stack(data, &stack->stackList[i])) {
			return true;
		}
    return false; //目标数据不存在
}

//-------------------------------------------------------
//                        表示
//-------------------------------------------------------
bool showStack(const Stack *stack,  bool showData_Stack(Stack_Data *data)) {
	int i;
	if (stack == NULL) { //指定堆不存在
		return false;
	}

	for (i = 0;i < stack->pointer;i++) {
		showData_Stack(&stack->stackList[i]);
		puts("");
	}
    return true;
}

//-------------------------------------------------------
//                        收尾
//-------------------------------------------------------
bool terminate_Stack(Stack *stack) {
	if (stack == NULL) { //指定堆不存在
		return true;
	}
	if (stack->stackList != NULL) {
		free(stack->stackList);
	}
	stack->max = stack->pointer = 0;
    return true;
}
