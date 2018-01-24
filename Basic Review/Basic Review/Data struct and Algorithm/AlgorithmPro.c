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
            break;
        case s6:
            break;
        case s7:
            break;
        case s8:
            break;
        default:
            break;
    }
}
