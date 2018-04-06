//
//  AlgorithmPro.h
//  Basic Review
//
//  Created by 徐伟达 on 2017/12/26.
//  Copyright © 2017年 徐伟达. All rights reserved.
//
//---------------------------------------------------------------------
//                         学习数据结构与算法
//  书名: 「入門　データ構造とアルゴリズム」
/*  网址: https://www.amazon.co.jp/%E5%85%A5%E9%96%80-%E3%83%87%E3%83%BC%E3%82%BF%E6%A7%8B%E9%80%A0%E3%81%A8%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0-Narasimha-Karumanchi/dp/4873116341/ref=sr_1_3?ie=UTF8&qid=1514262529&sr=8-3&keywords=%E3%83%87%E3%83%BC%E3%82%BF%E6%A7%8B%E9%80%A0%E3%81%A8%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0
*/
//---------------------------------------------------------------------
#ifndef AlgorithmPro_h
#define AlgorithmPro_h

#include <stdio.h>

#include "S2_Recursion.h"
#include "S3_List.h"
#include "S4_Stack.h"
#include "S5_Queue.h"

typedef enum AlgorithmPro {
    s1, s2, s3, s4, s5, s6, s7, s8, s9, s10
} AlgorithmProItem;

void AlgorithmProSelector(AlgorithmProItem item);

#endif /* AlgorithmPro_h */
