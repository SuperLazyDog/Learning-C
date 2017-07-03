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
    //-----------------------------------------------
    //                    阶乘
    //-----------------------------------------------
    puts("------------------------------");
    puts("            汉诺塔");
    puts("------------------------------");
    process_tower_hanoi(5, 1, 3);
    //-----------------------------------------------
    //                    八王妃
    //-----------------------------------------------
    puts("------------------------------");
    puts("            八王妃");
    puts("------------------------------");
    setQueue(0);
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

//-------------------------------------------------------
//                       哈诺塔
//-------------------------------------------------------
//把最后一个以外的往中间移
//把最后一个移到右边
//把中间的移到右边
void process_tower_hanoi(int num, int start, int destination) {
    if (num > 1) {
        process_tower_hanoi(num - 1, start, 6-start-destination);
    }
    printf("圆盘%d 从 %d 到 %d \n", num, start, destination);
    if (num > 1) {
        process_tower_hanoi(num - 1, 6 - start - destination, destination);
    }
}

//-------------------------------------------------------
//                       八王妃
//-------------------------------------------------------
int rows_Of_Cols[8];
int result_queue = 0;
Bool hasSet_Of_Rows[8] = { false, false, false, false, false, false, false, false }; //行
Bool hasSet_Of_Slash[15] = { false, false, false, false, false, false, false, false }; //   /列
Bool hasSet_Of_BackSlash[15] = { false, false, false, false, false, false, false, false }; //  \列
#define SIZE_QUEUE 8
#define ISBRIEF_SHOWMAP_QUEUE true
//---------------------------------
//           各列放一个
//---------------------------------
//展示地图
int id_Result_Queue = 1;
void showMap_Queue(Bool isBrief) {
    int i;
    char *mark = "□";
    char *target = "■";
    if (isBrief) {
        for (i = 0; i < SIZE_QUEUE; i++) {
            printf("%2d", rows_Of_Cols[i]);
        }
        putchar('\n');
    }else {
        int j = 0;
        puts("--------------------------------");
        //printf("         id: %d\n", id_Result_Queue++);
        for (i = 0; i < SIZE_QUEUE; i++) {//列
            printf("       ");
            for (j = 0; j < SIZE_QUEUE; j++) {//行
                if (j == rows_Of_Cols[i]) {
                    printf("%s ", target);
                }else {
                    printf("%s ", mark);
                }
            }
            putchar('\n');
            
        }
    }
    
}
//设置地图
void setQueue(int colum) {
    int i;//第n行
    for (i = 0; i < SIZE_QUEUE; i++) {
        if ((hasSet_Of_Rows[i] == false) && (hasSet_Of_Slash[i + colum] == false) && (hasSet_Of_BackSlash[colum - i + 7] == false)) {
            rows_Of_Cols[colum] = i;
            if (colum >= 7) {
                result_queue++;
                showMap_Queue(false);
            }else {
                hasSet_Of_Rows[i] = hasSet_Of_Slash[i + colum] = hasSet_Of_BackSlash[colum - i + 7] = true;
                setQueue(colum + 1);
                hasSet_Of_Rows[i] = hasSet_Of_Slash[i + colum] = hasSet_Of_BackSlash[colum - i + 7] = false;
            }
        }
    }
    
    //printf("result: %d\n", result_queue);
}

