//
//  MemorySet.c
//  Basic Review
//
//  Created by 徐伟达 on 2017/6/18.
//  Copyright © 2017年 徐伟达. All rights reserved.
//

#include "MemorySet.h"


void *mallocPro(void *p, long unsigned size) {
    p = malloc(size);
    if(!p) {
        printf("false\n");
        return NULL;
    }
    printf("true\n");
    return p;
}

void *callocPro(void *p, long unsigned n, long unsigned size) {
    p = calloc(n, size);
    if(!p) {
        printf("false\n");
        return NULL;
    }
    printf("true\n");
    return p;
}
