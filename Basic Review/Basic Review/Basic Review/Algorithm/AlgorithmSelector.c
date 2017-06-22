//
//  AlgorithmSelector.c
//  Basic Review
//
//  Created by 徐伟达 on 2017/6/18.
//  Copyright © 2017年 徐伟达. All rights reserved.
//

#include "AlgorithmSelector.h"

//---------------------------------------------------------------------------
//                               选择器
//---------------------------------------------------------------------------
int testCount_algorithm = 0;
void algorithmSelector(int num) {
    testCount_algorithm++;
    puts("******************************************");
    printf("               第%d回测试\n", testCount_algorithm);
    puts("start algorithm test");
    switch (num) {
        case search:
            puts("start search test");
            searchTest();
            break;
        case list:
            puts("start list test");
            listTest();
            break;
        case tree:
            puts("start tree test");
            treeTest();
            break;
        case hash:
            puts("start hash test\n");
            chainHashTest();
            break;
        case sampleDataStruct:
            puts("start data struct test");
            dataStructTest();
            break;
        default:
            puts("nothing matches requirement");
            break;
    }
    puts("\nend algorithm test");
    puts("******************************************\n");
}
