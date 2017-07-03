//
//  MemorySet.h
//  Basic Review
//
//  Created by 徐伟达 on 2017/6/18.
//  Copyright © 2017年 徐伟达. All rights reserved.
//

#ifndef MemorySet_h
#define MemorySet_h

#include <stdio.h>
#include <stdlib.h>
#include "Bool.h"
#define GETSTR_MEMSET false

void *mallocPro(void *p, long unsigned size, Bool getStr);
void *callocPro(void *p, long unsigned n, long unsigned size, Bool getStr);
#endif /* MemorySet_h */
