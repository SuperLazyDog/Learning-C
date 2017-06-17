//
//  MemorySet.c
//  Basic Review
//
//  Created by 徐伟达 on 2017/6/18.
//  Copyright © 2017年 徐伟达. All rights reserved.
//

#include "MemorySet.h"


bool mallocPro(void *p, long unsigned size) {
    p = malloc(size);
    if(!p) {
        printf("false\n");
        return false;
    }
    printf("true\n");
    return true;
}
