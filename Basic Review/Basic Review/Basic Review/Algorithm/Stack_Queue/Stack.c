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
Bool compareData_Stack(const Stack_Data *ldata, const Stack_Data *rdata) {//测试专用
	return *ldata == *rdata;
}
//---------------------------------------------
//                  输出格式
//---------------------------------------------
Bool showData_Stack(Stack_Data *data) { //测试专用
	printf("%d \n", *data);
    return true;
}

//---------------------------------------------
//                  数据对比函数
//---------------------------------------------
Bool compareData_Stack(const Stack_Data *ldata, const Stack_Data *rdata);//测试专用
//---------------------------------------------
//                  输出格式
//---------------------------------------------
Bool showData_Stack(Stack_Data *data); //测试专用
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
 Bool compareData_OpenAdressingHash(const OpenAdressingHash_Data *ldata, const OpenAdressingHash_Data *rdata);//测试专用
 //---------------------------------------------
 //                  输出格式
 //---------------------------------------------
 Bool showBucket_OpenAdressingHash(OpenAdressingHash_Data *data);*/

//-------------------------------------------------------
//                     管理测试的函数
//-------------------------------------------------------
void stackTest() {
    
}

//-------------------------------------------------------
//                       初始化
//-------------------------------------------------------
Bool initialize_Stack(Stack *stack, Capacity max) { // 初始化堆
	stack->pointer = 0;
	if (stack == NULL) {
		stack = (Stack *)mallocPro(stack, sizeof(Stack), GETSTR_MEMSET);
		if (stack == NULL) {
			return false;//初始化内存失败
		}
	}
	
	if ((stack->stackList = (Stack_Data *)callocPro(stack->stackList, max, sizeof(Stack_Data), GETSTR_MEMSET)) == NULL) {
		stack->max = 0;
		return false;//堆的数据链内存初始化失败
	}
	stack->max = max;
    return true;
}

//-------------------------------------------------------
//                        Push
//-------------------------------------------------------
Bool push_In_Stack(Stack *stack, Stack_Data *data) {
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
Bool pop_From_Stack(Stack *stack, Stack_Data *temp) {
	if (stack->pointer <= 0) {
		return false; //堆为空
	}
	*temp = stack->stackList[--stack->pointer];//--pointer
    return true;
}

//-------------------------------------------------------
//                        Peek
//-------------------------------------------------------
Bool peek_at_Stack(const Stack *stack, Stack_Data *temp) {
	if (stack->pointer <= 0) {
		return false; //堆为空
	}
	*temp = stack->stackList[stack->pointer - 1];
    return true;
}

//-------------------------------------------------------
//                        Clear
//-------------------------------------------------------
Bool clear_Stack(Stack *stack) {
	stack->pointer = 0;
    return true;
}

//-------------------------------------------------------
//                       获取容量
//-------------------------------------------------------
// # TODO: bool ---> Bool   /Basic Resive/session/Bool.h  4BA881E8-B763-462C-9A8F-102DB615D585
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
Bool isEmpty_Stack(const Stack *stack) {
	if (stack == NULL) { //指定堆不存在
		return false;
	}
    return (stack->pointer <= 0);
}

//-------------------------------------------------------
//                       是否满
//-------------------------------------------------------
Bool isFull_Stack(const Stack *stack) {
	if (stack == NULL) { //指定堆不存在
		return false;
	}
    return (stack->pointer >= stack->max);
}

//-------------------------------------------------------
//                       搜索数据
//-------------------------------------------------------
// # TODO: 搜索顺序: 从头到尾， 从尾到头  D8216609-5979-4D8B-8BEB-7985B85D9E2C
POINTER search_In_Stack(const Stack *stack, const Stack_Data *data, 
			Bool compareData_Stack(const Stack_Data *ldata, const Stack_Data *rdata)) {
	int i;
	if (stack == NULL) { //指定堆不存在
		return (POINTER)false;
	}
	for(i=0; i < stack->pointer; i++) {
		if (compareData_Stack(data, &stack->stackList[i])) {
			return (POINTER)i;
		}
    }
    return (POINTER)false; //目标数据不存在
}

//-------------------------------------------------------
//                        表示
//-------------------------------------------------------
// # TODO: 表示顺序: 从头到尾， 从尾到头  625B74F1-2CC4-487D-8796-A1B6276B87EE
Bool showStack(const Stack *stack,  Bool showData_Stack(Stack_Data *data)) {
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
Bool terminate_Stack(Stack *stack) {
	if (stack == NULL) { //指定堆不存在
		return true;
	}
	if (stack->stackList != NULL) {
		free(stack->stackList);
	}
	stack->max = stack->pointer = 0;
    return true;
}
