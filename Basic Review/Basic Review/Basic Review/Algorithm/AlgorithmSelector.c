//
//  AlgorithmSelector.c
//  Basic Review
//
//  Created by 徐伟达 on 2017/6/18.
//  Copyright © 2017年 徐伟达. All rights reserved.
//

#include "AlgorithmSelector.h"

void algorithmSelector(int num) {
    switch (num) {
        case search:
            searchTest();
            break;
            
        default:
            puts("nothing matches requirement");
            break;
    }
}
