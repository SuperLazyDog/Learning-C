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
void algorithmSelector(int num) {
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
        default:
            puts("nothing matches requirement");
            break;
    }
    puts("end algorithm test");
}
