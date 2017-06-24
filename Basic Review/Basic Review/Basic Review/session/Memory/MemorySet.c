//
//  MemorySet.c
//  Basic Review
//
//  Created by 徐伟达 on 2017/6/18.
//  Copyright © 2017年 徐伟达. All rights reserved.
//

#include "MemorySet.h"
#include "SampleDataStruct.h"
#include "Hash.h"


void *mallocPro(void *p, long unsigned size, bool getStr) {
    p = NULL;
    p = malloc(size);
    if(getStr) {
        if(!p) {
            printf("malloc failed\n");
            return NULL;
        }
        printf("malloc successfully\n");
        return p;
    }else {
        if(!p) {
            return NULL;
        }
        return p;
    }
}

void *callocPro(void *p, long unsigned n, long unsigned size, bool getStr) {
    p = NULL;
    p = calloc(n, size);
    if(getStr) {
        if(!p) {
            printf("calloc failed\n");
            return NULL;
        }
        printf("calloc successfully\n");
        return p;
    }else {
        if(!p) {
            return NULL;
        }
        return p;
    }
}
