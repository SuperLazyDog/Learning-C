//
//  AlgorithmPro.c
//  Basic Review
//
//  Created by 徐伟达 on 2017/12/26.
//  Copyright © 2017年 徐伟达. All rights reserved.
//

#include "AlgorithmPro.h"

void AlgorithmProSelector(AlgorithmProItem item) {
    switch (item) {
        case s1:
            break;
        case s2:
			puts("----------------------------------\n");
			puts("             S2 递归\n");
			puts("----------------------------------\n");
			recursionTester();
            break;
        case s3:
			puts("----------------------------------\n");
			puts("             S3 链表\n");
			puts("----------------------------------\n");
            listTester();
            break;
        case s4:
			puts("----------------------------------\n");
			puts("             S4 堆\n");
			puts("----------------------------------\n");
			stackTester();
            break;
        case s5:
			puts("----------------------------------\n");
			puts("             S5 序列\n");
			puts("----------------------------------\n");
			queueTester();
            break;
        case s6:
			puts("----------------------------------\n");
			puts("             S6 树\n");
			puts("----------------------------------\n");
			treeTester();
            break;
        case s7:
			puts("----------------------------------\n");
			puts("             S7 优先队列与堆\n");
			puts("----------------------------------\n");
			heapTester();
            break;
        case s8:
			puts("----------------------------------\n");
			puts("             S8 互素集合\n");
			puts("----------------------------------\n");
			setTester();
            break;
		case s9:
			puts("----------------------------------\n");
			puts("             S9 图论算法\n");
			puts("----------------------------------\n");
			graphTester();
			break;
        default:
            break;
    }
}
