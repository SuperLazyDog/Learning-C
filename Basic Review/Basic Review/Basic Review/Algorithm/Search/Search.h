//
//  Search.h
//  Basic Review
//
//  Created by 徐伟达 on 2017/6/18.
//  Copyright © 2017年 徐伟达. All rights reserved.
//

#ifndef Search_h
#define Search_h

#include <stdio.h>
#include <stdlib.h>
#include "Bool.h"
#include "MemorySet.h"
//---------------------------------------------------------------------------
//                                  探索
//---------------------------------------------------------------------------
//测试
void searchTest();
bool lineSearch(const int p[], const int num, const int key);
bool sentinelSearch(int p[], const int num, const int key);

#endif /* Search_h */
