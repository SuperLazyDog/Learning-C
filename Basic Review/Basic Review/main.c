//
//  main.c
//  Basic Review
//
//  Created by 徐伟达 on 2017/6/17.
//  Copyright © 2017年 徐伟达. All rights reserved.
//
//---------------------------------------------------------------------------
//                              标准库头文件
//---------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

//---------------------------------------------------------------------------
//                               功能性头文件
//---------------------------------------------------------------------------
//#include "test.h"//单纯的测试
//#include "Basic.h"//C语言基本复习
//#include "AlgorithmSelector.h"//算法
#include "AlgorithmPro.h"//数据结构与算法 O'REILLY
//#include "CBD.h" // 2017年下 CBD报告
//---------------------------------------------------------------------------
//                               辅助类头文件
//---------------------------------------------------------------------------
//#include "String.h"
//#include "Bool.h"//创建Bool
//#include "MemorySet.h"//安全的动态内存

//---------------------------------------------------------------------------
//                           操控类函数声明与主函数
//---------------------------------------------------------------------------
void basicReviewRunner(void);
void algorithmProRunner(void);
//void cbdReport(void);

int main(int argc, const char * argv[]) {
//    basicReviewRunner(); //第一遍学习
    algorithmProRunner(); //深度学习 数据结构与算法
//	cbdReport(); //CBD报告
    return 0;
}

//---------------------------------------------------------------------------
//                             第一遍学习的内容
//---------------------------------------------------------------------------
void basicReviewRunner() {
    //---------------------------------------------------------------------------
    //                               各种测试
    //---------------------------------------------------------------------------
    //testSelector(second);
    //testSelector(third);
    //testSelector(chainHash);
    //testSelector(memTest);
    //---------------------------------------------------------------------------
    //                               C语言基本复习
    //---------------------------------------------------------------------------
    //basicSelector(1);
    //basicSelector(2);
    //basicSelector(3);
    //basicSelector(4);
    //basicSelector(5);
    //basicSelector(6);
    //basicSelector(7);
    //basicSelector(8);
    
    //basicSelector(10);
    //---------------------------------------------------------------------------
    //                                算法
    //---------------------------------------------------------------------------
    //algorithmSelector(search);
    //algorithmSelector(list);
    //algorithmSelector(tree);
    //algorithmSelector(sampleDataStruct);
    //algorithmSelector(hash);
    //algorithmSelector(hash_OpenAdressing);
    //algorithmSelector(stack);
    //algorithmSelector(queue);
    //algorithmSelector(recurse);
    //algorithmSelector(sort);
}

//---------------------------------------------------------------------------
//                             数据结构与算法
//---------------------------------------------------------------------------
void algorithmProRunner() {
//	AlgorithmProSelector(s2); // 第二章 递归
//	AlgorithmProSelector(s3); // 第三章 链表
//	AlgorithmProSelector(s4); // 第四章 堆
//	AlgorithmProSelector(s5); // 第五章 序列
//	AlgorithmProSelector(s6); // 第六章 树
//	AlgorithmProSelector(s7); // 第七章 优先队列与堆
//	AlgorithmProSelector(s8); // 第八章 互素集合
	AlgorithmProSelector(s9); // 第九章 图论算法
}

//---------------------------------------------------------------------------
//                            2017下 CBD报告
//---------------------------------------------------------------------------
//void cbdReport(void) {
//	puts("---------------------------------------------");
//	puts("                Small-scale Data");
//	puts("                size: 100");
//	puts("---------------------------------------------");
//	CBDTestSelector(small);
//
//	puts("---------------------------------------------");
//	puts("                Medium-scale Data");
//	puts("                size: 10,000");
//	puts("---------------------------------------------");
//	CBDTestSelector(middle);
//
//	puts("---------------------------------------------");
//	puts("                Large-scale Data");
//	puts("                size: 1,000,000");
//	puts("---------------------------------------------");
//	CBDTestSelector(max);
//}

