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
    switch (num) {
        case search:
            searchTest();
            break;
        case list:
            listTest();
            break;
        default:
            puts("nothing matches requirement");
            break;
    }
}
